#include "rftoolz.h"
#include <qt_windows.h>
#include <QProcessEnvironment>
#include <QDebug>

RFToolz::RFToolz(QObject *parent) :
    QObject(parent)
{
}

void RFToolz::onKeysChanged(QString keyG, QString keyI)
{
    keyType = keyG.mid(9, 2);

    keyG.remove(8, 4);
    for (int i = 0; i < keyGSize; ++i)
        kG[i] = QString(keyG.at(i)).toUInt();

    keyI.remove(7, 4);
    for (int i = 0; i < keyISize; ++i)
        kI[i] = QString(keyI.at(i)).toUInt();

    qDebug() << "aaa";
}

quint32 RFToolz::getActivationKey() {
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString sysDrv = env.value(QString("SystemDrive")) + "\\";

    DWORD lpVolumeSerialNumber;
    bool ret = GetVolumeInformation ((LPCWSTR)sysDrv.utf16(), NULL, NULL,
                                     &lpVolumeSerialNumber, NULL, NULL, NULL, NULL);
    if (!ret) return -1;

    quint32 serial = 538689220; // (quint32)lpVolumeSerialNumber;

    quint32 sum = 0;
    for (int i = 0; i < keyGSize; ++i)
        sum += kG[i];
    serial *= sum;

    sum = 0;
    for (int i = 0; i < keyISize; ++i)
        sum += kI[i];
    serial *= sum;

    if (keyType == "R6") {
        serial *= 0x0003F455;
        serial %= 0x00F20BD3;
    } else if (keyType == "G5") {
        serial *= 0x0003FE02;
        serial %= 0x00BBA3C1;
    } else {
        serial = 0;
    }

    return serial;
}

quint32 RFToolz::onReloadActivationKey()
{
    quint32 serial = getActivationKey();

    return serial;
}
