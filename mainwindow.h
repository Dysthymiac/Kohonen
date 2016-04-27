#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kohonennetwork.h"
#include "picturebox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    KohonenNetwork net;
    void updateImage();
    bool running;
};

#endif // MAINWINDOW_H