#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
//#include "itemwindow.h"


namespace Ui {
class InfoWindow;
}

class InfoWindow : public QWidget
{
    Q_OBJECT

public:
//    InfoWindow(ItemWindow *item);
    InfoWindow(QString, QDate, QTime, int, int);
    ~InfoWindow();
    QWidget* getWidget();


signals:
    void closeButoonInfoPress();
    void seenButtonInfoPress();
    void linkButtonInfoPress();
//    void closeWindowAction();

private slots:

    void on_close_button_info_clicked();

    void on_seen_button_clicked();

    void on_openLink_button_clicked();

private:
    Ui::InfoWindow *ui;
    int unseenNumber;
//    ItemWindow item;
};

#endif // INFOWINDOW_H
