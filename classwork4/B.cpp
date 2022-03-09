# include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// reading
	int* numbers = new int[n];
	for (int i = 0; i < n; i++) cin >> numbers[i];

	// writing
	int* ptr = numbers;
	for (int i = 0; i < n; i++) {
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		ptr--;
		cout << *ptr << " ";
	}

}