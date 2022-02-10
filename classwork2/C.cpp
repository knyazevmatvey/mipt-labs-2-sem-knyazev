#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool ans = true;
	while (n != 1) {
		if (n % 2 != 0) ans = false;
		n = n / 2;
	}
	if (ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}