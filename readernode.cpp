#include "readernode.h"

ReaderNode::ReaderNode(FeatureNode* parent):
    FeatureNode(parent)
{
}

void ReaderNode::processEvent(const DetectedEvent event)
{
    qDebug() << event.getIdentifier() << " " << event.getMessage() << " " << event.getConfidence();
    emit generateEvent(event);
}

void ReaderNode::readFile(){

}
