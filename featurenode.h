#ifndef FEATURENODE_H
#define FEATURENODE_H

#include <QObject>
#include "detectedevent.h"

class FeatureNode : public QObject
{
    Q_OBJECT
public:
    explicit FeatureNode(QObject* parent = 0);

    virtual void processEvent(const DetectedEvent event) = 0;
public slots:
    void captureEvent(DetectedEvent captured_event){ processEvent(captured_event);}

signals:
    void generateEvent(DetectedEvent generated_event);

};


#endif // FEATURENODE_H
