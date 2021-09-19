#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    ui->setupUi(this);
    QPixmap sImage("/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/emptyImage.jpg");
    QPixmap typeImage("/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/manga.png");

    ui->label_special_image->setPixmap(sImage.scaled(ui->label_special_image->width(),ui->label_special_image->height(),Qt::KeepAspectRatio));
    ui->label_type_image->setPixmap(typeImage.scaled(ui->label_type_image->width(),ui->label_type_image->height(),Qt::KeepAspectRatio));

}

Form::~Form()
{
    delete ui;
}
