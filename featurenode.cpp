#include "featurenode.h"
#include <QDebug>

FeatureNode::FeatureNode(QObject *parent) :
    QObject(parent)
{
}

void FeatureNode::insertEvent(const DetectedEvent event)
{
    qDebug() << event.getIdentifier() << " " << event.getMessage() << " " << event.getConfidence();
    emit generateEvent(event);
}
