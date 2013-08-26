#ifndef DETECTEDEVENT_H
#define DETECTEDEVENT_H

#include <QObject>
#include <QString>

class DetectedEvent : public QObject
{
    Q_OBJECT
public:
    DetectedEvent();
    DetectedEvent(const DetectedEvent &other);
    ~DetectedEvent();

    DetectedEvent(QString event_id,QString event_msg, float conf,QObject *parent = 0) :
         QObject(parent),event_identifier(event_id),event_message(event_msg),confidence(conf){}

    QString getIdentifier() const { return event_identifier;}
    QString getMessage() const { return event_message;}
    float getConfidence() const { return confidence;}

signals:

public slots:

private:
    QString event_identifier;
    QString event_message;
    float confidence;
}

Q_DECLARE_METATYPE(DetectedEvent);

#endif // DETECTEDEVENT_H
