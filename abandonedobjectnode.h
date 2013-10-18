#ifndef ABANDONEDOBJECTNODE_H
#define ABANDONEDOBJECTNODE_H

#include <featurenode.h>
#include <QList>
#include <QStringList>
#include <QDebug>

class AbandonedObjectNode : public FeatureNode
{
public:
    explicit AbandonedObjectNode(FeatureNode* parent = 0);
    ~AbandonedObjectNode();

    void processEvents(const QList<DetectedEvent> event);
private:
    QList<DetectedEvent> speedEvents;
    QList<DetectedEvent> distanceEvents;
};

#endif // ABANDONEDOBJECTNODE_H
