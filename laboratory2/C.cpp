#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// variables for the pdf
const float T = 1;
const float dv = 0.001;
const int n_max = 100000;
const float f_pi = 3.1415925359f;


float mean(float psi[], float pdf[], float dv, unsigned size) {
	float sum = 0;
	float c = 0;
	for (int i = 0; i < size; i++) {
		float y = pdf[i] * psi[i] - c;
		float t = sum + y;
		c = (t - sum) - y;
		sum = t;
	}
	return sum*dv;
}


int main() {
	// setting precision
	cout << setprecision(10) << fixed;


	// creating maxwell's pdf and setting psi = ...
	float* pdf = new float[2 * n_max];
	float* psi = new float[2 * n_max];
	for (int i = 0; i < 2 * n_max; i++) {
		float x = i * dv + dv / 2 - n_max * dv;
		pdf[i] = exp(-x * x / T) / sqrt(f_pi * T);
		psi[i] = abs(x);
	}

	// multiplying by 2 since i only integrate over positive x
	cout << mean(pdf, psi, dv, 2 * n_max);

}