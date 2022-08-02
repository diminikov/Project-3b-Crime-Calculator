//
// Created by Dimitri on 7/31/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include <QApplication>
#include <iostream>

void ReadValuesFromFile(std::string filepath, std::map<std::pair<std::string, int>, StateInfo*>& data)
{
    std::ifstream file(filepath);

    if (file.is_open()) {
// read the heading data from the file
        std::string lineFromFile;
        getline(file, lineFromFile);


// get all lines from the file, one at a time
        while (getline(file, lineFromFile)) {
// stream of data coming from a string
            std::istringstream stream(lineFromFile);

// temp variabes needed
            std::string temp;
            std::string state;
            int year;
            int dataPopulation;
            double propertyAll;
            double propertyBurglary;
            double propertyLarceny;
            double propertyMotor;
            double violentAll;
            double violentAssault;
            double violentMurder;
            double violentRape;
            double violentRobbery;
            int populationAffectedByCrime;
            double percentPopProperty;
            double percentPopBurglary;
            double percentPopLarceny;
            double percentPopMotor;
            double percentPopViolent;
            double percentPopAssault;
            double percentPopMurder;
            double percentPopRape;
            double percentPopRobbery;
            double percentPopCrime;

            getline(stream, state, ',');
            getline(stream, temp, ',');
            year = stoi(temp);
            getline(stream, temp, ',');
            dataPopulation = stoi(temp);
            getline(stream, temp, ',');
            propertyAll = stod(temp);
            getline(stream, temp, ',');
            propertyBurglary = stod(temp);
            getline(stream, temp, ',');
            propertyLarceny = stod(temp);
            getline(stream, temp, ',');
            propertyMotor = stod(temp);
            getline(stream, temp, ',');
            violentAll = stod(temp);
            getline(stream, temp, ',');
            violentAssault = stod(temp);
            getline(stream, temp, ',');
            violentMurder = stod(temp);
            getline(stream, temp, ',');
            violentRape = stod(temp);
            getline(stream, temp, ',');
            violentRobbery = stod(temp);
            for (int i = 0; i < 9; i++)
                getline(stream, temp, ',');
            getline(stream, temp, ',');
            populationAffectedByCrime = stoi(temp);
            getline(stream, temp, ',');
            percentPopProperty = stod(temp);
            getline(stream, temp, ',');
            percentPopBurglary = stod(temp);
            getline(stream, temp, ',');
            percentPopLarceny = stod(temp);
            getline(stream, temp, ',');
            percentPopMotor = stod(temp);
            getline(stream, temp, ',');
            percentPopViolent = stod(temp);
            getline(stream, temp, ',');
            percentPopAssault = stod(temp);
            getline(stream, temp, ',');
            percentPopMurder = stod(temp);
            getline(stream, temp, ',');
            percentPopRape = stod(temp);
            getline(stream, temp, ',');
            percentPopRobbery = stod(temp);
            getline(stream, temp);
            percentPopCrime = stod(temp);


// construct an object from the temporary data
            auto obj = new StateInfo(dataPopulation, propertyAll, propertyBurglary, propertyLarceny, propertyMotor,
                                     violentAll, violentAssault, violentMurder,
                                     violentRape, violentRobbery, populationAffectedByCrime, percentPopProperty,
                                     percentPopBurglary, percentPopLarceny, percentPopMotor, percentPopViolent,
                                     percentPopAssault,
                                     percentPopMurder, percentPopRape, percentPopRobbery, percentPopCrime);
            data.insert({{state, year}, obj});
        }
        file.close();
    }
}


