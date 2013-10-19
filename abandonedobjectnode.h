#ifndef ABANDONEDOBJECTNODE_H
#define ABANDONEDOBJECTNODE_H

#include <featurenode.h>
#include <QList>
#include <QStringList>
#include <QHash>
#include <QDebug>

class AbandonedObjectNode : public FeatureNode
{
public:
    explicit AbandonedObjectNode(FeatureNode* parent = 0);
    ~AbandonedObjectNode();

    void processEvents(const QList<DetectedEvent> event);
private:
     QHash<QString,DetectedEvent> speedEvents;
};

#endif // ABANDONEDOBJECTNODE_H
