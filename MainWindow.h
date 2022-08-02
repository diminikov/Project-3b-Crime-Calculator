//
// Created by Dimitri on 7/31/2022.
//

#ifndef CRIMECALCULATORGUI_MAINWINDOW_H
#define CRIMECALCULATORGUI_MAINWINDOW_H

#include "CrimeGraph.h"
#include "Hash.h"
#include "StateInfo.h"
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>

class QPushButton;
class MainWindow : public QWidget
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    std::vector<bool> _answersToQuestions;
    std::vector<std::string> _questions;
    std::string _currState;
    int _currYear;
    void askQuestion(std::string question);
    void insertDataInGraph();
private slots:
    void slotNoButtonClicked();
    void slotYesButtonClicked();
    void slotStatePicked();
    void slotYearPicked();
    void slotRestartClicked();
private:
    int _windowWidth = 800;
    int _windowHeight = 400;
    int _questionNumber = 0;
    CrimeGraph* _crime;
    HashMapTable* _hashCrime;
    std::map<std::pair<std::string, int>, StateInfo*> _stateData;
    QLabel *_questionLabel;
    QLabel *_questionNumberLabel;
    QLabel * _recomendations1;
    QLabel * _recomendations2;
    QLabel * _outOf;
    QComboBox* _stateComboBox;
    QComboBox* _yearComboBox;
    QPushButton *_yesButton;
    QPushButton *_noButton;
    QPushButton *_restartButton;
};


#endif //CRIMECALCULATORGUI_MAINWINDOW_H
