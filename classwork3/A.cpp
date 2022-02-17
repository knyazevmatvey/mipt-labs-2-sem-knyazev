#include <iostream>
using namespace std;

int main() {
	const int N = 8;
	
	int a[N];
	for (int k = 0; k < N; k++) cin >> a[k];

	int i = 1, j = 2;
	while (i < N) {
		if (a[i - 1] < a[i]) {
			i = j;
			j = j + 1;
		}
		else {
			// swapping a[i] and a[i-1]
			int temp;
			temp = a[i];
			a[i] = a[i - 1];
			a[i - 1] = temp;

			i = i - 1;
			if (i == 0) {
				i = j;
				j = j + 1;
			}
		}
	}

	for (int k = 0; k < N; k++) cout << a[k] << " ";
}