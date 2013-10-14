#ifndef FILEWRITERNODE_H
#define FILEWRITERNODE_H

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <featurenode.h>

class FileWriterNode : public FeatureNode
{
public:
    explicit FileWriterNode(FeatureNode* parent = 0);
    FileWriterNode(QString filename,FeatureNode* parent = 0);
    ~FileWriterNode();

    void processEvents(const QList<DetectedEvent> event);
private:
    QFile file;
    QTextStream out_stream;
};

#endif // FILEWRITERNODE_H
