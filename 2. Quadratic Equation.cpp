#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << "Every number is a solution";
			}
			else {
				cout << endl;
			}
		}
		else {
			float ans = -c / b;
			cout << ans;
		}
	}
	else {
		int d = b * b - 4 * a * c;
		if (d > 0) {
			float ans1 = (-b - sqrt(d)) / 2 / a;
			float ans2 = (-b + sqrt(d)) / 2 / a;
			cout << ans1 << " " << ans2;
		}
		else if (d == 0) {
			float ans = -b / 2 / a;
			cout << ans;
		}
		else {
			cout << endl;
		}
	}
}