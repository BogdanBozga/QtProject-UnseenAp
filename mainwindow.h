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
#include <QCloseEvent>

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
    QList<ItemWindow*> items;
    bool rightWindowActive;
    bool writeAllItems();
    bool readAllItems();
    void addItem();
    void writeItem(ItemWindow *item);
    static void appendItem(ItemWindow item);
//    static void addItem(ItemWindow item);
    ItemAppendWindow rWindow;
    Ui::MainWindow *ui;
    //    void closeEvent (QCloseEvent *event) override;
    void fuck(ItemWindow item);
private slots:
    void on_pushButton_clicked();
private:

};
#endif // MAINWINDOW_H
