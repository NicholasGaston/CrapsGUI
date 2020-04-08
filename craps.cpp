#include <iostream>
#include <stdio.h>
//#include <QApplication>
//#include <QWidget>
//#include <QGridLayout>
//#include <QPushButton>
//#include <QLabel>
//#include <QPixmap>

#include "die.h"
#include "craps.h"
#include "ui_CrapsMainWindow.h"


CrapsMainWindow :: CrapsMainWindow(QMainWindow *parent) {
    // Build a GUI window with two dice.

    currentBankValue = 10000;
    setupUi(this);

    Die die1, die2;
    bool firstRoll = true;
    int winsCount = 0;

    QObject::connect(rollButton, SIGNAL(clicked()), this, SLOT(rollButtonClickedHandler()));
    QObject::connect(UserBetBox, SIGNAL(clicked()), this, SLOT(rollButtonClickedHandler()));
}
void CrapsMainWindow::printStringRep() {
    // String representation for Craps.
    char buffer[25];
    int length =  sprintf(buffer, "Die1: %i\nDie2: %i\n", die1.getValue(), die2.getValue());
    printf("%s", buffer);
}
void CrapsMainWindow::updateUI() {
//    printf("Inside updateUI()\n");
    std::string die1ImageName = ":/dieImages/" + std::to_string(die1.getValue());
    std::string die2ImageName = ":/dieImages/" + std::to_string(die2.getValue());
    die1UI->setPixmap(QPixmap(QString::fromStdString(die1ImageName)));
    die2UI->setPixmap(QPixmap(QString::fromStdString(die2ImageName)));
    BankChecker->setText(QString::fromStdString(message));
    currentBankValueUI->setText(QString::fromStdString(std::to_string(currentBankValue)));
}

// Player asked for another roll of the dice.
void CrapsMainWindow::rollButtonClickedHandler() {
//void Craps::rollButtonClickedHandler() {
    printf("Roll button clicked\n");
    checkBankValue();

    die1.roll();
    die2.roll();

    printStringRep();
    updateUI();
}




void CrapsMainWindow::checkBankValue()
{
    if(currentBankValue - UserBetBox->value() < 0)
    {

        message = "You dont have enough money to bet that amount!!";
    }
    else
    {
        message = ("You bet $" + std::to_string(UserBetBox->value()));
         currentBankValue -= UserBetBox->value();
    }

      }
