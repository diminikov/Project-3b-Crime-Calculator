#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H

using namespace std;

class Graph
{
protected:
    vector<vector<pair<int,double>>> _adjList;

public:
    void insertEdge(int from, int to, double weight);
    void setWeight(int from, double weight);
    bool isEdge(int from, int to);
    double sumEdge(int from, int to);
    double getWeight(int from, int to);
    vector<int> getAdjacent(int vertex);
    vector<vector<pair<int,double>>> getAdjList();
};



#endif //PROJECT3_GRAPH_H
