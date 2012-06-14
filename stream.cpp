#include "stream.h"
#include <QDebug>
#include <QApplication>

#include "ffft/FFTReal.h"


Stream::Stream(QString svID, QString sourceMAC, QObject *parent) : QObject(parent)
{
    this->capturing = true;
    this->alive = true;
    this->checkAlive = false;
    this->analysed = false;
    this->svID = svID;
    this->sourceMAC = sourceMAC;
    this->sampleRate = SampleRate();

    connect(&watcher, SIGNAL(finished()), this, SLOT(handleAnalysisFinished()));
    connect(this, SIGNAL(stopWatcher()), &watcher, SLOT(cancel()));
}

Stream::~Stream()
{
    qDebug() << "destroying Stream";

    //emit removeView();

    //future.cancel();
    //watcher.cancel();

    //future.cancel();
    if (future.isRunning()) {
        future.cancel();
    }

    if (watcher.isRunning()) {
        emit stopWatcher();
    }

    if (timer != NULL && timer->isActive()) {
        //timer->stop();
        //timer->disconnect();
        emit stopTimer();
    }
}

void Stream::addSample(LE_IED_MUnn_PhsMeas1 *dataset, quint16 smpCnt)
{
    if (smpCnt >= 0 && smpCnt < MAX_SAMPLES) {
        checkAlive = true;
        //qDebug() << smpCnt  << capturedSamples << samplesPerSecond;

        if (capturing) {
            samples[smpCnt].smpCount = smpCnt;
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
        }

        // determine sampling rate and nominal frequency
        if (smpCnt == 0 && capturedSamples >= SAMPLES_50HZ_80_PER_CYCLE/* && !sampleRate.isKnown()*/) {

            if (capturedSamples == SAMPLES_50HZ_80_PER_CYCLE) {
                sampleRate.setSampleRate(SampleRate::NominalFreq50Hz, SampleRate::Samples80);
                analysisInstance.setBlockParameters(&measure_P_50Hz_80_samples_per_cycle);
            }
            else if (capturedSamples == SAMPLES_60HZ_80_PER_CYCLE) {
                sampleRate.setSampleRate(SampleRate::NominalFreq60Hz, SampleRate::Samples80);
                analysisInstance.setBlockParameters(&measure_P_60Hz_80_samples_per_cycle);
            }
            else if (capturedSamples == SAMPLES_50HZ_256_PER_CYCLE) {
                sampleRate.setSampleRate(SampleRate::NominalFreq50Hz, SampleRate::Samples256);
                analysisInstance.setBlockParameters(&measure_P_50Hz_256_samples_per_cycle);
            }
            else if (capturedSamples == SAMPLES_60HZ_256_PER_CYCLE) {
                sampleRate.setSampleRate(SampleRate::NominalFreq60Hz, SampleRate::Samples256);
                analysisInstance.setBlockParameters(&measure_P_60Hz_256_samples_per_cycle);
            }

            if (sampleRate.isKnown()) {
                capturing = false;
                capturedSamples = 0;

                if (disabled == false) {
                    //updateStreamTableModel();

                    //emit updateModel(true);
                    /*emit */scheduleAnalysis();  // TODO: do analysis scheduling in StreamManager? Or, set a flag to: block UI updates; wait for all timers to stop, then block them; delete itself later.
                }
            }

            // TODO: detect invalid sample rate values, and count valid packets recv'd?
        }

        if (capturing) {
            if (smpCnt == 0) {
                capturedSamples = 1;
            }
            else {
                capturedSamples++;
            }
        }
    }
}

