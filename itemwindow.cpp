#include "itemwindow.h"
#include "ui_itemwindow.h"
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>

ItemWindow::ItemWindow(QString name, QString typePhotoLocation, QString specialPhotoLocation , QString link,int cEp,int maxEp, int repetitionPeriod,QDate nextRelease,QTime time,int nrUnseeEps) :
    ui(new Ui::ItemWindow)
{

    ui->setupUi(this);

    ui->textBrowser->setText(name);
    QFont serifFont("Times", 25);
    ui->textBrowser->setFont(serifFont);
    ui->textBrowser->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);


    ui->lcdNumber->display(0);
    ui->lcdNumber->setDigitCount(2);

    QPixmap photoType = QPixmap(typePhotoLocation);
    QPixmap photoSpecial = QPixmap(specialPhotoLocation);


    ui->label_special_image->setPixmap(photoSpecial.scaled(ui->label_special_image->width(),ui->label_special_image->height(),Qt::IgnoreAspectRatio));
    ui->label_type_image->setPixmap(photoType.scaled(ui->label_type_image->width(),ui->label_type_image->height(),Qt::KeepAspectRatioByExpanding));

    this->link = link;
    this->repertitionInterval = repetitionPeriod;
    this->name = name;
    this->cEp = cEp;
    this->maxEp = maxEp;
    this->nextRelease = nextRelease;
    this->nextTime = time;
    this->typePhotoName = typePhotoLocation;
    this->specialPhotoName = specialPhotoLocation;
    this->unseenNumber = nrUnseeEps;
    verifyNumber();
    ui->lcdNumber->display(unseenNumber);
    this->deleteButton = ui ->DeleteItem;



    infoWindow = new InfoWindow(name,nextRelease, time, unseenNumber, getRemainingHours());
    connect(infoWindow, &InfoWindow::closeButoonInfoPress, this, &ItemWindow::on_closeSuplimetarInfo);
    connect(infoWindow,&InfoWindow::seenButtonInfoPress, this, &ItemWindow::on_seenButtonInfo);
    connect(infoWindow,&InfoWindow::itemOpenUrl, this, &ItemWindow::openUrl);

}
void ItemWindow::openUrl(){
    QDesktopServices::openUrl(QUrl(link));
}

void ItemWindow::on_seenButtonInfo(){
    this->unseenNumber-=1;
    ui->lcdNumber->display(unseenNumber);
    emit itemModifed();
}

void ItemWindow::on_closeSuplimetarInfo(){
    emit closeSupminearInfoForMainWindow();
}

ItemWindow::ItemWindow(ItemWindow &citem) :
    QWidget(citem.parentWidget()),
    ui(new Ui::ItemWindow)
{

    this->ui = citem.ui;
    this->name=citem.name;
    this->cEp=citem.cEp;
    this->maxEp=citem.maxEp;
    this->nextRelease=citem.nextRelease;
    this->nextTime=citem.nextTime;
    this->typePhotoName=citem.typePhotoName;
    this->specialPhotoName=citem.specialPhotoName;
    this->unseenNumber=citem.unseenNumber;
}


ItemWindow::~ItemWindow()
{
    delete ui;
}




QString ItemWindow::getLink(){
    return link;
}

int ItemWindow::getRepeatingPeriod(){
    return repertitionInterval;
}

QWidget* ItemWindow::getLayout()
{
    QWidget* layout = ui->widget_item;
    return layout;
}

void ItemWindow::verifyNumber()
{
    while(nextRelease < QDate::currentDate()){
        nextRelease = nextRelease.addDays(repertitionInterval);
        if(cEp+unseenNumber >= maxEp)
            break;
        unseenNumber++;
    }
}

int ItemWindow::getCEp() const
{
    return cEp;
}

void ItemWindow::setCEp(int newCEp)
{
    cEp = newCEp;
}

int ItemWindow::getMaxEp() const
{
    return maxEp;
}

void ItemWindow::setMaxEp(int newMaxEp)
{
    maxEp = newMaxEp;
}

int ItemWindow::getUnseenNumber() const
{
    return unseenNumber;
}

void ItemWindow::setUnseenNumber(int newUnseenNumber)
{
    unseenNumber = newUnseenNumber;
}

const QDate &ItemWindow::getNextRelease() const
{
    return nextRelease;
}

void ItemWindow::setNextRelease(const QDate &newNextRelease)
{
    nextRelease = newNextRelease;
}

const QTime &ItemWindow::getNextTime() const
{
    return nextTime;
}

void ItemWindow::setNextTime(const QTime &newNextTime)
{
    nextTime = newNextTime;
}

const QString ItemWindow::getName() const
{
    return name;
}

void ItemWindow::setName(const QString &newName)
{
    name = newName;
}

const QString &ItemWindow::getTypePhotoName() const
{
    return typePhotoName;
}

const QString &ItemWindow::getSpecialPhotoName() const
{
    return specialPhotoName;
}


void ItemWindow::on_SuplimentarInfo_clicked()
{
    emit suplimentarInfoAction(this->getName());
}


void ItemWindow::on_DeleteItem_released()
{
    emit deleteAction(this->getName());
}

int ItemWindow::getRemainingHours(){

    return 100;
}


void ItemWindow::closeRWindowInfo(){
    qWarning() << " from here where?";
//    emit closeWindowAction();
}
