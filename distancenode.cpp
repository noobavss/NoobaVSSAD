#include "distancenode.h"

DistanceNode::DistanceNode(FeatureNode *parent) :
    FeatureNode(parent)
{
}


DistanceNode::~DistanceNode()
{
}

void DistanceNode::processEvent(const DetectedEvent event)
{
    qDebug() << "---------------" <<event.getIdentifier();
}
