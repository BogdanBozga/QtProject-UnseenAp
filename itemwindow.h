#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QWidget>

namespace Ui {
class ItemWindow;
}

class ItemWindow : public QWidget
{
    Q_OBJECT

public:
     ItemWindow(QString name, QPixmap photoType,QPixmap photoSpecial);
    ~ItemWindow();
    QWidget* getLayout();

private:
    Ui::ItemWindow *ui;
};

#endif // ITEMWINDOW_H
