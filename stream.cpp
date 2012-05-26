#include "stream.h"
#include <QDebug>


Stream::Stream(QString svID, QString sourceMAC, QObject *parent) : QObject(parent)
{
    this->analysed = false;
    this->svID = svID;
    this->sourceMAC = sourceMAC;
    this->sampleRate = RateUnknown;
    //this->capturedSamples = 1;

    connect(&watcher, SIGNAL(finished()), this, SLOT(handleAnalysisFinished()));
}

Stream::~Stream()
{
    future.cancel();
    watcher.cancel();
}

void Stream::addSample(LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
{
    if (smpCnt >= 0 && smpCnt < MAX_SAMPLES) {
        //qDebug() << smpCnt  << capturedSamples << samplesPerSecond;

        samples[smpCnt].voltage[0] = dataset->MUnn_TVTR_1_Vol_instMag.i;
        samples[smpCnt].voltageQuality[0] = dataset->MUnn_TVTR_1_Vol_q;
        samples[smpCnt].voltage[1] = dataset->MUnn_TVTR_2_Vol_instMag.i;
        samples[smpCnt].voltageQuality[1] = dataset->MUnn_TVTR_2_Vol_q;
        samples[smpCnt].voltage[2] = dataset->MUnn_TVTR_3_Vol_instMag.i;
        samples[smpCnt].voltageQuality[2] = dataset->MUnn_TVTR_3_Vol_q;
        samples[smpCnt].voltage[3] = dataset->MUnn_TVTR_4_Vol_instMag.i;
        samples[smpCnt].voltageQuality[3] = dataset->MUnn_TVTR_4_Vol_q;

        samples[smpCnt].current[0] = dataset->MUnn_TCTR_1_Amp_instMag.i;
        samples[smpCnt].currentQuality[0] = dataset->MUnn_TCTR_1_Amp_q;
        samples[smpCnt].current[1] = dataset->MUnn_TCTR_2_Amp_instMag.i;
        samples[smpCnt].currentQuality[1] = dataset->MUnn_TCTR_2_Amp_q;
        samples[smpCnt].current[2] = dataset->MUnn_TCTR_3_Amp_instMag.i;
        samples[smpCnt].currentQuality[2] = dataset->MUnn_TCTR_3_Amp_q;
        samples[smpCnt].current[3] = dataset->MUnn_TCTR_4_Amp_instMag.i;
        samples[smpCnt].currentQuality[3] = dataset->MUnn_TCTR_4_Amp_q;

        // determine sampling rate and nominal frequency
        if (smpCnt == 0 && this->sampleRate == RateUnknown) {
            if (capturedSamples == SAMPLES_50HZ_80_PER_CYCLE) {
                sampleRate = Rate80samples50Hz;
                //analysisInstance.setBlockParameters(&measure_P_50Hz_80_samples_per_cycle);    // TODO: probably returning NaN,etc. Rebuild with latest Coder, with non-finite
            }
            else if (capturedSamples == SAMPLES_60HZ_80_PER_CYCLE) {
                sampleRate = Rate80samples60Hz;
                //analysisInstance.setBlockParameters(&measure_P_60Hz_80_samples_per_cycle);
            }
            else if (capturedSamples == SAMPLES_50HZ_256_PER_CYCLE) {
                sampleRate = Rate256samples50Hz;
                //analysisInstance.setBlockParameters(&measure_P_50Hz_256_samples_per_cycle);
            }
            else if (capturedSamples == SAMPLES_60HZ_256_PER_CYCLE) {
                sampleRate = Rate256samples60Hz;
                //analysisInstance.setBlockParameters(&measure_P_60Hz_256_samples_per_cycle);
            }

            if (sampleRate != RateUnknown) {
                samplesPerSecond = capturedSamples;

                emit updateModel(true);
                emit scheduleAnalysis();
            }

            // TODO: find invalid sample rate values, and count valid packets recv'd?
        }

        if (smpCnt == 0) {
            capturedSamples = 1;
        }
        else {
            capturedSamples++;
        }
    }
}

QString Stream::getSvID()
{
    return this->svID;
}

QString Stream::getSourceMAC()
{
    return this->sourceMAC;
}

QString Stream::getFreq()
{
    if (analysed) {
        return QString("%1 Hz").arg(analysisInstance.measure_Y.Frequency);
    }
    else {
        return QString("--");
    }
}

QString Stream::getVoltage()
{
    if (analysed) {
        return QString("%1 kV").arg(sqrt(3) * (analysisInstance.measure_Y.Voltage[0] + analysisInstance.measure_Y.Voltage[1] + analysisInstance.measure_Y.Voltage[2]) / 3000.0);
    }
    else {
        return QString("--");
    }
}

QString Stream::getCurrent()
{
    if (analysed) {
        return QString("%1 kA").arg(sqrt(3) * (analysisInstance.measure_Y.Current[0] + analysisInstance.measure_Y.Current[1] + analysisInstance.measure_Y.Current[2]) / 3000.0);
    }
    else {
        return QString("--");
    }
}

QString Stream::getSamplesPerCycle()
{
    if (this->sampleRate == Rate80samples50Hz || this->sampleRate == Rate80samples60Hz) {
        return QString("80");
    }
    else if (this->sampleRate == Rate256samples50Hz || this->sampleRate == Rate256samples60Hz) {
        return QString("256");
    }
    else if (this->sampleRate == RateInvalid) {
        return QString("invalid");
    }
    else {
        return QString("--");
    }
}

quint32 Stream::getNumberOfSamplesCaptured()
{
    return this->capturedSamples;
}

bool Stream::isAnalysed()
{
    return analysed;
}

void Stream::setAnalysed(bool analysed)
{
    this->analysed = analysed;
}

ExternalOutputs_measure *Stream::getStreamData()
{
    return &analysisInstance.measure_Y;
}

void Stream::handleAnalysisFinished()
{
    //qDebug() << "done analysis";
    emit updateModel(true);         //TODO: updates still twitchy

    QTimer::singleShot(RECALCULATE_ANALYSIS_TIME, this, SLOT(scheduleAnalysis()));
}

void Stream::scheduleAnalysis() {
    //qDebug() << "in timer";

    // TODO: better checking of watcher/future state
    if (/*!isAnalysed() &&*/!watcher.isRunning() &&/*&future == NULL &&*/ sampleRate != RateUnknown) {
        future = QtConcurrent::run(this, &Stream::analyse);
        watcher.setFuture(future);
    }

    // TODO: invalidate samples per cycle info here too?
}

void Stream::analyse()
{
    //qDebug() << "in analysis";

    //QElapsedTimer timer;
    //timer.start();

    setAnalysed(false);

    analysisInstance.initialize();

    for (quint32 t = 0; t < samplesPerSecond; t++) {
        analysisInstance.measure_U.Vabcpu[0] = samples[t].voltage[0] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor;
        analysisInstance.measure_U.Vabcpu[1] = samples[t].voltage[1] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_2.Vol.sVC.scaleFactor;
        analysisInstance.measure_U.Vabcpu[2] = samples[t].voltage[2] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_3.Vol.sVC.scaleFactor;
        analysisInstance.measure_U.IabcAmps[0] = samples[t].current[0] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor;
        analysisInstance.measure_U.IabcAmps[1] = samples[t].current[1] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_2.Amp.sVC.scaleFactor;
        analysisInstance.measure_U.IabcAmps[2] = samples[t].current[2] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_3.Amp.sVC.scaleFactor;

        analysisInstance.step();
    }

    setAnalysed(true);

    //qDebug() << "The analysis took" << timer.elapsed() << "milliseconds";
}
