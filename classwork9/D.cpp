#include <iostream>
using namespace std;

struct denom_array_t {
	unsigned int* arr;
	unsigned int sz;

	denom_array_t() {
		arr = nullptr;
		sz = 0;
	}

	void add(unsigned int value) {
		// i just create a new array, rewrite most of it, and delete the old one
		if (sz != 0) {
			sz++;
			unsigned int* new_arr = new unsigned int[sz];
			for (int i = 0; i < sz - 1; i++) new_arr[i] = arr[i];
			new_arr[sz - 1] = value;
			delete[] arr;
			arr = new_arr;
		}
		if (sz == 0) {
			arr = new unsigned int[1];
			arr[0] = value;
			sz++;
		}
	}

	void free_memory() {
		delete[] arr;
	}

	void print() {
		for (int i = 0; i < sz; i++) {
			cout << arr[i];
			if (i != sz - 1) cout << " ";
		}
	}
};

denom_array_t egyptian_fractions(unsigned int num, unsigned int den) {
	int p = num, q = den;

	// assuming p <= q
	denom_array_t ans;
	while (p > 0) {
		int x = 0;
		while (q > p * x) x++;

		int new_p = p * x - q;
		int new_q = q * x;
		p = new_p;
		q = new_q;
		for (int i = 2; i <= p; i++) {
			while ((p % i == 0) && (q % i == 0)) {
				p = p / i;
				q = q / i;
			}
		}
		ans.add(x);
	}

	return ans;
}



int main() {
	int p, q;
	cin >> p >> q;
	egyptian_fractions(p, q).print();
}