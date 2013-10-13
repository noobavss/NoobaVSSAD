#include "distancenode.h"
#include <QFile>
#include <QTextStream>
DistanceNode::DistanceNode(FeatureNode *parent) :
    FeatureNode(parent),
    file("/home/chathuranga/Programming/FYP/data/text/2013-10-13-blob-distances.txt")
{
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

}


DistanceNode::~DistanceNode()
{
    file.close();
}

void DistanceNode::processEvents(const QList<DetectedEvent> event)
{
    if(event.count() < 2){
        return;
    }
    QList<DetectedEvent> distanceEvent;
    for(int i = 0; i < event.count(); i++){
        for(int j = i+1; j < event.count(); j++){

            QList<QString> params1 = event.at(i).getMessage().split(",");
            QList<QString> params2 = event.at(j).getMessage().split(",");
            float distX = params1.at(2).toFloat() - params2.at(2).toFloat();
            float distY = params1.at(3).toFloat() - params2.at(3).toFloat();

            float distance = qSqrt(distX* distX + distY * distY);
            distanceEvent.append(DetectedEvent("distance",QString("%1,%2-%3,%4").arg(params1.at(0)).arg(params1.at(1)).arg(params2.at(1)).arg(distance),1.0));
        }
    }


    QTextStream out_stream(&file);
    foreach(DetectedEvent e, distanceEvent){
        qDebug() << "===================================" << e.getIdentifier() << " " << e.getMessage() << " " << e.getConfidence();
        out_stream << e.getIdentifier() << "," << e.getMessage() << "\n";
    }

    //emit generateEvent(distanceEvent);
}
