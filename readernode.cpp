#include "readernode.h"

ReaderNode::ReaderNode(FeatureNode* parent):
    FeatureNode(parent),
    file("c:/in.txt")
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    in.setDevice(&file);

}

ReaderNode::ReaderNode(QString filename,FeatureNode* parent):
    FeatureNode(parent),
    file(filename)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    in.setDevice(&file);

}

ReaderNode::~ReaderNode(){
    file.close();
}

void ReaderNode::processEvent(const DetectedEvent event)
{
    //qDebug() << event.getIdentifier() << " " << event.getMessage() << " " << event.getConfidence();
    QString eventmessage = readFile();

    if(eventmessage == ""){
        return;
    }

    QStringList event_strings = eventmessage.split("|");


    if(event_strings.count() != 0){

        for(int i = 0; i < event_strings.count(); i++){
            if(event_strings.at(i) == ""){
                continue;
            }
//            QStringList parameters =  event_strings.at(i).split(",");

//            bool ok;

//            int frame = parameters.at(0).toInt(&ok);
//            int tag = parameters.at(1).toInt(&ok);
//            int x_position = parameters.at(2).toInt(&ok);
//            int y_position = parameters.at(3).toInt(&ok);
//            if(!ok) return;

//            qDebug() << frame << " " << tag << " " << x_position << " " << y_position;
            qDebug() << "blob " << i << " " << event_strings.at(i);
            DetectedEvent newEvent("blob",event_strings.at(i),1.0);
            emit generateEvent(newEvent);
        }
    }


}

QString ReaderNode::readFile(){

     if(!in.atEnd()) {
         QString line = in.readLine();
         return line;
     }
     else{
         return "\n";
     }
}