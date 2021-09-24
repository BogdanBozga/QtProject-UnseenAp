#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QApplication>

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
private slots:
    void on_pushButton_clicked();
    void addItem();

private:
    ItemAppendWindow rWindow;

//    bool leftWindowActive = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
