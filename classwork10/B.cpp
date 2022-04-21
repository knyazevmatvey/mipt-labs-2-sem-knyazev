#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* cost = new int[n];
	for (int i = 0; i < n; i++) cin >> cost[i];

	int x = 0;
	int curr = 0;			// price to get to x
	int prev = INT_MAX / 2;	// price to get to x-1
	int old = INT_MAX / 2;	// price to get to x-2
	// p. s. i assume that costs are much smaller than int max
	
	while (x < n) {
		int temp = curr;
		if (prev < temp) temp = prev;
		if (old < temp) temp = old;
		temp += cost[x];

		old = prev;
		prev = curr;
		curr = temp;
		x++;
	}

	cout << curr;
}