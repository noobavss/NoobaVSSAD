#include "speednode.h"

SpeedNode::SpeedNode(FeatureNode *parent) :
    FeatureNode(parent)
{
}

SpeedNode::~SpeedNode()
{

}

void SpeedNode::processEvents(const QList<DetectedEvent> event)
{

    //Recieve both current and previous blob positions at two calls.
    //This will gather both, and when both are recieced it will process.

    if(event.count() >0){
        if(event.at(0).getIdentifier() == "blob"){
            qDebug() << "got blobs" << event.at(0).getMessage();
            currentBlobEvents = event;
        }
        else{
            QList<QString> id = event.at(0).getIdentifier().split("_");
            if( id.at(0) == "delayed"){
                qDebug() << "got delayed blobs" << event.at(0).getMessage();
                previousBlobEvents = event;
            }
        }
    }

    //If both previous and current information have been recieved,
    //following will calculate speed and emit speed event.
    if(!currentBlobEvents.empty() && !previousBlobEvents.empty()){
        //qDebug() << "Recieved Both";

        QList<DetectedEvent> speedEvent;

        for(int i = 0; i < currentBlobEvents.count(); i++){
            for(int j = 0; j < previousBlobEvents.count(); j++){

                QList<QString> currentParams = currentBlobEvents.at(i).getMessage().split(",");
                QList<QString> delayedParams = previousBlobEvents.at(j).getMessage().split(",");

                //"426,11,330.554,200.367"
                if(currentParams.at(1) == delayedParams.at(1)){
                    float distX = currentParams.at(2).toFloat() - delayedParams.at(2).toFloat();
                    float distY = currentParams.at(3).toFloat() - delayedParams.at(3).toFloat();

                    float distance = qSqrt(distX* distX + distY * distY);

                    speedEvent.append(DetectedEvent("speed",QString("%1,%2,%3").arg(currentParams.at(0)).arg(currentParams.at(1)).arg(distance),1.0));
                }
            }
        }

        if(!speedEvent.empty()){
            emit generateEvent(speedEvent);
        }

        //After processing, we should erase existing data for next time step
        currentBlobEvents.clear();
        previousBlobEvents.clear();

    }
    else return;
}
