#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	int* ans = new int[n];
	ans[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		ans[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[i]) {
				if (ans[j] + 1 > ans[i]) ans[i] = ans[j] + 1;
			}
		}
	}

	cout << ans[0];
}