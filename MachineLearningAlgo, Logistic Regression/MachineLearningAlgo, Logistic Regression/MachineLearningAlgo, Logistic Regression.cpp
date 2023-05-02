#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

struct DataPoint {
    vector<double> features;
    int label;
};

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

double predict(const vector<double>& features, const vector<double>& weights) {
    double z = 0.0;
    for (int i = 0; i < features.size(); i++) {
        z += features[i] * weights[i];
    }
    return sigmoid(z);
}

vector<double> trainLogisticRegression(const vector<DataPoint>& data, int numIterations, double learningRate) {
    vector<double> weights(data[0].features.size(), 0.0);
    for (int i = 0; i < numIterations; i++) {
        for (int j = 0; j < data.size(); j++) {
            double predicted = predict(data[j].features, weights);
            double error = data[j].label - predicted;
            for (int k = 0; k < weights.size(); k++) {
                weights[k] += learningRate * error * data[j].features[k];
            }
        }
    }
    return weights;
}

int main() {
    // Define the input data and labels
    vector<DataPoint> data = {
        {{2.0, 3.0}, 0},
        {{5.0, 4.0}, 0},
        {{3.0, 1.0}, 1},
        {{6.0, 3.0}, 1},
    };

    // Train a logistic regression model on the data
    int numIterations = 1000;
    double learningRate = 0.01;
    vector<double> weights = trainLogisticRegression(data, numIterations, learningRate);

    // Predict the label of a new data point
    vector<double> features = { 4.0, 2.0 };
    double probability = predict(features, weights);
    int label = (probability >= 0.5) ? 1 : 0;
    cout << "Predicted label: " << label << endl;

    return 0;
}
