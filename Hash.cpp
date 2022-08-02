#include "Hash.h"

HashMapTable::HashMapTable(map<pair<string, int>, StateInfo *> &dataToStore, string state, int year) {

    currState = state;
    currYear = year;

  // need to store the titles of the crime as an int index for the unordered map
  // and then it's values will be stored as a double into the hashMap
    /*
   * The vertexes in the graph will be:
   * 0: propertyAll
   * 1: propertyBurglary
   * 2: propertyLarceny
   * 3: propertyMotor
   * 4: violentAll
   * 5: violentAssault
   * 6: violentMurder
   * 7: violentRape
   * 8: violentRobbery
   */
  StateInfo *temp = dataToStore.find({currState, currYear})->second;
    //double scaleDown = temp->_percentPopCrime / 100;

    double weight = .265;
    hashMap.insert({0,weight * temp->_percentPopProperty});
    hashMap.insert({1,weight * temp->_percentPopBurglary});
    hashMap.insert({2,weight * temp->_percentPopLarceny});
    hashMap.insert({3,weight * temp->_percentPopMotor});
    hashMap.insert({4,weight * temp->_percentPopViolent});
    hashMap.insert({5,weight * temp->_percentPopAssault});
    hashMap.insert({6,weight * temp->_percentPopMurder});
    hashMap.insert({7,weight * temp->_percentPopRape});
    hashMap.insert({8,weight * temp->_percentPopRobbery});

    // initializing safety score
    safetyScore = 0;
}

double HashMapTable::computeSafetyScore(vector<bool> userAnswers) {
    // takes in the answers and then calculates the safety score based on their
    // choices

    double sum = 0;

    for (int i = 2; i < userAnswers.size(); i++)
    {
        if (i == 2 && userAnswers.at(i) == 1)//larceny
            hashMap.at(2) *= 4.0;

        else if (i == 3 && userAnswers.at(i) == 1)//motor
            hashMap.at(3) *= 5.0;

        else if (i == 4 && userAnswers.at(i) == 1)//property
            hashMap.at(0) *= 4.0;

        else if (i == 5 && userAnswers.at(i) == 1)//burglary
            hashMap.at(1) *= 4.0;

        else if (i == 6 && userAnswers.at(i) == 1)//assault
            hashMap.at(5) += 10.0;

        else if (i == 7 && userAnswers.at(i) == 1)//violent
            hashMap.at(4) += 15.0;

    }

    for(int j = 0; j < 6; j++)
    {
        sum += hashMap.at(j);
    }

    //additional points to overall score
    if(userAnswers[8] == 1)
        sum += 10.0;
    if(userAnswers[9] == 1)
        sum += 20;
    if(userAnswers[10] == 1)
        sum *= 1.3;

    safetyScore = 100 - sum;

    return safetyScore;
}
