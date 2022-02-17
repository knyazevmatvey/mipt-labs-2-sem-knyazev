#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int a, b;
	if (n > m) {
		a = n;
		b = m;
	}
	else {
		a = m;
		b = n;
	}

	while (b > 0) {
		a = a % b;
		int temp1, temp2;
		temp1 = a;
		temp2 = b;
		a = temp2;
		b = temp1;
	}

	cout << n * m / a;
}