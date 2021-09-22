#include "itemappendwindow.h"
#include "ui_itemappendwindow.h"
#include "mainwindow.h"



ItemAppendWindow::ItemAppendWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemAppendWindow)
{
    ui->setupUi(this);

    QPixmap animeImage(animeTypeLocation);
    QPixmap mangaImage(mangaTypeLocation);
    QPixmap image(defaultImageLocation);


    animeImage = animeImage.scaled(ui->photo_type_selected->width(),ui->photo_type_selected->height(),Qt::KeepAspectRatioByExpanding);
    mangaImage = mangaImage.scaled(ui->photo_type_selected->width(),ui->photo_type_selected->height(),Qt::KeepAspectRatioByExpanding);
    image = image.scaled(ui->photo_special->width(),ui->photo_special->height(),Qt::KeepAspectRatioByExpanding);

    animeTypeImage = animeImage;
    mangaTypeImage = mangaImage;
    specialImage = image;

    ui->photo_type_selected->setPixmap(animeTypeImage);
    ui->photo_special->setPixmap(specialImage);

    ui->radioButton_anime->setChecked(true);
    QObject::connect(ui->radioButton_anime,&QRadioButton::toggled,this, &ItemAppendWindow::radioButtonChange);

}

ItemAppendWindow::~ItemAppendWindow()
{
    delete ui;
}


QWidget* ItemAppendWindow::getWidget()
{
    QWidget *widget= ui->big_widget;
    return widget;
}


void ItemAppendWindow::radioButtonChange()
{
    if(ui->radioButton_manga->isChecked()){
        ui->photo_type_selected->setPixmap(mangaTypeImage);
    }else if(ui->radioButton_anime->isChecked())
        ui->photo_type_selected->setPixmap(animeTypeImage);
}

void ItemAppendWindow::on_save_button_released()
{
    QString name = ui->name_text->displayText();
    QPixmap type = ui->photo_type_selected->grab();
    QPixmap specialPhoto = ui->photo_special->grab();
    ItemWindow nitem(name,type,specialPhoto);
    item = nitem.getLayout();
    emit save_done();
}

QWidget* ItemAppendWindow::getItem()
{
    return item;
}
