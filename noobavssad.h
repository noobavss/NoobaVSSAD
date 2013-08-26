#ifndef NOOBAVSSAD_H
#define NOOBAVSSAD_H

#include <QObject>
#include <QTimer>

class NoobaVSSAD : public QObject
{
    Q_OBJECT
public:
    explicit NoobaVSSAD(QObject *parent = 0);

signals:

public slots:

private:

    QTimer timer;


};

#endif // NOOBAVSSAD_H
