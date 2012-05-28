#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_toolButtonReloadActivationKey_clicked();

private:
    Ui::Widget *ui;

signals:
    void keysChanged(QString keyG, QString keyI);
    quint32 reloadActivationKey();
};

#endif // WIDGET_H
