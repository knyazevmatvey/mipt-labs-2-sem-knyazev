#include <iostream>
using namespace std;

int digit(long long int x, int pos) {
	// returns digit at pos from the right (if pos == 0, returns right-most digit)
	for (int i = 0; i < pos; i++) {
		x = x / 10;
	}
	return (x % 10);
}

int main() {
	int n;
	long long int number;
	cin >> n >> number;

	int i = 0;
	bool is_palendrom = true;
	while (i * 2 < n) {
		if (digit(number, i) != digit(number, n - 1 - i)) is_palendrom = false;
		i++;
	}

	if (is_palendrom) {
		cout << 1;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << digit(number, i);
		}
	}

	
}