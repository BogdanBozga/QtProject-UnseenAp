#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include <QFile>
#include <QCborMap>
#include <QCborValue>
#include "itemappendwindow.h"
#include "itemwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addRWidget();
    void removeRWidget();
    QVector<ItemWindow*> items;
    bool rightWindowActive;
    bool writeAllItems();
    bool readAllItems();
    void addItem();
    ItemAppendWindow rWindow;
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_clicked();
private:

};
#endif // MAINWINDOW_H
