#include "noobavssad.h"

NoobaVSSAD::NoobaVSSAD(QObject *parent) :
    QObject(parent),
    facePositionReader("G:/FYP/FYP/results/data/pets2006-test3-blobs.txt"),
    blobPositionReader("G:/FYP/FYP/results/data/pets2006-test3-blobs-staticbgsubs.txt"),
    startingDummy("0-TrackPosition","10,12",1.0)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(readInputs()));
    connect(&blobPositionReader, SIGNAL(generateEvent(DetectedEvent)), &blobDistanceNode, SLOT(captureEvent(DetectedEvent)));
}

void NoobaVSSAD::launch(){
    timer.start(100);
}

void NoobaVSSAD::readInputs(){
    blobPositionReader.processEvent(startingDummy);
    facePositionReader.processEvent(startingDummy);
}
