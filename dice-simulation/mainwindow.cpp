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
    delete diceOne;
    delete diceTwo;
    delete diceThree;
    delete diceFour;
    delete diceFive;
    delete diceSix;
}


void MainWindow::on_pushButton_clicked()
{
    int rndNumber = generateRandomNumber();
    QLabel * dice = ui->outputLabel;
    switch(rndNumber) {
    case 1:
        dice->setPixmap(*diceOne);
        break;
    case 2:
        dice->setPixmap(*diceTwo);
        break;
    case 3:
        dice->setPixmap(*diceThree);
        break;
    case 4:
        dice->setPixmap(*diceFour);
        break;
    case 5:
        dice->setPixmap(*diceFive);
        break;
    case 6:
        dice->setPixmap(*diceSix);
        break;
    default:
        dice->setText("Bad number generated.");
        break;
    }
    ui->outputLabel->show();
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

