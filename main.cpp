#include <QtCore/QCoreApplication>
#include <featurenode.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    FeatureNode reader,receiver;

    QObject::connect(&reader,SIGNAL(generateEvent(DetectedEvent)),&receiver,SLOT(captureEvent(DetectedEvent)));

    const DetectedEvent event("1-Position","10,12",1.0);

    qDebug() << event.getIdentifier() << "\n";
    qDebug() << event.getMessage() << "\n";
    qDebug() << event.getConfidence() << "\n";


    reader.insertEvent(event);


    return a.exec();
}
