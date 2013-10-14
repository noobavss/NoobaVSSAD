#ifndef DISSTANCENODE_H
#define DISSTANCENODE_H


#include <qmath.h>
#include <QList>
#include <QStringList>
#include <featurenode.h>

class DistanceNode : public FeatureNode
{
public:
    explicit DistanceNode(FeatureNode* parent = 0);
    ~DistanceNode();

    void processEvents(const QList<DetectedEvent> event);



};

#endif // DISSTANCENODE_H
