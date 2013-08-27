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

    QStringList parameters = eventmessage.split(",");
    bool ok;

    int frame = parameters.at(0).toInt(&ok);
    int tag = parameters.at(1).toInt(&ok);
    int x_position = parameters.at(2).toInt(&ok);
    int y_position = parameters.at(3).toInt(&ok);
    if(!ok) return;

    qDebug() << frame << " " << tag << " " << x_position << " " << y_position;

    //emit generateEvent(event);
}

QString ReaderNode::readFile(){

     if(!in.atEnd()) {
         QString line = in.readLine();
         return line;
     }
     else{
         return ",,,";
     }
}
