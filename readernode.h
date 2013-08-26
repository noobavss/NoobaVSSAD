#ifndef READERNODE_H
#define READERNODE_H

#include <QDebug>
#include <featurenode.h>

class ReaderNode : public FeatureNode
{
public:
    explicit ReaderNode(FeatureNode* parent = 0);

    void processEvent(const DetectedEvent event);

private:
    void readFile();
};

#endif // READERNODE_H
