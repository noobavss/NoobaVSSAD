#include <QtCore/QCoreApplication>
#include <QDebug>
#include <readernode.h>
#include <noobavssad.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NoobaVSSAD application;

    application.launch();

    ReaderNode reader,receiver;

    QObject::connect(&reader,SIGNAL(generateEvent(DetectedEvent)),&receiver,SLOT(captureEvent(DetectedEvent)));

    const DetectedEvent event("1-Position","10,12",1.0);

    qDebug() << event.getIdentifier() << "\n";
    qDebug() << event.getMessage() << "\n";
    qDebug() << event.getConfidence() << "\n";


    reader.processEvent(event);


    return a.exec();
}
