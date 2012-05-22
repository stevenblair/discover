#include "stream.h"

Stream::Stream(QObject *parent) : QObject(parent)
{
    this->analysed = false;
}

void Stream::addSample()
{
}
