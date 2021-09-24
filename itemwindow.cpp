#include "itemwindow.h"
#include "ui_itemwindow.h"
#include <QString>
ItemWindow::ItemWindow(QString name, QPixmap photoType,QPixmap photoSpecial,int cEp,int maxEp,QDate nextDate,QTime time) :
    ui(new Ui::ItemWindow)
{
    ui->setupUi(this);

    ui->textBrowser->setText(name);
    QFont serifFont("Times", 30);
    ui->textBrowser->setFont(serifFont);
    ui->textBrowser->setAlignment(Qt::AlignHCenter);

    ui->lcdNumber->display(0);
    ui->lcdNumber->setDigitCount(2);

    ui->label_special_image->setPixmap(photoSpecial.scaled(ui->label_special_image->width(),ui->label_special_image->height(),Qt::IgnoreAspectRatio));
    ui->label_type_image->setPixmap(photoType.scaled(ui->label_type_image->width(),ui->label_type_image->height(),Qt::KeepAspectRatioByExpanding));



    this->cEp = cEp;
    this->maxEp = maxEp;
    this->nextRelease = nextDate;
    this->nextTime = time;
    ui->lcdNumber->display(unseenNumber);
}
//Qt::IgnoreAspectRatio
//Qt::KeepAspectRatio
//Qt::KeepAspectRatioByExpanding
ItemWindow::~ItemWindow()
{
    delete ui;
}

QWidget* ItemWindow::getLayout()
{
    QWidget* layout = ui->widget_item;
    return layout;
}

void ItemWindow::verifyNumber()
{
    while(nextRelease < QDate::currentDate()){
        nextRelease = nextRelease.addDays(7);
        unseenNumber++;
    }
    if(nextRelease == QDate::currentDate())
        if(nextTime <= QTime::currentTime()){
            nextRelease = nextRelease.addDays(7);
            unseenNumber++;
        }
    ui->lcdNumber->display(unseenNumber);
}
