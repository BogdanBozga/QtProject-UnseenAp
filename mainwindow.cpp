#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "itemwindow.h"
#include "itemappendwindow.h"
#include "infowindow.h"
#include "mainwindow.h"

#include <QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&rWindow,&ItemAppendWindow::save_done,this,&MainWindow::addItem);
    QObject::connect(&rWindow,&ItemAppendWindow::close_signel,this,&MainWindow::removeRWidget);
    rWindowWidget = rWindow.getWidget();
    suplimentarInfoMode = false;
    rightWindowActive = false;
    ui->verticalSlider->setVisible(false);
    readAllItems();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addItem()
{
    ItemWindow *item = rWindow.item;
    connect(item,&ItemWindow::deleteAction,this,&MainWindow::deleteItem);
    connect(item,&ItemWindow::suplimentarInfoAction,this,&MainWindow::on_suplimentarInfo);
    items.append(item);
    ui->item_place->insertWidget(0,item->getLayout());

    update();
    writeItem(item);
}

void MainWindow::removeRWidget(){
    ui->widget_right->setVisible(false);
    rightWindowActive= false;
}


void MainWindow::writeItem(ItemWindow *item){

    QFile saveFileR(QStringLiteral("save.json"));

    if (!saveFileR.open(QIODevice::ReadOnly))
        qWarning("Couldn't open save file.");

    QByteArray saveData = saveFileR.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    QJsonObject loadData = loadDoc.object();

    QJsonArray itemsArray;

    QJsonObject itemObject;
    itemObject["name"] = item->getName();
    itemObject["specialPhoto"] = item->getSpecialPhotoName();
    itemObject["typePhoto"] = item->getTypePhotoName();
    itemObject["nextReleaseDate"] = item->getNextRelease().toString();
    itemObject["releaseTime"] = item->getNextTime().toString();
    itemObject["nrTotalEps"] = item->getMaxEp();
    itemObject["nrCurentEp"] = item->getCEp();
    itemObject["nrUnseeEps"] = item->getUnseenNumber();
    itemsArray.append(itemObject);

    if (loadData.contains("items") && loadData["items"].isArray()) {
    QJsonArray data = loadData["items"].toArray();
    for (int levelIndex = 0; levelIndex < data.size(); ++levelIndex) {
        QJsonObject itemData = data[levelIndex].toObject();
        itemsArray.append(itemData);
    }
    }
    saveFileR.close();
    QFile saveFileW(QStringLiteral("save.json"));
    if (!saveFileW.open(QIODevice::WriteOnly))
        qWarning("Couldn't open save file.");


    QJsonObject jsonData;
    jsonData["items"] = itemsArray;
    saveFileW.write(QJsonDocument(jsonData).toJson());


}


void MainWindow::updateWidget(QWidget *widget){
        ui->item_place->removeWidget(widget);
        update();
}

bool MainWindow::writeAllItems()
{
    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }
    QJsonObject jsonData;

    QJsonArray itemsArray;
    for (ItemWindow *item : items) {
        QJsonObject itemObject;
        itemObject["name"] = item->getName();
        itemObject["specialPhoto"] = item->getSpecialPhotoName();
        itemObject["typePhoto"] = item->getTypePhotoName();
        itemObject["nextReleaseDate"] = item->getNextRelease().toString();
        itemObject["releaseTime"] = item->getNextTime().toString();
        itemObject["nrTotalEps"] = item->getMaxEp();
        itemObject["nrCurentEp"] = item->getCEp();
        itemObject["nrUnseeEps"] = item->getUnseenNumber();
        itemsArray.append(itemObject);
    }

    jsonData["items"] = itemsArray;
    saveFile.write(QJsonDocument(jsonData).toJson());
    return true;
}