vector<string> GenerateRecommendations(vector<bool>& answersToQuestions) {
    vector<string> vec;
    if (answersToQuestions[10]) {
        vec.push_back("When you go out, make sure to go out with a group.");
    }
    if (answersToQuestions[9]) {
        vec.push_back("Try your best to limit your exposure to drugs and alcohol as these substances have been proven to significantly increase crime.");
    }
    if (answersToQuestions[8]) {
        vec.push_back("It is advised that you don't stay out past dark on a consistent basis, as crime rates increase substantially at night.");
    }
    if (answersToQuestions[4]) {
        vec.push_back("Gas stations are a common place for crime at night, so try to avoid going to these after dark.");
    }
    if (answersToQuestions[2]) {
        vec.push_back("Property crimes is very high towards people when they are in cars. Our recommendation is to keep your car doors locked and windows up.");
        vec.push_back("A can of pepper spray would also be a suggestion, as a lot of crime in cars happens at stop lights, and this would provide a way of defense.");
    }
    if ((answersToQuestions[7])) {
        vec.push_back("We highly advise you do NOT bring guests into your place of residency unless you know them well. There are a variety of crimes that you expose "
                   "yourself to by bringing strangers into your place of residency.");
    }
    if ((answersToQuestions[5])) {
        vec.push_back("Break ins are six percent more likely during the day, so always make sure to keep your doors locked and windows shut if they are not being monitored.");
    }
    vec.push_back("No Recommendations, Congratulations!");
    vec.push_back("No Recommendations, Congratulations!");
    return vec;
}

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent)
{
    _currYear = 2000;
    //Set size of the window
    setFixedSize(_windowWidth, _windowHeight);

    //Setting the first question of the test
    _questions.push_back("What state would you like to calculate for?");
    _questions.push_back("What year would you like to calculate for?");

    ReadValuesFromFile("finalProject_stateCrimeData.csv", _stateData);

    _crime = new CrimeGraph(0);

    //Create and position the question
    _questionLabel = new QLabel(QString::fromStdString(_questions[_questionNumber]), this);
    _questionLabel->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)-100, 300, 60);
    _questionLabel->setAlignment(Qt::AlignCenter);
    _questionLabel->setWordWrap(true);

    //Create and position the question number
    _questionNumberLabel = new QLabel(QString::fromStdString("Question " + std::to_string(_questionNumber+1)), this);
    _questionNumberLabel->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)-150, 300, 60);
    _questionNumberLabel->setAlignment(Qt::AlignCenter);

    _stateComboBox = new QComboBox(this);
    _stateComboBox->setGeometry(((_windowWidth/2)-100), (_windowHeight/2)-10, 200, 20);
    _stateComboBox->addItems({"Choose State", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "District of Columbia",
                              "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana",
                              "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska",
                              "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota",
                              "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee",
                              "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"});

    _yearComboBox = new QComboBox(this);
    _yearComboBox->setGeometry(((_windowWidth/2)-100), (_windowHeight/2)-10, 200, 20);
    _yearComboBox->addItem("Choose Year");
    for(int i = 1960; i < 2019; i ++){
        _yearComboBox->addItem(QString::fromStdString(to_string(i)));
    }
    _yearComboBox->hide();

    //Create and position the yes button
    _yesButton = new QPushButton("Yes", this);
    _yesButton->setGeometry(((_windowWidth/2)-40)-80, (_windowHeight/2)+30, 80, 30);
    _yesButton->hide();

    //Create and position the no button
    _noButton = new QPushButton("No", this);
    _noButton->setGeometry(((_windowWidth/2)-40)+80, (_windowHeight/2)+30, 80, 30);
    _noButton->hide();

    //Create and position the restart button
    _restartButton = new QPushButton("Restart", this);
    _restartButton->setGeometry((_windowWidth- 80), (_windowHeight- 30), 80, 30);
    _restartButton->hide();

    _questionNumber++;

    _answersToQuestions.resize(10, false);

    //Connecting the functions to the buttons
    connect(_yesButton, SIGNAL (clicked()), this, SLOT (slotYesButtonClicked()));
    connect(_noButton, SIGNAL (clicked()), this, SLOT (slotNoButtonClicked()));
    connect(_restartButton, SIGNAL (clicked()), this, SLOT (slotRestartClicked()));
    connect(_stateComboBox, SIGNAL (currentTextChanged(QString)), this, SLOT (slotStatePicked()));
    connect(_yearComboBox, SIGNAL (currentTextChanged(QString)), this, SLOT (slotYearPicked()));
}



void MainWindow::slotNoButtonClicked() {
    if(_questionNumber < _questions.size()-1) {
        _answersToQuestions[_questionNumber] = false;
        _questionNumber++;
        askQuestion(_questions[_questionNumber]);
    }else{
        insertDataInGraph();
    }
}

void MainWindow::slotYesButtonClicked() {
    if(_questionNumber < _questions.size()-1) {
        _answersToQuestions[_questionNumber] = true;
        _questionNumber++;
        askQuestion(_questions[_questionNumber]);
    }else{
        insertDataInGraph();
    }
}

void MainWindow::askQuestion(std::string question) {
    _questionNumberLabel->setText(QString::fromStdString("Question " + std::to_string(_questionNumber+1)));
    _questionLabel->setText(QString::fromStdString(question));
}

void MainWindow::slotStatePicked() {
        _currState = _stateComboBox->currentText().toStdString();
        _stateComboBox->hide();
        _yearComboBox->show();
        _questionNumber++;
}

