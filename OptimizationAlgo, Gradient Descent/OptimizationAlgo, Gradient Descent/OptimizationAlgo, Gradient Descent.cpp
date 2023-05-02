#include <iostream>
#include <vector>
using namespace std;

// Define the cost function
double costFunction(double x, double y) {
    return pow(x, 2) + pow(y, 2);
}

// Calculate the gradient of the cost function
vector<double> gradient(double x, double y) {
    vector<double> grad;
    grad.push_back(2 * x);
    grad.push_back(2 * y);
    return grad;
}

// Perform gradient descent to optimize the cost function
void gradientDescent(double x, double y, double alpha, int numIterations) {
    for (int i = 0; i < numIterations; i++) {
        vector<double> grad = gradient(x, y);
        x -= alpha * grad[0];
        y -= alpha * grad[1];
        cout << "Iteration " << i << ": x = " << x << ", y = " << y << endl;
    }
}

int main() {
    double x = 1.0;
    double y = 2.0;
    double alpha = 0.1;
    int numIterations = 10;
    gradientDescent(x, y, alpha, numIterations);
    return 0;
}
