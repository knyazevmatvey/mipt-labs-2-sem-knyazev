#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int* marks = new int[m + 2];
	marks[0] = 0;
	for (int i = 0; i < m; i++) cin >> marks[i + 1];
	marks[m + 1] = n;

	int k = m + 2;
	
	// a[i][j] -- the money we would need if the log was from i-th mark to j-th
	int** a = new int*[k];
	for (int i = 0; i < k; i++) a[i] = new int[k];

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) a[i][j] = 0;

	// finding answer for a[i][i+cuts] by making a cut at a[i][j]
	for (int cuts = 2; cuts < k; cuts++) {
		for (int i = 0; i < k - cuts; i++) {
			int ans = INT_MAX;
			for (int j = 1; j < cuts; j++) {
				if (a[i][i + j] + a[i + j][i + cuts] < ans) ans = a[i][i + j] + a[i + j][i + cuts];
			}
			a[i][i + cuts] = marks[i + cuts] - marks[i] + ans;
		}
	}

	cout << a[0][k - 1];
}