void MainWindow::insertDataInGraph() {
    _yesButton->hide();
    _noButton->hide();
    double crimeOffset = ((_stateData.find({_currState, _currYear})->second->_percentPopCrime)) / 5;
    if(crimeOffset < 1){
        crimeOffset = 1;
    }else if(crimeOffset > 1.14){
        crimeOffset = 1.14;
    }
    for(int i = 2; i < _answersToQuestions.size(); i ++){
        if(_answersToQuestions[i]) {
            switch (i) {
                case 2:
                    _crime->setWeight(2,(_crime->getWeight(0, 2) + 7)*crimeOffset);
                    _crime->setWeight(0, (_crime->getWeight(0, 1) + 7)*crimeOffset);
                    break;
                case 3:
                    _crime->setWeight(3, (_crime->getWeight(0, 3) + 9)*crimeOffset);
                    _crime->setWeight(0, (_crime->getWeight(0, 1) + 9)*crimeOffset);
                    break;
                case 4:
                    _crime->setWeight(1, (_crime->getWeight(0, 1) + 8)*crimeOffset);
                    break;
                case 5:
                    _crime->setWeight(1, (_crime->getWeight(0, 1) + 8)*crimeOffset);
                    _crime->setWeight(0, (_crime->getWeight(0, 0) + 8)*crimeOffset);
                    break;
                case 6:
                    _crime->setWeight(5, (_crime->getWeight(0, 5) + 9)*crimeOffset);
                    _crime->setWeight(4, (_crime->getWeight(0, 4) + 9)*crimeOffset);
                    break;
                case 7:
                    _crime->setWeight(5, (_crime->getWeight(0, 5) + 15)*crimeOffset);
                    _crime->setWeight(6, (_crime->getWeight(0, 6) + 15)*crimeOffset);
                    _crime->setWeight(7, (_crime->getWeight(0, 7) + 15)*crimeOffset);
                    _crime->setWeight(8, (_crime->getWeight(0, 8) + 15)*crimeOffset);
                    _crime->setWeight(4, (_crime->getWeight(0, 4) + 15)*crimeOffset);
                    break;
                case 8:
                    _crime->setWeight(5, (_crime->getWeight(0, 5) + 15)*crimeOffset);
                    _crime->setWeight(6, (_crime->getWeight(0, 6) + 15)*crimeOffset);
                    _crime->setWeight(7, (_crime->getWeight(0, 7) + 15)*crimeOffset);
                    _crime->setWeight(8, (_crime->getWeight(0, 8) + 15)*crimeOffset);
                    _crime->setWeight(4, (_crime->getWeight(0, 4) + 15)*crimeOffset);
                    break;
                case 9:
                    _crime->setWeight(5, (_crime->getWeight(0, 5) + 8)*crimeOffset);
                    _crime->setWeight(6, (_crime->getWeight(0, 6) + 8)*crimeOffset);
                    _crime->setWeight(7, (_crime->getWeight(0, 7) + 8)*crimeOffset);
                    _crime->setWeight(8, (_crime->getWeight(0, 8) + 8)*crimeOffset);
                    _crime->setWeight(4, (_crime->getWeight(0, 4) + 8)*crimeOffset);
                    break;
                case 10:
                    _crime->setWeight(5, (_crime->getWeight(0, 5) * 6)*crimeOffset);
                    _crime->setWeight(6, (_crime->getWeight(0, 6) * 6)*crimeOffset);
                    _crime->setWeight(7, (_crime->getWeight(0, 7) * 6)*crimeOffset);
                    _crime->setWeight(8, (_crime->getWeight(0, 8) * 6)*crimeOffset);
                    _crime->setWeight(4, (_crime->getWeight(0, 4) * 6)*crimeOffset);
                    break;
                default:
                    break;
            }
        }
    }
    _hashCrime = new HashMapTable(_stateData, _currState, _currYear);
    _crime->generateSafetyScore();
    _hashCrime->computeSafetyScore(_answersToQuestions);
    _questionNumberLabel->setText(QString::fromStdString("Adjacency List Safety Score: " + to_string(_crime->_safetyScore)));
    _questionNumberLabel->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)-50, 300, 60);
    _questionLabel->setText(QString::fromStdString("Hash Table  Safety Score: " + to_string(_hashCrime->GetSafetyScore())));
    _questionLabel->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)-100, 300, 60);

    _outOf = new QLabel(QString::fromStdString("Safety scores are rated out of 100"), this);
    _outOf->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)+-175, 300, 60);
    _outOf->setAlignment(Qt::AlignCenter);
    _outOf->setWordWrap(true);
    _outOf->show();


    _recomendations1 = new QLabel(QString::fromStdString(GenerateRecommendations(_answersToQuestions)[0]), this);
    _recomendations1->setGeometry(((_windowWidth/2)-150), (_windowHeight/2), 300, 60);
    _recomendations1->setAlignment(Qt::AlignCenter);
    _recomendations1->setWordWrap(true);
    _recomendations1->show();

    _recomendations2 = new QLabel(QString::fromStdString(GenerateRecommendations(_answersToQuestions)[1]), this);
    _recomendations2->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)+100, 300, 60);
    _recomendations2->setAlignment(Qt::AlignCenter);
    _recomendations2->setWordWrap(true);
    _recomendations2->show();

    _restartButton->show();
}

void MainWindow::slotYearPicked() {
    _questionNumberLabel->setText(QString::fromStdString("Question " + std::to_string(_questionNumber+1)));
    _questionLabel->setText(QString::fromStdString(_questions[_questionNumber]));
    _currYear = stoi(_yearComboBox->currentText().toStdString());
    _yearComboBox->hide();
    _noButton->show();
    _yesButton->show();
}

void MainWindow::slotRestartClicked() {
    _questionNumber = 0;
    _questionNumberLabel->setText(QString::fromStdString("Question " + std::to_string(_questionNumber+1)));
    _questionNumberLabel->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)-150, 300, 60);

    _questionLabel->setText(QString::fromStdString(_questions[_questionNumber]));
    _questionLabel->setGeometry(((_windowWidth/2)-150), (_windowHeight/2)-100, 300, 60);

    _outOf->hide();
    _recomendations1->hide();
    _recomendations2->hide();

    _stateComboBox->show();
    _questionNumber ++;
}

