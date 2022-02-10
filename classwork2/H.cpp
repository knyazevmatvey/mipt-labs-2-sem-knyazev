#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string number;
	cin >> n >> number;

	int i = 0;
	bool is_palendrom = true;
	while (i * 2 < n) {
		if (number[i] != number[n - 1 - i]) is_palendrom = false;
		i++;
	}

	if (is_palendrom) {
		cout << 1;
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			cout << number[i];
		}
	}

	
}