#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> small;
	vector<int> big;
	int m = 2;
	while (m * m <= n) {
		if (n % m == 0) {
			small.push_back(m);
			if (m * m != n) big.push_back(n / m);
		}
		m++;
	}
	for (int i = 0; i < big.size(); i++) {
		cout << big[i] << " ";
	}
	for (int i = small.size() - 1; i >= 0; i--) {
		cout << small[i] << " ";
	}

}