#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "itemwindow.h"
#include "itemappendwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_right->layout()->addWidget(rWindow.getWidget());
    ui->widget_right->setVisible(false);
    QObject::connect(&rWindow,&ItemAppendWindow::save_done,this,&MainWindow::addItem);
    QObject::connect(&rWindow,&ItemAppendWindow::close_signel,this,&MainWindow::removeRWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRWidget()
{
    if(!rightWindowActive){
        rightWindowActive = true;
        ui->widget_right->setVisible(true);
    }
}

void MainWindow::addItem()
{
    ItemWindow *item = rWindow.item;
    items.push_back(item);


//    QDate data=QDate::currentDate();
//    QMessageBox msgBox;
//    msgBox.setText(data.toString("yyyy.MM.dd"));
//    msgBox.exec();
    ui->item_place->insertWidget(0,item->getLayout());
    update();
    //rWindow.setVisible(true);
    //ui->widget_right->removeWidget(rWindow.getWidget());

//    qApp->processEvents();
}

void MainWindow::on_pushButton_clicked()
{
    if(!rightWindowActive){
        rightWindowActive = true;
        ui->widget_right->setVisible(true);
    }
}

void MainWindow::removeRWidget(){
    ui->widget_right->setVisible(false);
    rightWindowActive= false;
}

