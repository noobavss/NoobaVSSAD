#ifndef DISSTANCENODE_H
#define DISSTANCENODE_H

#include <QFile>
#include <QDebug>
#include <QList>
#include <qmath.h>
#include <QStringList>
#include <featurenode.h>

class DistanceNode : public FeatureNode
{
public:
    explicit DistanceNode(FeatureNode* parent = 0);
    ~DistanceNode();

    void processEvents(const QList<DetectedEvent> event);

private:
    QFile file;

};

#endif // DISSTANCENODE_H
