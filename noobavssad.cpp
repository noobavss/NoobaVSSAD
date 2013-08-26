#include "noobavssad.h"

NoobaVSSAD::NoobaVSSAD(QObject *parent) :
    QObject(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(readInputs()));

}

void NoobaVSSAD::launch(){
    timer.start(1000);
}

void NoobaVSSAD::readInputs(){
    qDebug() << "Test";
}
