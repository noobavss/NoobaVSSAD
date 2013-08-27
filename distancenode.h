#ifndef DISSTANCENODE_H
#define DISSTANCENODE_H

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <featurenode.h>

class DistanceNode : public FeatureNode
{
public:
    explicit DistanceNode(FeatureNode* parent = 0);
    ~DistanceNode();

    void processEvent(const DetectedEvent event);

};

#endif // DISSTANCENODE_H
