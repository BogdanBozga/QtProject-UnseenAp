#include "itemappendwindow.h"
#include "ui_itemappendwindow.h"
#include "mainwindow.h"
#include "itemwindow.h"


ItemAppendWindow::ItemAppendWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemAppendWindow)
{
    ui->setupUi(this);


    QPixmap animeTypeImage(animeTypeLocation);
    QPixmap mangaTypeImage(mangaTypeLocation);
    QPixmap image(defaultImageLocation);

    animeTypeImage = animeTypeImage.scaled(ui->photo_type_selected->width(),ui->photo_type_selected->height(),Qt::KeepAspectRatioByExpanding);
    mangaTypeImage = animeTypeImage.scaled(ui->photo_type_selected->width(),ui->photo_type_selected->height(),Qt::KeepAspectRatioByExpanding);
    image = image.scaled(ui->photo_special->width(),ui->photo_special->height(),Qt::KeepAspectRatioByExpanding);

    ui->photo_type_selected->setPixmap(animeTypeImage);
    ui->photo_special->setPixmap(image);

    animeRButton = new QRadioButton("Anime",this);
    mangaRButton = new QRadioButton("Manga",this);
    animeRButton->setChecked(true);

    QButtonGroup *radioButtons= new QButtonGroup();
    radioButtons->addButton(animeRButton);
    radioButtons->addButton(mangaRButton);
    ui->radioButton_layout->addWidget(qobject_cast<QWidget*>(radioButtons));
    ui->radioButton_layout->addWidget(animeRButton);

    ui->radioButton_layout->addWidget(mangaRButton);

//    connect(radioButtons,&QButtonGroup::buttonToggled,
//        this, &ItemAppendWindow::radioButtonChange);

//    connect(animeRButton,&QRadioButton::toggled,
//        this, &ItemAppendWindow::radioButtonChange);

//    connect(mangaRButton,&QRadioButton::toggled,
//        this, &ItemAppendWindow::radioButtonChange);
}

ItemAppendWindow::~ItemAppendWindow()
{
    delete ui;
}


QWidget* ItemAppendWindow::getWidget()
{
    QWidget *widget= qobject_cast<QWidget*>(ui->big_widget);
    return widget;
}

void ItemAppendWindow::radioButtonChange()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
    if(mangaRButton->isChecked()){
        ui->photo_type_selected->setPixmap(mangaTypeImage);
    }
    if(animeRButton->isChecked())
        ui->photo_type_selected->setPixmap(animeTypeImage);
    update();
}

void ItemAppendWindow::on_save_button_released()
{
//    QString name = qobject_cast<QString>(ui->name_text);
//    QPixmap type = ui->photo_type_selected->grab();
//    QPixmap specialPhoto = ui->photo_special->grab();
//    //ItemWindow item(name,type,specialPhoto);
}

