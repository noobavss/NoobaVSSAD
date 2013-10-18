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

    
    //1.
    foreach( DetectedEvent e, event){
        qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << e.getIdentifier() << " " << e.getMessage() << " " << e.getConfidence();

    }


    //Recieve both speed and relative distance at two calls.
    //This will gather both, and when both are recieced it will process.
    /*
    if(event.count() >0){
        QList<QString> id = event.at(0).getIdentifier().split("_");
        if( id.at(0) == "distance"){
            qDebug() << "got distance at AB Obj" << event.at(0).getMessage();
            distanceEvents = event;

            if(!speedEvents.empty() && !distanceEvents.empty()){

                //If the speed events are available at the time we recieve distanceEvents, speedEvents might be older,
                //and may not consist all relevant speeds.
                QList<QString> speedParams = speedEvents.at(0).getMessage().split(",");
                QList<QString> distanceParams = distanceEvents.at(0).getMessage().split(",");

                if(speedParams.at(0) < distanceParams.at(0)){
                    speedEvents.clear();
                }
            }
        }
        else if(event.at(0).getIdentifier() == "speed"){
            qDebug() << "got speed at AB Obj" << event.at(0).getMessage();
            speedEvents = event;
        }
    }
    //If both speed and distance information have been recieved,
    //following will check for abandoned objects.
    //Concept is, if the relative distance between two objects increase with time,
    //and one of objects are not moving, that might be an abandoned object.

    if(!speedEvents.empty() && !distanceEvents.empty()){
        //qDebug() << "Recieved Both";


        for(int i = 0; i < distanceEvents.count(); i++){
            for(int j = 0; j < speedEvents.count(); j++){

                QList<QString> speedParams = speedEvents.at(i).getMessage().split(",");
                QList<QString> distanceParams = distanceEvents.at(j).getMessage().split(",");

                QList<QString> blobs = distanceParams.at(1).split("-");

                qDebug() << distanceParams.at(1);

                //if(speedParams.at(2).toFloat() > 5.0){
                //    break;
                //}

                if(speedParams.at(1) == blobs.at(0)){
                    qDebug() << "First Blob match with less speed";
                }
                if(speedParams.at(1) == blobs.at(1)){
                    qDebug() << "Second Blob match with less speed";
                }
            }
        }

        //After processing, we should erase existing data for next time step
        speedEvents.clear();
        distanceEvents.clear();
    }
    else return;
        */
}
