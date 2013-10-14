#include "delaynode.h"

DelayNode::DelayNode(FeatureNode *parent) :
    FeatureNode(parent),
    delaySteps(1)
{
}

DelayNode::~DelayNode()
{

}

void DelayNode::processEvents(const QList<DetectedEvent> event)
{
    previousEventQueue.enqueue(event);
    if(previousEventQueue.count()>delaySteps){
        emit generateEvent(previousEventQueue.dequeue());
    }
}
