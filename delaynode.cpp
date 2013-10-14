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
    QList<DetectedEvent> delayedEvent;
    QList<DetectedEvent> newDelayedEvent;

    previousEventQueue.enqueue(event);
    if(previousEventQueue.count()>delaySteps){
        delayedEvent = previousEventQueue.dequeue();

        for(int i = 0; i < delayedEvent.count(); i++){
            DetectedEvent newEvent(QString("delayed_%1_%2").arg(delaySteps).arg(delayedEvent.at(i).getIdentifier()),QString("delayed_%1_%2").arg(delaySteps).arg(delayedEvent.at(i).getIdentifier()),1.0);
            newDelayedEvent.append(newEvent);
        }
        emit generateEvent(newDelayedEvent);
    }
}
