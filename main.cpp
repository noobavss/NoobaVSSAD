#include <QtCore/QCoreApplication>
#include <QDebug>
#include <readernode.h>
#include <noobavssad.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NoobaVSSAD application;

    application.launch();

    return a.exec();
}
