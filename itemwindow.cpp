#include "itemwindow.h"
#include "ui_itemwindow.h"
#include <QString>
ItemWindow::ItemWindow(QString name, QPixmap photoType,QPixmap photoSpecial) :
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
    QWidget* layout= ui->widget_item;
    return layout;
}
