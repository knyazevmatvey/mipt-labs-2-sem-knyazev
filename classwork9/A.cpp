#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* x = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	int t = 0;
	int closest = -1;
	int lectures = 0;
	bool finished = false;
	while (!finished) {
		finished = true;
		for (int i = 0; i < n; i++) if (x[i] >= t) finished = false;
		if (finished) break;

		for (int i = 0; i < n; i++) {
			if (x[i] >= t) {
				if ((closest == -1) || (y[i] < y[closest])) closest = i;
			}
		}

		lectures++;
		t = y[closest];
		closest = -1;
	}

	delete[] x, y;
	cout << lectures;
}