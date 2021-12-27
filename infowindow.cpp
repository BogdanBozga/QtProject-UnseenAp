#include "infowindow.h"
#include "ui_infowindow.h"

//InfoWindow::InfoWindow(ItemWindow *nitem) :
//    ui(new Ui::InfoWindow)
//{
//    ui->setupUi(this);
//    this->item = nitem;

//    QFont serifFont("Times", 25);

//    ui->nextDateLabelInfo->setText(item->getNextRelease().toString());
//    ui->nextDateLabelInfo->setFont(serifFont);
//    ui->nextDateLabelInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);


//    ui->nextHourLaberInfo->setText(item->getNextTime().toString());
//    ui->nextHourLaberInfo->setFont(serifFont);
//    ui->nextHourLaberInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);


//    ui->unseenLCD->display(item->getUnseenNumber());
//    ui->unseenLCD->setDigitCount(2);
//}

InfoWindow::InfoWindow(QString nextReleaseDate,QString nextReleaseTime,int unseenNumber):
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    QFont serifFont("Times", 25);
//    item = new ItemWindow();
    ui->nextDateLabelInfo->setText(nextReleaseDate);
    ui->nextDateLabelInfo->setFont(serifFont);
    ui->nextDateLabelInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);


    ui->nextHourLaberInfo->setText(nextReleaseTime);
    ui->nextHourLaberInfo->setFont(serifFont);
    ui->nextHourLaberInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);


    ui->unseenLCD->display(unseenNumber);
    ui->unseenLCD->setDigitCount(2);
}

QWidget* InfoWindow::getWidget()
{
    QWidget *widget= ui->big_widget;
    return widget;
}


InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::on_seenButton_clicked()
{
//    item->setUnseenNumber(item->getUnseenNumber()-1);
//    ui->unseenLCD->display(item->getUnseenNumber());
//    update();
}


void InfoWindow::on_closeButtonInfo_clicked()
{

}


void InfoWindow::on_deleteButtonInfo_clicked()
{

}

