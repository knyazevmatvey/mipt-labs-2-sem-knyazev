#include <iostream>
using namespace std;

int main() {
	int n, m, ans;
	cin >> n;

	// initial values
	m = n;
	ans = 0;

	if (n == 0) return 0;

	while (n != 0) {
		if (n == m) ans++;
		if (n > m) {
			m = n;
			ans = 1;
		}
		cin >> n;
	}
	cout << ans;
}