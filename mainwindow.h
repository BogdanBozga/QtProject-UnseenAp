#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void addItem(ItemWindow);
private slots:
    void on_pushButton_clicked();

protected:
    QVector<ItemWindow> items;

private:




    bool rightWindowActive = false;
    bool leftWindowActive = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
