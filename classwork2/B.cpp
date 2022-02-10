#include <iostream>
using namespace std;

int main() {
	int n;
	int ans = 0;
	cin >> n;
	while (n != 0) {
		if (n % 2 == 0) ans++;
		cin >> n;
	}
	cout << ans;
}