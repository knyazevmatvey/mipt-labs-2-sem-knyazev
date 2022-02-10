#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int m = 2;
	while (m <= n) {
		if (n % m == 0) cout << m << " ";
		while (n % m == 0) {
			n = n / m;
		}
		m++;
	}
}