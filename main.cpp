#include <QtGui/QApplication>
#include "widget.h"
#include "rftoolz.h"

enum rfTypes {
    G5,
    G6,
    I3,
    E1,
    E2,
    E3,
    E4,
    E5,
    E6,
    E7,
    E8,
    A1,
    H1
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    RFToolz t;

    QObject::connect(&w, SIGNAL(keysChanged(QString,QString)),
                     &t, SLOT(onKeysChanged(QString,QString)));
    QObject::connect(&w, SIGNAL(reloadActivationKey()),
                     &t, SLOT(onReloadActivationKey()));

    w.show();
    
    return a.exec();
}
