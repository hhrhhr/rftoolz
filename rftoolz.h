#ifndef RFTOOLZ_H
#define RFTOOLZ_H

#include <QObject>

const int keyGSize = 18;
const int keyISize = 13;

class RFToolz : public QObject
{
    Q_OBJECT

    quint8 kG[keyGSize];
    quint8 kI[keyISize];
    QString keyType;     // key type

    quint32 getActivationKey();

public:
    explicit RFToolz(QObject *parent = 0);
    
signals:
    
public slots:
    void onKeysChanged(QString keyG, QString keyI);
    quint32 onReloadActivationKey();
};

#endif // RFTOOLZ_H
