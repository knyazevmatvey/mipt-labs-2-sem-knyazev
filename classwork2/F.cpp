#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	bool ans = true;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) ans = false;
	}
	if (ans) cout << "YES";
	if (!ans) cout << "NO";
}