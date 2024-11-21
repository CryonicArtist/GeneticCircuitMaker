#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Define types of genetic circuit components
enum ComponentType { PROMOTER, REPRESSOR, ACTIVATOR, GENE };

// Component struct representing each element in the circuit
struct Component {
    string name;
    ComponentType type;
    double activityLevel;
    string id;
};

// Genetic Circuit class
class GeneticCircuit {
public:
    void addComponent(const Component& component) {
        components.push_back(component);
    }

    void simulate() {
        map<string, double> geneExpression;
        for (const auto& component : components) {
            if (component.type == GENE) {
                double promoterActivity = getPromoterActivity(component.name);
                vector<Component> regulators = getRegulators(component.name);
                double expressionLevel = calculateGeneExpression(promoterActivity, regulators);
                geneExpression[component.name] = expressionLevel;
            }
        }

        // Output results
        for (const auto& gene : geneExpression) {
            cout << "Gene: " << gene.first 
                 << " | Expression Level: " << gene.second * 100 << "%" << endl;
        }
    }

private:
    vector<Component> components;

    double getPromoterActivity(const string& geneName) {
        for (const auto& comp : components) {
            if (comp.name == geneName && comp.type == PROMOTER) {
                return comp.activityLevel;
            }
        }
        return 0.0;
    }

    vector<Component> getRegulators(const string& geneName) {
        vector<Component> regulators;
        for (const auto& comp : components) {
            if (comp.name == geneName && (comp.type == ACTIVATOR || comp.type == REPRESSOR)) {
                regulators.push_back(comp);
            }
        }
        return regulators;
    }

    double calculateGeneExpression(double promoterActivity, const vector<Component>& regulators) {
        double finalActivity = promoterActivity;
        for (const auto& regulator : regulators) {
            if (regulator.type == ACTIVATOR) {
                finalActivity += regulator.activityLevel;
            } else if (regulator.type == REPRESSOR) {
                finalActivity -= regulator.activityLevel;
            }
        }
        return std::clamp(finalActivity, 0.0, 1.0);  // Set the activity level
    }
};

int main() {
    GeneticCircuit circuit;
    circuit.addComponent({"GeneA", PROMOTER, 0.6, "GeneA_Promoter"});
    circuit.addComponent({"GeneA", REPRESSOR, 0.3, "GeneA_Repressor"});
    circuit.addComponent({"GeneA", ACTIVATOR, 0.5, "GeneA_Activator"});
    circuit.addComponent({"GeneA", GENE, 0.0, "GeneA_Gene"});

    circuit.addComponent({"GeneB", PROMOTER, 0.8, "GeneB_Promoter"});
    circuit.addComponent({"GeneB", REPRESSOR, 0.4, "GeneB_Repressor"});
    circuit.addComponent({"GeneB", GENE, 0.0, "GeneB_Gene"});


    circuit.simulate();

    return 0;
}