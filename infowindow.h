#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include "itemwindow.h"


namespace Ui {
class InfoWindow;
}

class InfoWindow : public QWidget
{
    Q_OBJECT

public:
//    InfoWindow(ItemWindow *item);
    InfoWindow(QString nextReleaseDate,QString nextReleaseTime,int unseenNumber);
    ~InfoWindow();
    QWidget* getWidget();


signals:
    void closeButoonPress();
    void deleteButtonPress();

private slots:
    void on_seenButton_clicked();

    void on_closeButtonInfo_clicked();

    void on_deleteButtonInfo_clicked();

private:
    Ui::InfoWindow *ui;
//    ItemWindow item;
};

#endif // INFOWINDOW_H
