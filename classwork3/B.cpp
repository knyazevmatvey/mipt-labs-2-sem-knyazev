#include <iostream>
using namespace std;

int main() {
	const int N = 8;
	int a[N] = { 0 };
	for (int i = 0; i < N; i++) cin >> a[i];

	int num;
	cin >> num;
	
	// выводит позицию числа в массиве (наиболее правого из равных элементов), если число не встречается, выводит 0
	if ((num > a[N - 1]) || (num < a[0])) {
		cout << endl;
		return 0;
	}
	else {
		int left = 0;
		int right = N;
		while (right - left > 1) {
			int m = (left + right) / 2;
			if (num >= a[m]) {
				left = m;
			}
			else {
				right = m;
			}
		}
		if (a[left] == num) {
			cout << left;
		}
	}
}