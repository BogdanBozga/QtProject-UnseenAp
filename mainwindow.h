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
    bool writeAllItems();
    bool readAllItems();
    void addItem();
    void writeItem(ItemWindow *item);

    void updateWidget(QWidget *layout);



    QList<ItemWindow*> items;




public slots:
    void addInfoToRWidget(QWidget *widget);
    void deleteItem(QString name);
    void deleteItem();
    void testSlot();

private slots:
    void on_addButton_clicked();

private:
    bool rightWindowActive;
    Ui::MainWindow *ui;
    ItemAppendWindow rWindow;
};
#endif // MAINWINDOW_H
