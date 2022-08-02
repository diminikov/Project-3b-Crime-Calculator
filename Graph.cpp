//
// Created by Dimitri on 7/31/2022.
//

#include "Graph.h"

// insertEdge() adds an edge between from and to with a specified weight
void Graph::insertEdge(int from, int to, double weight)
{
    if(from+1 > _adjList.size()){
        _adjList.resize(from+1);
    }
    if(to+1 > _adjList.size()){
        _adjList.resize(to+1);
    }
    _adjList[from].push_back({to,weight});
}

//isEdge() returns a boolean indicating true if there is an edge between the from and to vertex
bool Graph::isEdge(int from, int to)
{
    for(auto i : _adjList[from]) {
        if(i.first == to)
            return true;
    }


    return false;
}

//sumEdge() returns the sum of weights of all edge connecting the from and to vertex. Returns 0 if no edge connect the two vertices.
double Graph::sumEdge(int from, int to)
{
    double sum = 0;
    if(from == to){
        for(auto i : _adjList[from]) {
            if(i.first == to)
                sum += i.second;
        }
    }else{
        for(auto i : _adjList[from]) {
            if(i.first == to)
                sum += i.second;
        }
        for(auto i : _adjList[to]) {
            if(i.first == from)
                sum += i.second;
        }
    }
    return sum;
}

//getWeight() returns a sorted vector containing all weights of the edges connecting the from and to vertex
double Graph::getWeight(int from, int to)
{
    for(auto i : _adjList[from]){
        if(i.first == to)
            return i.second;
    }
}

//getAdjacent() returns a vector with all adjacent vertexes
vector<int> Graph::getAdjacent(int vertex)
{
    vector<int> adj;
    for(auto i : _adjList[vertex])
        adj.push_back(i.first);
    return adj;
}

vector<vector<pair<int, double>>> Graph::getAdjList() {
    return _adjList;
}

void Graph::setWeight(int from, double weight) {
    for(int i = 0; i < _adjList.size(); i++){
        for(int j = 0; j < _adjList[i].size(); j++){
            if(_adjList[i][j].first == from || i == from)
                _adjList[i][j].second = weight;
        }
    }
}
