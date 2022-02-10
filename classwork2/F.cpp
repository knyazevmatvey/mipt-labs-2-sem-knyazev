#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> prime(n + 1);
	for (int i = 0; i < n + 1; i++) {
		prime[i] = true;
	}

	for (int i = 2; i < n; i++) {
		if (prime[i]) {
			int m = 2;
			while (i * m <= n) {
				prime[i * m] = false;
				m++;
			}
		}
	}

	if (prime[n]) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}