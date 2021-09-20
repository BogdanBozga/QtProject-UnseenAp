#include "itemappendwindow.h"
#include "ui_itemappendwindow.h"
#include "mainwindow.h"
#include "itemwindow.h"


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
//    animeRButton = new QRadioButton("Anime",this);
//    mangaRButton = new QRadioButton("Manga",this);
//    animeRButton->setChecked(true);

//    QButtonGroup *radioButtons= new QButtonGroup();
//    radioButtons->addButton(animeRButton);
//    radioButtons->addButton(mangaRButton);
//    //ui->radioButton_layout->addLayout(qobject_cast<QLayout*>(radioButtons));
//    ui->radioButton_layout->addWidget(animeRButton);
//    ui->radioButton_layout->addWidget(mangaRButton);

//    QMessageBox msgBox;
//    msgBox.setText("The document has been modified.");
//    msgBox.exec();

//    QObject::connect(animeRButton, &QRadioButton::toggled, this, &ItemAppendWindow::radioButtonChange);
   // QObject::connect(mangaRButton, &QRadioButton::toggled, this, &ItemAppendWindow::radioButtonChange);

    ui->radioButton_anime->setChecked(true);
    QObject::connect(ui->radioButton_anime,&QRadioButton::toggled,this, &ItemAppendWindow::radioButtonChange);
    //QObject::connect(ui->radioButton_manga,&QRadioButton::clicked,this, &ItemAppendWindow::radioButtonChange);

    //QObject::connect(animeRButton, &ItemAppendWindow::toggled, this, &ItemAppendWindow::radioButtonChange);
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
    QWidget *widget= ui->big_widget;
    return widget;
}

//ItemAppendWindow::ItemAppendWindow(const ItemAppendWindow &cWindow)
//{
//    ui->setupUi(cWindow.ui->big_widget);
//}

void ItemAppendWindow::radioButtonChange()
{
    if(ui->radioButton_manga->isChecked()){
        ui->photo_type_selected->setPixmap(mangaTypeImage);
    }else if(ui->radioButton_anime->isChecked())
        ui->photo_type_selected->setPixmap(animeTypeImage);
}

void ItemAppendWindow::on_save_button_released()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
//    QString name = qobject_cast<QString>(ui->name_text);
//    QPixmap type = ui->photo_type_selected->grab();
//    QPixmap specialPhoto = ui->photo_special->grab();
//    //ItemWindow item(name,type,specialPhoto);
}
