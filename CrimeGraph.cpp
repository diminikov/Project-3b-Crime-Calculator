#include <algorithm>
#include "CrimeGraph.h"
#include <set>

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
CrimeGraph::CrimeGraph(double defaultWeight) {
    for(int i = 0; i < 9; i++) {
        for(int j = 8; j > i; j--) {
            insertEdge(i,j,defaultWeight);
        }
    }
    _safetyScore = 0;
}

CrimeGraph::CrimeGraph() {
    for(int i = 0; i < 9; i++) {
        for(int j = 8; j > i; j--) {
            insertEdge(i,j,10);
        }
    }
    _safetyScore = 0;
}

bool sortFunction(pair<int,pair<int,double>> i, pair<int,pair<int,double>> j){
    return i.second.second < j.second.second;
}

void mergeSet(set<int>* v, set<int>* u){
    v->insert(u->begin(),u->end());
}

double CrimeGraph::generateSafetyScore() {
    vector<pair<int,pair<int,double>>> edges;
    vector<pair<int,pair<int,double>>> mst;
    for(int i = 0; i < _adjList.size(); i++) {
        for (int j = 0; j < _adjList[i].size(); j++) {
            edges.push_back({i, {_adjList[i][j].first, _adjList[i][j].second}});
        }
    }

    sort(edges.begin(),edges.end(), sortFunction);

    unordered_map<int,set<int>*> sets;
    for(int i = 0; i < _adjList.size(); i++){
        sets.insert({i,new set<int>});
        sets.find(i)->second->insert(i);
    }

    for(auto i : edges){
        if(sets.find(i.second.first) != sets.end() && sets.find(i.first) != sets.end()) {
            if (sets.find(i.first)->second->find(i.second.first) == sets.find(i.first)->second->end()) {
                mergeSet(sets.find(i.first)->second, sets.find(i.second.first)->second);
                set<int> *temp = sets.find(i.second.first)->second;
                sets.erase(i.second.first);
                delete (temp);
                mst.push_back({i.first,{i.second.first,i.second.second}});
            }
        }
    }

    double sum = 0;
    for(auto i : mst){
        sum += i.second.second;
    }

    sum = sum/9;

    _safetyScore = 100 - sum;
    return _safetyScore;
}

double CrimeGraph::getSafetyScore() {
    return _safetyScore;
}

void CrimeGraph::printGraph() {
    for(int i = 0; i < _adjList.size(); i++){
        for(auto j : _adjList[i]){
            std::cout << i << " - " << j.first << " : " << j.second << endl;
        }
    }
}
