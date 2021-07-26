#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chrono>
#include <random>
#include <QPixmap>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionLicense_triggered();

private:
    Ui::MainWindow *ui;
    QPixmap *diceOne = new QPixmap(":/images/diceOne.png");
    QPixmap *diceTwo = new QPixmap(":/images/diceTwo.png");
    QPixmap *diceThree = new QPixmap(":/images/diceThree.png");
    QPixmap *diceFour = new QPixmap(":/images/diceFour.png");
    QPixmap *diceFive = new QPixmap(":/images/diceFive.png");
    QPixmap *diceSix = new QPixmap(":/images/diceSix.png");
};
#endif // MAINWINDOW_H
