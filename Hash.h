#include "StateInfo.h"
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class HashMapTable {
  /*std::map<std::pair<std::string, int>, StateInfo *> &data) */

  unordered_map<int, double> hashMap;
  int bucketSize;
  double safetyScore;

public:
  // inserting the elements into the hash table
  HashMapTable(map<pair<string, int>, StateInfo *> &dataToStore, string state, int year);

  // computing our safety score
  double computeSafetyScore(vector<bool> userAnswers);

  // retrieving the safety score
  double GetSafetyScore() { return safetyScore; }

    std::string currState;
    int currYear;
};
