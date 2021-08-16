#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    diceFaces[0] = new QPixmap(":/images/diceOne.png");
    diceFaces[1] = new QPixmap(":/images/diceTwo.png");
    diceFaces[2] = new QPixmap(":/images/diceThree.png");
    diceFaces[3] = new QPixmap(":/images/diceFour.png");
    diceFaces[4] = new QPixmap(":/images/diceFive.png");
    diceFaces[5] = new QPixmap(":/images/diceSix.png");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
}

// Generates random number between 0 and 5
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
    return (n % 6);
}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0; i < 6; ++i) {
        delete diceFaces[i];
    }
    delete timer;
}

void MainWindow::showRandomFaces()
{
    timer->start(75);
}

void MainWindow::stopRandomFaces()
{
    timer->stop();
}

void MainWindow::on_pushButton_clicked()
{
    QTimer::singleShot(1500, this, SLOT(stopRandomFaces()));
    showRandomFaces();
}


void MainWindow::on_actionLicense_triggered()
{
    QMessageBox msgBox;
    QString information("<center><b>License</b><br>GNU Lesser General Public License v2.1<br><br><b>Created by</b><br>Ignacio Belitzky</center>");
    QString title("About Dice Simulator");
    msgBox.setText(information);
    msgBox.setWindowTitle(title);
    msgBox.addButton(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::onTimeOut()
{
    QLabel * dice = ui->outputLabel;
    int rndNumber = generateRandomNumber();
    dice->setPixmap(*diceFaces[rndNumber]);
}

