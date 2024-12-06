# GeneticCircuitMaker

This program simulates the gene expression of a simple genetic circuit. Users can input the activity levels of the promoter, activator, and repressor, and observe how the gene expression changes over a series of time steps. It also provides a graphical representation of gene expression over time.

Features

	1.	Simulates Gene Expression:
	•	Calculates the expression level of a gene based on the interactions between a promoter, activator, and repressor.
	2.	Time-Based Simulation:
	•	Gene expression is calculated at each time step, allowing users to see dynamic changes over time.
	3.	Graphical Output:
	•	Displays a simple graph of gene expression levels over time using * symbols for visualization.
	4.	User-Friendly Inputs:
	•	Promoter activity level, activator effect, and repressor effect can all be customized by the user.

Getting Started

Prerequisites

	•	A C++ compiler supporting at least C++11 (e.g., g++).

Compilation

To compile the program, use the following command:

g++ -std=c++11 -o genetic_circuit_simulation genetic_circuit_simulation.cpp

Running the Program

After compiling, run the program using:

./genetic_circuit_simulation

User Input

The program will prompt you to enter the following values:
	1.	Promoter Activity Level:
	•	A value between 0 and 1 representing the activity level of the promoter.
	•	Example: 0.6
	2.	Repressor Effect Level:
	•	A value between 0 and 1 representing the effect level of the repressor.
	•	Example: 0.3
	3.	Activator Effect Level:
	•	A value between 0 and 1 representing the effect level of the activator.
	•	Example: 0.5
	4.	Number of Time Steps:
	•	The total number of time steps over which the simulation will run.
	•	Example: 5

Understanding Time Steps

What is a Time Step?

A time step represents a single instance in time during the simulation. At each time step:
	•	The program calculates gene expression based on the current promoter activity, repressor effect, and activator effect.
	•	The dynamic changes (if any) to these components are applied, simulating real-life variations in gene regulation.

For example, if you input 5 time steps, the program will calculate gene expression five times, once for each time step, and display the results.

Example Interaction

Input:

Enter promoter activity level (0 to 1): 0.6
Enter repressor effect level (0 to 1): 0.3
Enter activator effect level (0 to 1): 0.5
Enter the number of time steps for simulation: 5

Output:

Time Step 1: Gene: GeneA | Expression Level: 80.00%
Time Step 2: Gene: GeneA | Expression Level: 81.26%
Time Step 3: Gene: GeneA | Expression Level: 79.83%
Time Step 4: Gene: GeneA | Expression Level: 78.47%
Time Step 5: Gene: GeneA | Expression Level: 80.08%

Expression Level Over Time (Graph):
Time Step | Expression (%)
---------------------------
        1 | **************************************** 80.00%
        2 | ***************************************** 81.26%
        3 | **************************************** 79.83%
        4 | *************************************** 78.47%
        5 | **************************************** 80.08%

How Gene Expression is Calculated

The formula used to calculate gene expression is:

Gene Expression = Promoter Activity + Activator Effect - Repressor Effect

Important Notes:

	1.	If the calculated expression level exceeds 1.0, it is clamped to 1.0.
	2.	If the calculated expression level is below 0.0, it is clamped to 0.0.

Additional Notes

	•	Graph Scaling: Each * symbol in the graph represents approximately 2% of the expression level, providing a simple visual representation of changes over time.
	•	Dynamic Behavior: The program simulates slight changes in the promoter, activator, and repressor activity levels over time using sine and cosine functions for realistic oscillations.

**This readme was generated my chatgpt**