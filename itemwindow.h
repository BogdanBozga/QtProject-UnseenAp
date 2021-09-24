#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QWidget>
#include <QDate>
#include <QTime>

namespace Ui {
class ItemWindow;
}

class ItemWindow : public QWidget
{
    Q_OBJECT

public:
     ItemWindow(QString name, QPixmap photoType,QPixmap photoSpecial,int cEp,int maxEp,QDate nextRelease,QTime time);
    ~ItemWindow();
    QWidget* getLayout();
    void verifyNumber();

private:
    int cEp= 0;
    int maxEp = 0;
    int unseenNumber = 0;
    QDate nextRelease;
    QTime nextTime;
    Ui::ItemWindow *ui;

};

#endif // ITEMWINDOW_H