void Stream::updateStreamTableModel() {
    if (row != NULL && row->isAnalysed()) {
        //qDebug() << "in updateStreamTableModel()";

        row->moveToThread(QApplication::instance()->thread());  // moves the object to UI thread
        emit setStreamTableRow(row);
        //row = NULL;
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

// TODO: put this processing in analysis thread?
QPainterPath *Stream::getPainterPath(QPainterPath *path, PowerSystemQuantity powerSystemQuantity, int phase)
{
    quint32 iterations = sampleRate.getSamplesPerCycle() * NUMBER_OF_CYCLES_TO_ANALYSE;
    qreal Ts = sampleRate.getTimestep();

    for (quint32 t = 0; t < iterations; t++) {
        qreal tMilliseconds = (qreal) t * Ts * 1000.0;

        if (powerSystemQuantity == Stream::Current) {
            if (t == 0) {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 *samples[t].current[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor);
            }
            else {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 *samples[t].current[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor);
            }
        }
        else if (powerSystemQuantity == Stream::Voltage) {
            if (t == 0) {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 *samples[t].voltage[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor);
            }
            else {
                path->setElementPositionAt(t, tMilliseconds, (qreal) -1.0 *samples[t].voltage[phase] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor);
            }
        }

        //qDebug() << (qreal) t * Ts << (qreal) samples[t].current[phase] * 0.01;
    }

    return path;
}

quint32 Stream::getNumberOfSamplesCaptured()
{
    return this->capturedSamples;
}

bool Stream::isAnalysed()
{
    return analysed;
}

bool Stream::isAlive()
{
    return this->alive;
}

void Stream::setAnalysed(bool analysed)
{
    this->analysed = analysed;
}

ExternalOutputs_measure *Stream::getStreamData()
{
    return &analysisInstance.measure_Y;
}

qreal Stream::getMaxInstantaneous(Stream::PowerSystemQuantity powerSystemQuantity)
{
    if (powerSystemQuantity == Stream::Voltage) {
        return maxInstantaneousVoltage;
    }
    else if (powerSystemQuantity == Stream::Current) {
        return maxInstantaneousCurrent;
    }
    return 0.0;
}

SampleRate *Stream::getSampleRate()
{
    return &sampleRate;
}

Sample *Stream::getSampleAt(quint32 i)
{
    if (i >= 0 && i < MAX_SAMPLES) {
        return &(samples[i]);
    }

    return NULL;
}

void Stream::handleAnalysisFinished()
{
    //qDebug() << "done analysis";

    //emit updateModel(false);         //TODO: updates still twitchy, need more granular update?

    if (disabled == false) {
        updateStreamTableModel();

        capturing = true;

//        if (timer == NULL) {
//            timer = new QTimer(this);
//            connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
//            connect(this, SIGNAL(stopTimer()), timer, SLOT(stop()));
//            timer->start(RECALCULATE_ANALYSIS_TIME);
//        }
    }

    //emit updateView();  // TODO: Safe to put this here? Could be race condition?

    //QTimer::singleShot(RECALCULATE_ANALYSIS_TIME, this, SLOT(scheduleAnalysis()));
}

void Stream::scheduleAnalysis() {
    //qDebug() << "in scheduleAnalysis";

    // TODO: better checking of watcher/future state
    if (!watcher.isRunning() && sampleRate.isKnown()) {
        future = QtConcurrent::run(this, &Stream::analyse);     // TODO: can only use this (and timers) if using exec(); explicitly create other thread?
        watcher.setFuture(future);
    }

    // TODO: invalidate samples per cycle info here too?
}

// TODO: restore this timer just for checking if alive.
void Stream::timeout()
{
    //qDebug() << "in timeout";
    if (disabled == false) {
        bool prevAlive = alive;

        if (checkAlive == false) {
            alive = false;
        }
        else {
            alive = true;
            scheduleAnalysis();
        }

        if (alive != prevAlive) {
            //emit updateModel(false);    // TODO: only update appropriate cell?
            updateStreamTableModel();
        }

        checkAlive = false;
    }
    else {
        emit stopTimer();
        emit deleteLater();
    }
}

void Stream::analyse()
{
    //qDebug() << "in analysis";
    //QElapsedTimer timer;
    //timer.start();

    // TODO: must not overwrite samples arrays during this

    setAnalysed(false);
    quint32 iterations = sampleRate.getSamplesPerCycle() * NUMBER_OF_CYCLES_TO_ANALYSE;

    row = new StreamTableRow();

    analysisInstance.initialize();

    maxInstantaneousVoltage = 0.0;
    maxInstantaneousCurrent = 0.0;;

    //TODO: why the need to ignore the first sample?
    for (quint32 t = 1; t < iterations; t++) {
        analysisInstance.measure_U.Vabcpu[0] = samples[t].voltage[0] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_1.Vol.sVC.scaleFactor;
        analysisInstance.measure_U.Vabcpu[1] = samples[t].voltage[1] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_2.Vol.sVC.scaleFactor;
        analysisInstance.measure_U.Vabcpu[2] = samples[t].voltage[2] * LE_IED.S1.MUnn.IEC_61850_9_2LETVTR_3.Vol.sVC.scaleFactor;
        analysisInstance.measure_U.IabcAmps[0] = samples[t].current[0] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_1.Amp.sVC.scaleFactor;
        analysisInstance.measure_U.IabcAmps[1] = samples[t].current[1] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_2.Amp.sVC.scaleFactor;
        analysisInstance.measure_U.IabcAmps[2] = samples[t].current[2] * LE_IED.S1.MUnn.IEC_61850_9_2LETCTR_3.Amp.sVC.scaleFactor;

        qreal timestepMaxVoltage = qMax(qAbs(analysisInstance.measure_U.Vabcpu[0]), qMax(qAbs(analysisInstance.measure_U.Vabcpu[1]), qAbs(analysisInstance.measure_U.Vabcpu[2])));
        if (timestepMaxVoltage > maxInstantaneousVoltage) {
            maxInstantaneousVoltage = timestepMaxVoltage;
        }
        qreal timestepMaxCurrent = qMax(qAbs(analysisInstance.measure_U.IabcAmps[0]), qMax(qAbs(analysisInstance.measure_U.IabcAmps[1]), qAbs(analysisInstance.measure_U.IabcAmps[2])));
        if (timestepMaxCurrent > maxInstantaneousCurrent) {
            maxInstantaneousCurrent = timestepMaxCurrent;
        }

        analysisInstance.step();
    }

    quint32 len = this->sampleRate.getLargestPowerOfTwo();
    qreal inputFrequency = this->sampleRate.getSamplesPerSecond();
    ffft::FFTReal <qreal> fft_object(len);
    qreal x[8][len];
    qreal f[8][len];

    for (int signal = 0; signal < 8; signal++) {
        for (quint32 t = 0; t < len; ++t) {
            x[signal][t] = samples[t].getSampleValue(signal) / maxInstantaneousVoltage;     // TODO: set proper scale
            x[signal][t] = x[signal][t] * 0.5 * (1 - qCos((2 * M_PI * t) / (len - 1)));     // apply Hann Window to sample
        }

        fft_object.do_fft(f[signal], x[signal]);

        for (quint32 i = 2; i <= len / 2; ++i) {
            qreal frequency = qreal(i * inputFrequency) / (len);
            const qreal real = f[signal][i];
            qreal imaginary = 0.0;
            qreal mag = 0.0;

            if (i > 0 && i < len / 2) {
                imaginary = f[signal][len / 2 + i];
            }

            mag = qSqrt(real*real + imaginary*imaginary);

            // TODO: define this cut-off in View, because there will be a grid line here anyway?
            //if (mag >= 0.01) {
                row->appendFreqPoint(signal, log10(frequency), -log10(mag));  // negate the y-coordinate, in preparation for plotting
            //}
        }
    }

    setAnalysed(true);

    // generate row contents and move it to original thread (commsThread)
    row->setup(this);

    //qDebug() << sizeof(row) << sizeof(*row);

    row->moveToThread(this->thread());  // TODO: just move to UI thread here, rather than later?
    //emit setStreamTableRow(row);

    //qDebug() << "The analysis took" << timer.elapsed() << "milliseconds";
}
