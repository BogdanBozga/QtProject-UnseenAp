#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "itemwindow.h"
#include "itemappendwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRWidget()

{   if(!rightWindowActive){
        rightWindowActive = true;
        ui->widget_right->layout()->addWidget(rWindow.getWidget());
    }
    //ui->widget_left->widget()->setVisible(false);
}

//void MainWindow::addItem(ItemWindow item)
//{
//    items.append(item);

//}

void MainWindow::on_pushButton_clicked()
{
    addRWidget();
}


