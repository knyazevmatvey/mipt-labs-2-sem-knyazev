#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int* stops = new int[k];
	for (int i = 0; i < k; i++) cin >> stops[i];

	int ans = 0;
	int x = 0; // current position
	while (x < n - m) {
		bool hope = false;
		for (int i = 0; i < k; i++) if ((x < stops[i]) && (stops[i] <= x + m)) hope = true;
		if (!hope) {
			ans = -1;
			break;
		}
		else {
			int farthest = -1;
			for (int i = 0; i < k; i++) {
				if ((x < stops[i]) && (stops[i] <= x + m)) {
					if (stops[i] > farthest) farthest = stops[i];
				}
			}
			x = farthest;
			ans++;
		}
	}
	cout << ans;
}