#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	double ans = 0;
	for (int i = 1; i <= n; i++) {
		double j = i;
		ans += 1 / (j * j);
	}
	cout << ans;
}