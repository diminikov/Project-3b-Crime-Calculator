#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

#ifndef CRIMECALCULATORGUI_STATEINFO_H
#define CRIMECALCULATORGUI_STATEINFO_H
struct StateInfo
{
    int _dataPopulation;
    double _propertyAll;
    double _propertyBurglary;
    double _propertyLarceny;
    double _propertyMotor;
    double _violentAll;
    double _violentAssault;
    double _violentMurder;
    double _violentRape;
    double _violentRobbery;
    int _populationAffectedByCrime;
    double _percentPopProperty;
    double _percentPopBurglary;
    double _percentPopLarceny;
    double _percentPopMotor;
    double _percentPopViolent;
    double _percentPopAssault;
    double _percentPopMurder;
    double _percentPopRape;
    double _percentPopRobbery;
    double _percentPopCrime;

    StateInfo(int dataPopulation, double propertyAll, double propertyBurglary, double propertyLarceny, double propertyMotor, double violentAll, double violentAssault,
              double violentMurder, double violentRape, double violentRobbery, int populationAffectedByCrime, double percentPopProperty, double percentPopBurglary, double percentPopLarceny, double percentPopMotor,
              double percentPopViolent, double percentPopAssault, double percentPopMurder, double percentPopRape, double percentPopRobbery, double percentPopCrime)
    {
        _dataPopulation = dataPopulation;
        _propertyAll = propertyAll;
        _propertyBurglary = propertyBurglary;
        _propertyLarceny = propertyLarceny;
        _propertyMotor = propertyMotor;
        _violentAll = violentAll;
        _violentAssault = violentAssault;
        _violentMurder = violentMurder;
        _violentRape = violentRape;
        _violentRobbery = violentRobbery;
        _populationAffectedByCrime = populationAffectedByCrime;
        _percentPopProperty = percentPopProperty;
        _percentPopBurglary = percentPopBurglary;
        _percentPopLarceny = percentPopLarceny;
        _percentPopMotor = percentPopMotor;
        _percentPopViolent = percentPopViolent;
        _percentPopAssault = percentPopAssault;
        _percentPopMurder = percentPopMurder;
        _percentPopRape = percentPopRape;
        _percentPopRobbery = percentPopRobbery;
        _percentPopCrime = percentPopCrime;
    }
};


#endif //CRIMECALCULATORGUI_STATEINFO_H