bool MainWindow::readAllItems()
{
    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }
    QByteArray saveData = saveFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    QJsonObject loadData = loadDoc.object();
    if (loadData.contains("items") && loadData["items"].isArray()) {
        items.clear();
        QJsonArray itemArray = loadData["items"].toArray();
        QString name;
        QString typePhotoLocation;
        QString specialPhotoLocation;
        int cEp=0;
        int maxEp=0;
        int nrUnseeEps=0;
        QDate nextRelease;
        QTime time;

        int indexOfInsertion=0;
        for (int levelIndex = 0; levelIndex < itemArray.size(); ++levelIndex) {
            QJsonObject itemData = itemArray[levelIndex].toObject();

            if (itemData.contains("name") && itemData["name"].isString()){
                name = itemData["name"].toString();
            }

            if (itemData.contains("specialPhoto") && itemData["specialPhoto"].isString()){
                specialPhotoLocation = itemData["specialPhoto"].toString();
            }

            if (itemData.contains("typePhoto") && itemData["typePhoto"].isString()){
                typePhotoLocation = itemData["typePhoto"].toString();
            }

            if (itemData.contains("nextReleaseDate") && itemData["nextReleaseDate"].isString()){
                nextRelease = QDate::fromString(itemData["nextReleaseDate"].toString());
            }

            if (itemData.contains("releaseTime") && itemData["releaseTime"].isString()){
                time = QTime::fromString(itemData["releaseTime"].toString());
            }

            if (itemData.contains("nrTotalEps") && itemData["nrTotalEps"].isDouble()){
                maxEp = itemData["nrTotalEps"].toInt();
            }
            if (itemData.contains("nrCurentEp") && itemData["nrCurentEp"].isDouble()){
                cEp = itemData["nrCurentEp"].toInt();
            }

            if (itemData.contains("nrUnseeEps") && itemData["nrUnseeEps"].isDouble()){
                nrUnseeEps = itemData["nrUnseeEps"].toInt();
            }

            ItemWindow *item = new ItemWindow(name,typePhotoLocation,specialPhotoLocation,cEp,maxEp,nextRelease,time,nrUnseeEps);
            item->verifyNumber();
            items.append(item);
            connect(item,&ItemWindow::deleteAction,this,&MainWindow::deleteItem);
            connect(item,&ItemWindow::suplimentarInfoAction,this,&MainWindow::on_suplimentarInfo);
            ui->item_place->insertWidget(indexOfInsertion++,item->getLayout());//we need to specify the insertion index in order to insert before the spacer
            update();
        }

    }else{
        qWarning() << "No data to be readed";
    }
    return true;
}

void MainWindow::deleteItem(QString name)
{
    qWarning() << name + " on delete item";
    for(int i=0;i<items.length();i++){
        if(items[i]->getName()==name){
            updateWidget(items[i]->getLayout());
            items.removeAt(i);
            break;
        }
    }
    writeAllItems();
    update();
}


void MainWindow::on_addButton_clicked()// the button for right window
{
    if(!rightWindowActive){
        if(suplimentarInfoMode){
            ui->widget_right->layout()->removeWidget(infoWindowWidget);
            ui->widget_right->repaint();
            suplimentarInfoMode = false;
        }
        ui->widget_right->layout()->addWidget(rWindowWidget);
        ui->widget_right->setVisible(true);
        rightWindowActive = true;
    }
}

void MainWindow::on_suplimentarInfo(QString name){
            for(int i=0;i<items.length();i++){
                if(items[i]->getName()==name){
                    if(rightWindowActive){
                         ui->widget_right->layout()->removeWidget(rWindowWidget);
                         ui->widget_right->repaint();
                         rightWindowActive = false;
                    }
                    infoWindowInstance = new InfoWindow(name, items[i]->getNextRelease(), items[i]->getNextTime(), items[i]->getUnseenNumber());
                    infoWindowWidget = infoWindowInstance->getWidget();
                    suplimentarInfoMode = true;

                    ui->widget_right->layout()->addWidget(infoWindowWidget);
                    ui->widget_right->setVisible(true);
                    break;
                }
            }

}



