#include <QApplication>
#include <QScreen>
#include <QPushButton>
#include <QLabel>
#include "CrimeGraph.h"
#include "MainWindow.h"
#include <map>
#include <vector>
#include "StateInfo.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MainWindow window;

    window._questions.emplace(window._questions.end(),"Do you commonly use a car as a means of transportation?");
    window._questions.emplace(window._questions.end(),"If you own a car or motorcycle, do you keep it outside? If you don't own either, answer no.");
    window._questions.emplace(window._questions.end(),"Do you go to the gas station at night?");
    window._questions.emplace(window._questions.end(),"Do you consistently keep the doors to your residency unlocked and the windows open?");
    window._questions.emplace(window._questions.end(),"Do you work in person?");
    window._questions.emplace(window._questions.end(),"Do you allow individuals you recently met into your place of residency?");
    window._questions.emplace(window._questions.end(),"Do you stay out past dark on a consistent basis?");
    window._questions.emplace(window._questions.end(),"Do you use drugs or alcohol at social events on a regular basis?");
    window._questions.emplace(window._questions.end(),"When you go out, do you go alone?");

    // use both data structures


    // generate Recommendations
    /* int numberOfRecommendations = GenerateRecommendations(answersToQuestions);
    if (numberOfRecommendations == 0)
        std::cout << "Your common weekly activity is at a low risk of crime.. keep doing what you're doing!";*/
    window.show();
    return a.exec();
}
