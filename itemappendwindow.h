#ifndef ITEMAPPENDWINDOW_H
#define ITEMAPPENDWINDOW_H

//#include <QWidget>
#include <QPixmap>
#include <QRadioButton>
#include <QMessageBox>
#include <QButtonGroup>
namespace Ui {
class ItemAppendWindow;
}

class ItemAppendWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ItemAppendWindow(QWidget *parent = nullptr);
    ~ItemAppendWindow();

    QWidget* getWidget();
    static bool active;
    QRadioButton *animeRButton;
    QRadioButton *mangaRButton;
    QButtonGroup *radioButtons;

public slots:
    void radioButtonChange();


signals:
    void clicked();

private slots:


    void on_save_button_released();

private:

    Ui::ItemAppendWindow *ui;
    QString mangaTypeLocation = "/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/manga.png";
    QString animeTypeLocation = "/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/anime.png";
    QString defaultImageLocation="/home/bozga/Desktop/qt projects/UnseenEp/Image/DefaultImage/emptyImage.jpg";





    QPixmap animeTypeImage;
    QPixmap mangaTypeImage;
    QPixmap image;
};

#endif // ITEMAPPENDWINDOW_H
