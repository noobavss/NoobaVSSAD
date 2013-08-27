#ifndef READERNODE_H
#define READERNODE_H

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <featurenode.h>

class ReaderNode : public FeatureNode
{
public:
    explicit ReaderNode(FeatureNode* parent = 0);
    ReaderNode(QString filename,FeatureNode* parent = 0);
    ~ReaderNode();

    void processEvent(const DetectedEvent event);


private:

    QFile file;
    QTextStream in;
    QString readFile();
};

#endif // READERNODE_H