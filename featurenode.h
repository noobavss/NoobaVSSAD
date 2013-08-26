#ifndef FEATURENODE_H
#define FEATURENODE_H

#include <QObject>
#include "detectedevent.h"

class FeatureNode : public QObject
{
    Q_OBJECT
public:
    FeatureNode(QObject* parent = 0);

    void insertEvent(const DetectedEvent event);
public slots:
    void captureEvent(DetectedEvent captured_event){ insertEvent(captured_event);}

signals:
    void generateEvent(DetectedEvent generated_event);

};


#endif // FEATURENODE_H
