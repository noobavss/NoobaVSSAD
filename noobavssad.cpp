#include "noobavssad.h"

NoobaVSSAD::NoobaVSSAD(QObject *parent) :
    QObject(parent),
    fileReader("G:/FYP/FYP/results/S1-T1-C-3-track.txt"),
    startingDummy("0-TrackPosition","10,12",1.0)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(readInputs()));

}

void NoobaVSSAD::launch(){
    timer.start(1000);
}

void NoobaVSSAD::readInputs(){
    fileReader.processEvent(startingDummy);
}
