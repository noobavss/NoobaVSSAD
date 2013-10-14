#ifndef SPEEDNODE_H
#define SPEEDNODE_H

#include <QList>
#include <QStringList>
#include <QDebug>
#include <featurenode.h>

class SpeedNode : public FeatureNode
{
public:
    explicit SpeedNode(FeatureNode* parent = 0);
    ~SpeedNode();

    void processEvents(const QList<DetectedEvent> event);

};

#endif // SPEEDNODE_H
