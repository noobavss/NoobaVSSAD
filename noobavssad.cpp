#include "noobavssad.h"

NoobaVSSAD::NoobaVSSAD(QObject *parent) :
    QObject(parent),
    blobPositionReader("/home/chathuranga/Programming/FYP/data/text/2013-10-13-blob_centroids.txt"),
    facePositionReader("/home/chathuranga/Programming/FYP/data/text/pets2006-test3-blobs.txt"),
    blobDistanceWriterNode("/home/chathuranga/Programming/FYP/data/text/2013-10-14-blob-distances.txt"),
    startingDummy()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(readInputs()));
    connect(&blobPositionReader, SIGNAL(generateEvent(QList<DetectedEvent>)), &blobDistanceNode, SLOT(captureEvent(QList<DetectedEvent>)));
    connect(&blobPositionReader, SIGNAL(generateEvent(QList<DetectedEvent>)), &blobPositionDelayedNode, SLOT(captureEvent(QList<DetectedEvent>)));
    connect(&blobDistanceNode, SIGNAL(generateEvent(QList<DetectedEvent>)), &blobDistanceWriterNode, SLOT(captureEvent(QList<DetectedEvent>)));
}

void NoobaVSSAD::launch(){
    timer.start(1);
}

void NoobaVSSAD::readInputs(){
    blobPositionReader.processEvents(startingDummy);
    facePositionReader.processEvents(startingDummy);
}
