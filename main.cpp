#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define types of genetic circuit components
enum ComponentType { PROMOTER, REPRESSOR, ACTIVATOR, GENE };

// Component struct representing each element in the circuit
struct Component {
    string name;
    ComponentType type;
    double activityLevel;  // 0 to 1 for promoters, effect level for activators/repressors
    string targetGene;     // For regulators, the gene they affect
};

// Function to apply activators and repressors to a promoter
double calculateGeneExpression(double promoterActivity, const vector<Component>& regulators) {
    double finalActivity = promoterActivity;

    for (const auto& regulator : regulators) {
        if (regulator.type == ACTIVATOR) {
            finalActivity += regulator.activityLevel;  // Increase promoter activity
        } else if (regulator.type == REPRESSOR) {
            finalActivity -= regulator.activityLevel;  // Decrease promoter activity
        }
    }

    // Clamp the activity level between 0 and 1
    return max(0.0, min(1.0, finalActivity));
}

// Function to dynamically input a genetic circuit
vector<Component> inputCircuit() {
    vector<Component> circuit;
    int numComponents;

    cout << "Enter the number of components in the circuit: ";
    cin >> numComponents;

    for (int i = 0; i < numComponents; ++i) {
        Component component;
        string type;

        cout << "\nComponent " << (i + 1) << ":\n";
        cout << "Name: ";
        cin >> component.name;

        cout << "Type (PROMOTER, ACTIVATOR, REPRESSOR, GENE): ";
        cin >> type;

        if (type == "PROMOTER") component.type = PROMOTER;
        else if (type == "ACTIVATOR") component.type = ACTIVATOR;
        else if (type == "REPRESSOR") component.type = REPRESSOR;
        else if (type == "GENE") component.type = GENE;
        else {
            cout << "Invalid type. Skipping component.\n";
            continue;
        }

        cout << "Activity Level (0 to 1): ";
        cin >> component.activityLevel;

        if (component.type != GENE) {
            cout << "Target Gene: ";
            cin >> component.targetGene;
        }

        circuit.push_back(component);
    }

    return circuit;
}

// Function to simulate the circuit over time
void simulateCircuit(const vector<Component>& circuit, int timeSteps) {
    map<string, double> geneExpression;  // Map to store gene expression levels

    // Initialize gene expression levels
    for (const auto& component : circuit) {
        if (component.type == GENE) {
            geneExpression[component.name] = 0.0;
        }
    }

    // Simulate over time
    for (int t = 0; t < timeSteps; ++t) {
        map<string, double> newGeneExpression = geneExpression;

        for (const auto& gene : geneExpression) {
            double promoterActivity = 0.0;
            vector<Component> regulators;

            // Find the promoter and regulators for this gene
            for (const auto& component : circuit) {
                if (component.targetGene == gene.first) {
                    if (component.type == PROMOTER) {
                        promoterActivity = component.activityLevel;
                    } else if (component.type == ACTIVATOR || component.type == REPRESSOR) {
                        regulators.push_back(component);
                    }
                }
            }

            // Calculate new gene expression level
            newGeneExpression[gene.first] = calculateGeneExpression(promoterActivity, regulators);
        }

        // Update gene expression levels
        geneExpression = newGeneExpression;

        // Output current state
        cout << "Time Step " << (t + 1) << ":\n";
        for (const auto& gene : geneExpression) {
            cout << "  Gene " << gene.first << ": " << fixed << setprecision(2) << gene.second * 100 << "%\n";
        }
    }
}

int main() {
    // Step 1: Input the genetic circuit
    cout << "Welcome to the Genetic Circuit Simulator!\n";
    auto circuit = inputCircuit();

    // Step 2: Input simulation parameters
    int timeSteps;
    cout << "\nEnter the number of time steps for simulation: ";
    cin >> timeSteps;

    // Step 3: Simulate the circuit
    simulateCircuit(circuit, timeSteps);

    return 0;
}
