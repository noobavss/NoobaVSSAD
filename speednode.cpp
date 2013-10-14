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
    if(event.count() >0){
        if(event.at(0).getIdentifier() == "distance"){
            qDebug() << "got dist " << event.at(0).getMessage();
        }
        else{
            QList<QString> id = event.at(0).getIdentifier().split("_");
            if( id.at(0) == "delayed"){
                qDebug() << "got delayed dist " << event.at(0).getMessage();
            }
        }
    }
}
