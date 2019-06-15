#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QStyle>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QGraphicsPixmapItem>

#include <drawscene.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void open();
    void test_motion_estimation();
    void test_graphcut();

    void on_graphcutGammaSlider_valueChanged(int value);
    void on_fgdRadius_valueChanged(int value);
    void on_bgdRadius_valueChanged(int value);
    void on_foregroundTool_clicked();
    void on_backgroundTool_clicked();
    void on_defaultTool_clicked();

private:
    Ui::MainWindow *ui;

    DrawScene *drawScene;
    QImage *curImage;
    QGraphicsPixmapItem pixmapItem;

    QAction *openAction, *test1Action, *test2Action;
    QFileDialog *fileDiolog;
    QString path;

    double uiGamma = 10;
};

#endif // MAINWINDOW_H
