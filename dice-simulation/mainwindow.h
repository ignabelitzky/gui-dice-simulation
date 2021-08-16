#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chrono>
#include <random>
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showRandomFaces();

private slots:
    void on_pushButton_clicked();
    void on_actionLicense_triggered();
    void onTimeOut();
    void stopRandomFaces();

private:
    Ui::MainWindow *ui = nullptr;
    QPixmap *diceFaces[6];
    QTimer *timer = nullptr;
};
#endif // MAINWINDOW_H
