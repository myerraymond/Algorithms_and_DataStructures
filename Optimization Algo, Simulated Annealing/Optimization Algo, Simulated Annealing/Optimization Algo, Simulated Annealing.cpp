#include <iostream>
#include <cmath>
#include <random>
using namespace std;

// Define the objective function
double objectiveFunction(double x) {
    return pow(x, 2) + 10 * sin(x);
}

// Perform simulated annealing to optimize the objective function
void simulatedAnnealing(double x, double T, double coolingRate, int numIterations) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-10, 10);
    for (int i = 0; i < numIterations; i++) {
        double x_new = dis(gen);
        double deltaE = objectiveFunction(x_new) - objectiveFunction(x);
        if (deltaE < 0) {
            x = x_new;
        }
        else {
            double acceptanceProb = exp(-deltaE / T);
            uniform_real_distribution<> dis2(0, 1);
            double randNum = dis2(gen);
            if (randNum < acceptanceProb) {
                x = x_new;
            }
        }
        T *= coolingRate;
        cout << "Iteration " << i << ": x = " << x << ", f(x) = " << objectiveFunction(x) << ", T = " << T << endl;
    }
}

int main() {
    double x = 0.0;
    double T = 100.0;
    double coolingRate = 0.99;
    int numIterations = 100;
    simulatedAnnealing(x, T, coolingRate, numIterations);
    return 0;
}
