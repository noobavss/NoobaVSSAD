#include "noobavssad.h"

NoobaVSSAD::NoobaVSSAD(QObject *parent) :
    QObject(parent),
    blobPositionReader("G:/FYP/FYP/results/data/pets2006-test3-blobs.txt"),
    facePositionReader("G:/FYP/FYP/results/data/pets2006-test3-blobs-staticbgsubs.txt"),
    startingDummy("0-TrackPosition","10,12",1.0)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(readInputs()));
}

void NoobaVSSAD::launch(){
    timer.start(200);
}

void NoobaVSSAD::readInputs(){
    blobPositionReader.processEvent(startingDummy);
    facePositionReader.processEvent(startingDummy);
}
