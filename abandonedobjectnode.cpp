#include "abandonedobjectnode.h"

AbandonedObjectNode::AbandonedObjectNode(FeatureNode *parent) :
    FeatureNode(parent)
{
}


AbandonedObjectNode::~AbandonedObjectNode()
{

}

void AbandonedObjectNode::processEvents(const QList<DetectedEvent> event)
{

    

//    foreach( DetectedEvent e, event){
//        qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << e.getIdentifier() << " " << e.getMessage() << " " << e.getConfidence();

//    }

    //This is output event
    QList<DetectedEvent> abandonedObjectEvent;

    //Recieve both speed and relative distance at two calls.
    //This will gather both, and when both are recieced it will process.

    if(!event.isEmpty()){
        QList<QString> id = event.at(0).getIdentifier().split("_");
        if( id.at(0) == "distChange"){

            foreach(DetectedEvent distChangeEvent, event){
                QList<QString> message = distChangeEvent.getMessage().split(",");

                float distChange = message.at(2).toFloat();

                if(distChange <1.0){
                    continue;
                }

                //else, distance is changing, so we are looking weather one blob is not moving
                QList<QString> blobIds = message.at(1).split("-");

                 float speedFirstBlob = 0.0;
                 float speedSecondBlob = 0.0;
                if(speedEvents.contains(blobIds.at(0)) && speedEvents.contains(blobIds.at(1))){
                    DetectedEvent speedEvent = speedEvents.value(blobIds.at(0));
                    speedFirstBlob = speedEvent.getMessage().split(",").at(2).toFloat();

                    speedEvent = speedEvents.value(blobIds.at(1));
                    speedSecondBlob = speedEvent.getMessage().split(",").at(2).toFloat();

                    if(speedFirstBlob <0.01 && speedSecondBlob > 3.0){
                        abandonedObjectEvent.append(DetectedEvent("ABObj",QString("%1,%2,%3,%4,%5,%6").arg(message.at(0)).arg(blobIds.at(0)).arg(blobIds.at(1)).arg(distChange).arg(speedFirstBlob).arg(speedSecondBlob),1.0));
                    }
                    else if(speedFirstBlob > 3.0 && speedSecondBlob <0.01){
                        abandonedObjectEvent.append(DetectedEvent("ABObj",QString("%1,%2,%3,%4,%5,%6").arg(message.at(0)).arg(blobIds.at(1)).arg(blobIds.at(0)).arg(distChange).arg(speedSecondBlob).arg(speedFirstBlob),1.0));
                    }
                }
                //else continue;
            }
        }
        else if(id.at(0) == "speed"){
            //Insert new speed events to the hash map.
            //If already exists the key, this will replace the previous version
            foreach(DetectedEvent e, event){
                QList<QString> message = e.getMessage().split(",");
                speedEvents.insert(message.at(1),e);
            }
        }

        if(!abandonedObjectEvent.isEmpty()){
            emit generateEvent(abandonedObjectEvent);
        }
    }
}
