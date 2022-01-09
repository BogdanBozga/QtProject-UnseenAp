#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QWidget>
#include <QDate>
#include <QPushButton>
#include <QTime>
#include "infowindow.h"

namespace Ui {
class ItemWindow;
}

class ItemWindow : public QWidget
{
    Q_OBJECT

public:
     ItemWindow(QString name, QString typePhotoName, QString specialPhotoName, int cEp,int maxEp,QDate nextRelease,QTime time,int nrUnseeEps=0);
    ~ItemWindow();
     ItemWindow(ItemWindow &citem);
     ItemWindow();


    QWidget* getLayout();
    void verifyNumber();

    QPushButton *deleteButton;

    int getCEp() const;
    void setCEp(int newCEp);
    int getMaxEp() const;
    void setMaxEp(int newMaxEp);
    int getUnseenNumber() const;
    void setUnseenNumber(int newUnseenNumber);
    const QDate &getNextRelease() const;
    void setNextRelease(const QDate &newNextRelease);
    const QTime &getNextTime() const;
    void setNextTime(const QTime &newNextTime);
    const QString getName() const;
    void setName(const QString &newName);

    const QString &getTypePhotoName() const;
    const QString &getSpecialPhotoName() const;
    Ui::ItemWindow *ui;

signals:
    void deleteAction(QString name);
    void suplimentarInfoAction(QString name);

//public slots:
//    void on_DeleteItem_released();
//    void on_SuplimentarInfo_clicked();

private slots:
    void on_DeleteItem_released();

    void on_SuplimentarInfo_clicked();

private:
    int cEp= 0;
    int maxEp = 0;
    int unseenNumber = 0;
    QDate nextRelease;
    QTime nextTime;

    QString name;
    QString typePhotoName;
    QString specialPhotoName;

};

#endif // ITEMWINDOW_H
