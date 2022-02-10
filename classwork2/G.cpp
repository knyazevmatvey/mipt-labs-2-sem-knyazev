#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) cout << n / i << " ";
		i++;
	}
	i--;
	if (i * i == n) i--;
	while (i >= 2) {
		if (n % i == 0) cout << i << " ";
		i--;
	}
	

}