#include <iostream>

using namespace std;

double dotProduct(double x[], double w[]) {	
	double product = 0;
	for (int i = 0; i < 3; i++)
		product += x[i]*w[i];
	return product;
};

void updateWeights(double *w, double x[], double eta, double error) {
	for (int i = 0; i < 3; i++)
		w[i] += eta * error * x[i];
};

double calculateError(double y, double result) {
	return y - result;
};

int makePrediction(double result, double th) {
	int prediction;
	if (result > th)
		prediction = 1;
	else 
		prediction = 0;

	return prediction;
};

int main() {
	// Training data
	double x[4][3] = { 
		{0,0,1},
		{0,1,1},
		{1,0,1},
		{1,1,1}};

	// Labels
	double y[4] = {0, 1, 1, 1};	
	// Weights
	double w[3] = {0.5, 0.5, 0.5};

	// Number epochs
	int epochs = 10;
	// Learning rate
	double eta = 0.1;
	// Cut-off
	double th = 0.5;
	double error;

	for (int i = 0; i < epochs; i++) {
		// iterate over all training samples		
		for (int n = 0; n < 4; n++) {
			// Dot product between weights and training sample
			double result =  dotProduct(x[n], w); 

			// calculate error
			double error = calculateError(y[n], result);
			
			// update weights		
			updateWeights(w, x[n], eta, error);
		};
		cout << error << endl;
	};

	// Prediction
	for (int n = 0; n < 4; n++) {
		double result = dotProduct(x[n], w);
		int prediction = makePrediction(result, th);

		cout << y[n] << " - " << prediction << endl;
	};

	return 0;
}
