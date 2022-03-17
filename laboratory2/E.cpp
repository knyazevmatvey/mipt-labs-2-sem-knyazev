#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// variables for the pdf
const double T = 1;
const double dv = 0.001;
const int n_max = 100000;
const double d_pi = 3.1415925359;


float sum(double psi[], double pdf[], unsigned size) {
	if (size == 0) return 0;
	if (size == 1) return psi[0] * pdf[0];
	int new_size = size / 2;
	double sum_1 = sum(psi, pdf, new_size);
	for (int i = 0; i < new_size; i++) {
		pdf++;
		psi++;
	}
	double sum_2 = sum(psi, pdf, size - new_size);
	return sum_1 + sum_2;
}


float mean(double psi[], double pdf[], double dv, unsigned size) {
	return sum(psi, pdf, size) * dv;
}


int main() {
	// setting precision
	cout << setprecision(10) << fixed;


	// creating maxwell's pdf and setting psi = ...
	// (
	double* pdf = new double[2 * n_max];
	double* psi = new double[2 * n_max];
	for (int i = 0; i < 2 * n_max; i++) {
		double x = i * dv + dv / 2 - n_max * dv;
		pdf[i] = exp(-x * x / T) / sqrt(d_pi * T);
		psi[i] = abs(x);
	}

	// multiplying by 2 since i only integrate over positive x
	cout << mean(pdf, psi, dv, 2 * n_max);

}