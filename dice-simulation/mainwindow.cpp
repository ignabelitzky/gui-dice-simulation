#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// Generates random number between 1 and 6
static int generateRandomNumber()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
                (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count() +
                        (std::mt19937::result_type)
                        std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
    std::mt19937::result_type n;
    while((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 5) % 6) {
        // bad value retrieved so get next one
    }
    return ((n % 6) + 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int rndNumber = generateRandomNumber();
    ui->outputLabel->setText(QString::number(rndNumber));
}

