#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "itemwindow.h"
#include "itemappendwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(this,&MainWindow::save_done,this,&MainWindow::addItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRWidget()

{   if(!rightWindowActive){
        rightWindowActive = true;
        ui->widget_right->layout()->addWidget(rWindow.getWidget());
        //rWindow.setVisible(true);
    }
    //ui->widget_left->widget()->setVisible(false);
    //connect(this,&MainWindow::save_done,this,&MainWindow::addItem);
    QObject::connect(&rWindow,&ItemAppendWindow::save_done,this,&MainWindow::addItem);
}

void MainWindow::addItem()
{


    QWidget *item = rWindow.item;
    items.push_back(item);


    QDate data=QDate::currentDate();
    QMessageBox msgBox;
    msgBox.setText(data.toString("yyyy.MM.dd"));
    msgBox.exec();
    ui->item_place->insertWidget(0,item);
    update();
    //rWindow.setVisible(true);
}

void MainWindow::on_pushButton_clicked()
{
    addRWidget();
}


