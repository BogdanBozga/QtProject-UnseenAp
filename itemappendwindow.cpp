#include "ui_itemappendwindow.h"
#include "itemappendwindow.h"
#include "mainwindow.h"



ItemAppendWindow::ItemAppendWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemAppendWindow)
{
    ui->setupUi(this);

    typeImegeLocation = animeTypeLocation;
    specialImageLocation = defaultImageLocation;

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
    ui->date->setDate(QDate::currentDate());
    ui->radioButton_anime->setChecked(true);
    ui->total_ep->setValue(12);
    ui->last_ep->setValue(1);
    ui->repetitionPerioQSpinBox->setValue(7);
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
        typeImegeLocation = mangaTypeLocation;
    }else if(ui->radioButton_anime->isChecked()){
        ui->photo_type_selected->setPixmap(animeTypeImage);
        typeImegeLocation = animeTypeLocation;
    }
}

void ItemAppendWindow::on_save_button_released()
{
    QString name = ui->name_QLineEdit->text();
    QString link = ui->Link_QLineEdit->text();
    int cEp = ui->last_ep->value();
    int mEp = ui->total_ep->value();
    int repetiotion = ui->repetitionPerioQSpinBox->value();
    QDate date = ui->date->date();
    QTime time = ui->time->time();

    ItemWindow *nitem = new ItemWindow(name, typeImegeLocation, specialImageLocation, link, cEp, mEp, repetiotion, date, time);
    nitem->verifyNumber();
    item = nitem;
    emit save_done();
}


void ItemAppendWindow::on_cancel_button_clicked()
{
   emit close_signel();
}

void ItemAppendWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home/",
                                                    tr("Images (*.png *.xpm *.jpg)"));


    if(fileName.size()){
        specialImageLocation = fileName;

        if(CopyImage(fileName,imageResourseLocation)){
            QVector <QString> imageName = fileName.split("/");
            specialImageLocation = imageResourseLocation + imageName[imageName.length()-1];
        }else{
            qWarning()<< "Image copy fail";
        }
    }

    QPixmap image(specialImageLocation);
    specialImage = image.scaled(ui->photo_special->width(),ui->photo_special->height(),Qt::IgnoreAspectRatio);
    ui->photo_special->setPixmap(specialImage);
}

bool ItemAppendWindow::CopyImage(const QString& sourceFile, const QString& destinationDir)
{
    QFileInfo fileInfo(sourceFile);
    QString destinationFile = destinationDir + QDir::separator() + fileInfo.fileName();
    bool result = QFile::copy(sourceFile, destinationFile);
    return result;
}

