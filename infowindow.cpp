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
//    ui->nextHourLaberInfo->setFont(serifFont);getWidget
//    ui->nextHourLaberInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);


//    ui->unseenLCD->display(item->getUnseenNumber());
//    ui->unseenLCD->setDigitCount(2);
//}

InfoWindow::InfoWindow(QString name, QDate nextReleaseDate,QTime nextReleaseTime,int unseenNumber):
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    QFont serifFont("Times", 25);
//    item = new ItemWindow();
    ui->nameLabelInfo->setText(name);
    ui->nextDateLabelInfo->setText(nextReleaseDate.toString());
    ui->nextDateLabelInfo->setFont(serifFont);
    ui->nextDateLabelInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);


    ui->nextHourLaberInfo->setText(nextReleaseTime.toString());
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

//void InfoWindow::on_seenButton_clicked()
//{
//    item->setUnseenNumber(item->getUnseenNumber()-1);
//    ui->unseenLCD->display(item->getUnseenNumber());
//    update();
//}


void InfoWindow::on_close_button_info_clicked()
{
    qWarning() << " note here";
}


void InfoWindow::on_seen_button_clicked()
{

}

