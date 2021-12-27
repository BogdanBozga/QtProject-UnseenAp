#ifndef ITEMAPPENDWINDOW_H
#define ITEMAPPENDWINDOW_H

//#include <QWidget>
#include <QPixmap>
#include <QRadioButton>
#include <QMessageBox>
#include <QButtonGroup>
#include <QFileDialog>
#include <QSysInfo>
#include <QDir>

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
    bool CopyImage(const QString& sourceFile, const QString& destinationDir);

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
    void on_pushButton_clicked();

private:

    Ui::ItemAppendWindow *ui;
    QString mangaTypeLocation = ":/image/Image/DefaultImage/manga.png";
    QString animeTypeLocation = ":/image/Image/DefaultImage/anime.png";
    QString defaultImageLocation=":/image/Image/DefaultImage/emptyImage.jpg";
    QString imageResourseLocation = "/home/bozga/PersonalProjects/QtProjects/UnseenEp/Image/SpecialImage/";

    QString typeImegeLocation;
    QString specialImageLocation;


//    QWidget* getItem();
    QPixmap animeTypeImage;
    QPixmap mangaTypeImage;
    QPixmap specialImage;
};

#endif // ITEMAPPENDWINDOW_H
