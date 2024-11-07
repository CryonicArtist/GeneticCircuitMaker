#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

enum ComponentType { PROMOTER, REPRESSOR, ACTIVATOR, GENE};

struct Component {
    string name;
    ComponentType;
    double activityLevel
}

double calculateGeneExpression(double promoterActivity, const vector<Component>& regulators){
    double finalActivity;
}