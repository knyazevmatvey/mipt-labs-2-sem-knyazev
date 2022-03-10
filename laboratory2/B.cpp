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
	int step = 1;
	float* x = new float[size];
	for (int i = 0; i < size; i++) x[i] = psi[i] * pdf[i];
	while (step < size) {
		int i = 0;
		while ((i + 2) * step < size) {
			x[i * step] += x[(i + 1) * step];
			i++;
		}
		if ((i + 1) * step < size) x[i * step] += x[(i + 1) * step];
		step *= 2;
	}
	return x[0] * dv;
}


int main() {
	// setting precision
	cout << setprecision(10) << fixed;


	// creating maxwell's pdf and setting psi = ...
	// (
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