#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

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
    QVector<QWidget*> items;

private slots:
    void on_pushButton_clicked();
    void addItem();

private:
    ItemAppendWindow rWindow;
    bool rightWindowActive = false;
//    bool leftWindowActive = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
