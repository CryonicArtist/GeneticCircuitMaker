#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

enum ComponentType { PROMOTER, REPRESSOR, ACTIVATOR, GENE };

// Component struct representing each element in the circuit
struct Component {
    string name;
    ComponentType type;
    double activityLevel; // 0 to 1 for promoters, effect level for activators/repressors
};

// Function to apply activators and repressors on a promoter
double calculateGeneExpression(double promoterActivity, const vector<Component>& regulators) {
    double finalActivity = promoterActivity;
    
    // Loop through each regulator and adjust the promoter's activity
    for (const auto& regulator : regulators) {
        if (regulator.type == ACTIVATOR) {
            finalActivity += regulator.activityLevel;  // Increase promoter activity
        } else if (regulator.type == REPRESSOR) {
            finalActivity -= regulator.activityLevel;  // Decrease promoter activity
        }
    }

    // Clamp the activity level between 0 and 1
    if (finalActivity > 1.0) finalActivity = 1.0;
    if (finalActivity < 0.0) finalActivity = 0.0;

    return finalActivity;
}

// Main function to simulate the genetic circuit
void simulateCircuit(const vector<Component>& circuit) {
    map<string, double> geneExpression;  // Map to store gene expression levels

    for (const auto& component : circuit) {
        if (component.type == GENE) {
            // Find the corresponding promoter and regulators
            double promoterActivity = 0.0;
            vector<Component> regulators;

            for (const auto& comp : circuit) {
                if (comp.name == component.name && comp.type == PROMOTER) {
                    promoterActivity = comp.activityLevel;
                } else if (comp.name == component.name && (comp.type == ACTIVATOR || comp.type == REPRESSOR)) {
                    regulators.push_back(comp);
                }
            }

            // Calculate gene expression based on promoter activity and regulators
            double expressionLevel = calculateGeneExpression(promoterActivity, regulators);
            geneExpression[component.name] = expressionLevel;
        }
    }

    // Output the results
    for (const auto& gene : geneExpression) {
        cout << "Gene: " << gene.first << " | Expression Level: " << gene.second * 100 << "%" << endl;
    }
}

int main() {
    // Example circuit
    vector<Component> circuit = {
        {"GeneA", PROMOTER, 0.6},
        {"GeneA", REPRESSOR, 0.5},
        {"GeneA", ACTIVATOR, 0.5},
        {"GeneA", GENE, 0.0},
        
        {"GeneB", PROMOTER, 0.8},
        {"GeneB", REPRESSOR, 0.8},
        {"GeneB", ACTIVATOR, 0.8},
        {"GeneB", GENE, 0.0},
    };

    // Simulate the genetic circuit
    simulateCircuit(circuit);

    return 0;
}