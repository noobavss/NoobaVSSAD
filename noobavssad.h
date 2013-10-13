#ifndef NOOBAVSSAD_H
#define NOOBAVSSAD_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <readernode.h>
#include <distancenode.h>

class NoobaVSSAD : public QObject
{
    Q_OBJECT
public:
    explicit NoobaVSSAD(QObject *parent = 0);
    void launch();

signals:

public slots:
    void readInputs();

private:

    QTimer timer;
    QList<DetectedEvent> startingDummy;
    ReaderNode blobPositionReader;
    ReaderNode facePositionReader;
    DistanceNode blobDistanceNode;
};

#endif // NOOBAVSSAD_H
