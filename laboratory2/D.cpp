#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// variables for the pdf
const float T = 1;
const float dv = 0.001;
const int n_max = 100000;
const float f_pi = 3.1415925359f;


void Split(float const x, float& x_h, float& x_l) {
	auto c = static_cast<float>((1ul << 11) + 1ul);
	x_h = (c * x) + (x - (c * x));
	x_l = x - x_h;
}


void TwoMult(float a, float b, float& s, float& t) {
	float a_high, a_low, b_high, b_low;
	Split(a, a_high, a_low);
	Split(b, b_high, b_low);
	s = a * b;
	t = -s + a_high * b_high;
	t += a_high * b_low;
	t += a_low * b_high;
	t += a_low * b_low;
}


float mean(float arr[], float dv, unsigned size, float& error) {
	float sum = 0;
	float c = 0;
	for (int i = 0; i < size; i++) {
		float y = arr[i] - c;
		float t = sum + y;
		c = (t - sum) - y;
		sum = t;
	}
	error = c;
	return sum * dv;
}


int main() {
	// setting precision
	cout << setprecision(10) << fixed;


	// creating maxwell's pdf and setting psi = ...
	float* pdf = new float[2 * n_max];
	float* psi = new float[2 * n_max];

	// big and tiny are arrays for different terms of psi*pdf
	float* big = new float[2 * n_max];
	float* tiny = new float[2 * n_max];

	for (int i = 0; i < 2 * n_max; i++) {
		float x = i * dv + dv / 2 - n_max * dv;
		pdf[i] = exp(-x * x / T) / sqrt(f_pi * T);
		psi[i] = abs(x);
		TwoMult(pdf[i], psi[i], big[i], tiny[i]);
	}

	
	float big_error, small_error;
	float big_part = mean(big, dv, 2 * n_max, big_error);
	float small_part = mean(tiny, dv, 2 * n_max, small_error);
	cout << "sum = " << big_part + small_part + big_error << endl;
	cout << "big part = " << big_part << endl;
	cout << "big error = " << big_error << endl;
	cout << "small part = " << small_error << endl;

	// оно какое-то странное и хуже чем надо
}