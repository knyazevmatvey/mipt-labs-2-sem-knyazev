#include <iostream>
using namespace std;

int main() {
	int a[4] = { 1, 7, 49, 98 };
	int n;
	cin >> n;

	int ans = 0;
	int stage = 3;
	while (stage >= 0) {
		ans += n / a[stage];
		n = n % a[stage];
		stage--;
	}

	cout << ans;
}