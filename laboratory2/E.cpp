#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// variables for the pdf
const double T = 1;
const double dv = 0.001;
const int n_max = 100000;
const double f_pi = 3.1415925359f;


float mean(double psi[], double pdf[], double dv, unsigned size) {
	double sum = 0;
	double c = 0;
	for (int i = 0; i < size; i++) {
		double y = pdf[i] * psi[i] - c;
		double t = sum + y;
		c = (t - sum) - y;
		sum = t;
	}
	return sum * dv;
}


int main() {
	// setting precision
	cout << setprecision(10) << fixed;


	// creating maxwell's pdf and setting psi = ...
	double* pdf = new double[2 * n_max];
	double* psi = new double[2 * n_max];
	for (int i = 0; i < 2 * n_max; i++) {
		double x = i * dv + dv / 2 - n_max * dv;
		pdf[i] = exp(-x * x / T) / sqrt(f_pi * T);
		psi[i] = abs(x);
	}

	// multiplying by 2 since i only integrate over positive x
	cout << mean(pdf, psi, dv, 2 * n_max);

	// тоже почему-то не сильно лучше чем float
}