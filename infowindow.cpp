#include <QDate>
#include <QTime>
#include "infowindow.h"
#include "ui_infowindow.h"
//QString name, QDate nextReleaseDate,QTime nextReleaseTime,int unseenNumber, int remainingHours/
InfoWindow::InfoWindow(QString name, QDate nextReleaseDate,QTime nextReleaseTime,int unseenNumber_, int remainingHours):
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    QFont serifFont("Times", 20);
//    item = new ItemWindow();
    ui->nameLabelInfo->setText(name);
    ui->nameLabelInfo->setFont(serifFont);

    ui->nextDateLabelInfo->setText(nextReleaseDate.toString());
    ui->nextDateLabelInfo->setFont(serifFont);
    ui->nextDateLabelInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    ui->nextDateLabelInfo->setFont(serifFont);

    ui->nextHourLaberInfo->setText(nextReleaseTime.toString());
    ui->nextHourLaberInfo->setFont(serifFont);
    ui->nextHourLaberInfo->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    ui->nextHourLaberInfo->setFont(serifFont);

    ui->unseenLCD->display(unseenNumber_);
    ui->unseenLCD->setDigitCount(2);
    ui->unseenLCD->setFont(serifFont);

    ui->remainingHours->setFont(serifFont);

    ui->label->setFont(serifFont);
    ui->label_2->setFont(serifFont);
    ui->label_4->setFont(serifFont);
    ui->label_6->setFont(serifFont);
    this->unseenNumber = unseenNumber_;
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


void InfoWindow::on_close_button_info_clicked()
{
    emit closeButoonInfoPress();
}


void InfoWindow::on_seen_button_clicked()
{
    if(unseenNumber > 0){
        unseenNumber--;
        ui->unseenLCD->display(unseenNumber);
        emit seenButtonInfoPress();
    }
}


void InfoWindow::on_openLink_button_clicked()
{
    emit itemOpenUrl();
}

