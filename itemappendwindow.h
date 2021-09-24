#ifndef ITEMAPPENDWINDOW_H
#define ITEMAPPENDWINDOW_H

//#include <QWidget>
#include <QPixmap>
#include <QRadioButton>
#include <QMessageBox>
#include <QButtonGroup>

#include "itemwindow.h"

namespace Ui {
class ItemAppendWindow;
}

class ItemAppendWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ItemAppendWindow(QWidget *parent = nullptr);
    ~ItemAppendWindow();
    ItemWindow *item;
    QWidget* getWidget();
    static bool active;
    QRadioButton *animeRButton;
    QRadioButton *mangaRButton;
    QButtonGroup *radioButtons;
signals:
    void save_done();
    void close_signel();

public slots:
    void radioButtonChange();
    void on_save_button_released();

private slots:
    void on_cancel_button_clicked();

private:

    Ui::ItemAppendWindow *ui;
    QString mangaTypeLocation = "/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/manga.png";
    QString animeTypeLocation = "/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/anime.png";
    QString defaultImageLocation="/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/emptyImage.jpg";
    QWidget* getItem();




    QPixmap animeTypeImage;
    QPixmap mangaTypeImage;
    QPixmap specialImage;
};

#endif // ITEMAPPENDWINDOW_H
