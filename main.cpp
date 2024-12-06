#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <cmath>   

using namespace std;

// Define types of genetic circuit components
enum ComponentType { PROMOTER, REPRESSOR, ACTIVATOR, GENE };

// Component struct representing each element in the circuit
struct Component {
    string name;
    ComponentType type;
    double activityLevel; // 0 to 1 for promoters, effect level for activators/repressors
};

// Function to calculate gene expression
double calculateGeneExpression(double promoterActivity, double activatorEffect, double repressorEffect) {
    double finalActivity = promoterActivity + activatorEffect - repressorEffect;

    // Clamp the activity level between 0 and 1
    if (finalActivity > 1.0) finalActivity = 1.0;
    if (finalActivity < 0.0) finalActivity = 0.0;

    return finalActivity;
}

// print the expression-per-time graph
void printExpressionGraph(const vector<double>& expressionLevels) {
    cout << "\nExpression Level Over Time (Graph):\n";
    cout << "Time Step | Expression (%)\n";
    cout << "---------------------------\n";

    for (size_t i = 0; i < expressionLevels.size(); i++) {
        cout << setw(9) << i + 1 << " | ";
        int barLength = static_cast<int>(expressionLevels[i] * 50); // Scale bar length for display
        cout << string(barLength, '*') << " " << fixed << setprecision(2) << expressionLevels[i] * 100 << "%" << endl;
    }
}

int main() {
    Component promoter = {"GeneA", PROMOTER, 0.0};
    Component repressor = {"GeneA", REPRESSOR, 0.0};
    Component activator = {"GeneA", ACTIVATOR, 0.0};
    Component gene = {"GeneA", GENE, 1.0}; // Default gene activity level is set to 1.0

    // Get user inputs for promoter, repressor, and activator activity levels
    cout << "Enter promoter activity level (0 to 1): ";
    cin >> promoter.activityLevel;

    cout << "Enter repressor effect level (0 to 1): ";
    cin >> repressor.activityLevel;

    cout << "Enter activator effect level (0 to 1): ";
    cin >> activator.activityLevel;

    // Get the number of time steps
    int timeSteps;
    cout << "Enter the number of time steps for simulation: ";
    cin >> timeSteps;

    vector<double> expressionLevels; // To store expression levels at each time step

    // Simulate gene expression over time
    for (int t = 0; t < timeSteps; t++) {
        // Simulate slight changes over time (optional dynamic behavior, adjust if needed)
        double dynamicPromoter = promoter.activityLevel * (1 + 0.1 * sin(t)); // Adding variability to promoter
        double dynamicRepressor = repressor.activityLevel * (1 + 0.05 * cos(t));
        double dynamicActivator = activator.activityLevel * (1 + 0.05 * sin(t));

        // Calculate gene expression
        double expressionLevel = calculateGeneExpression(dynamicPromoter, dynamicActivator, dynamicRepressor);
        expressionLevels.push_back(expressionLevel);

        // Output the expression level at each time step
        cout << "Time Step " << t + 1 << ": Gene: " << gene.name 
             << " | Expression Level: " << fixed << setprecision(2) 
             << expressionLevel * 100 << "%" << endl;
    }

    printExpressionGraph(expressionLevels);

    return 0;
}