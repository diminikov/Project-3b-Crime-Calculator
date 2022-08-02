#include "Graph.h"

#ifndef PROJECT3_CRIMEGRAPH_H
#define PROJECT3_CRIMEGRAPH_H


class CrimeGraph : public Graph{
public:
    double _safetyScore;
    CrimeGraph(double defaultWeight);
    CrimeGraph();
    double generateSafetyScore();
    double getSafetyScore();
    void printGraph();
};


#endif //PROJECT3_CRIMEGRAPH_H
