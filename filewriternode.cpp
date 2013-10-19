#include "filewriternode.h"

FileWriterNode::FileWriterNode(FeatureNode *parent) :
    FeatureNode(parent),
    file("/home/chathuranga/Programming/FYP/data/text/2013-10-13-blob-distances.txt")
{
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    out_stream.setDevice(&file);
}

FileWriterNode::FileWriterNode(QString filename,FeatureNode* parent):
    FeatureNode(parent),
    file(filename)
{
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Cannot create/open file named " << filename << "! Abort.";
        return;
    }
    out_stream.setDevice(&file);
}

FileWriterNode::~FileWriterNode()
{
    file.close();
}

void FileWriterNode::processEvents(const QList<DetectedEvent> event)
{
    foreach(DetectedEvent e, event){
        qDebug() << "===================================" << e.getIdentifier() << " " << e.getMessage() << " " << e.getConfidence();
        out_stream << e.getIdentifier() << "," << e.getMessage() << "\n";
        out_stream.flush();
    }
}
