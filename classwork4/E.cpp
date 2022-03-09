# include <iostream>
using namespace std;

void pyramidal_scheme(int arr[], int n) {
	// right border after which the array is sorted
	// (sorted elements at the end of the loop's body will start from index = right-1)
	int right = n;

	while (right > 0) {
		// setting i to zero and increasing while we can
		int i = right / 2 - 1;

		// making the first check
		if (2 * i + 2 <= right - 1) {
			if (arr[i] > arr[2 * i + 2]) {
				int temp = arr[2 * i + 2];
				arr[2 * i + 2] = arr[i];
				arr[i] = temp;
			}
		}
		if (arr[i] > arr[2 * i + 1]) {
			int temp = arr[2 * i + 1];
			arr[2 * i + 1] = arr[i];
			arr[i] = temp;
		}
		i--;

		// making other checks
		// p.s. я делаю проверки лишь один раз за цикл, т. е. не дожидаюсь пока условие станет верным во всех вершинач
		while (i >= 0) {
			if ((arr[i] > arr[2 * i + 2]) || (arr[i] > arr[2 * i + 1])) {
				if (arr[2 * i + 1] < arr[2 * i + 2]) {
					int temp = arr[i];
					arr[i] = arr[2 * i + 1];
					arr[2 * i + 1] = temp;
				}
				else {
					int temp = arr[i];
					arr[i] = arr[2 * i + 2];
					arr[2 * i + 2] = temp;
				}
			}
			i--;
		}

		// replacing elements
		int temp = arr[right - 1];
		arr[right - 1] = arr[0];
		arr[0] = temp;

		right--;
	}

}

int main() {
	int n;
	cin >> n;

	int* numbers = new int[n];
	for (int i = 0; i < n; i++) cin >> numbers[i];

	pyramidal_scheme(numbers, n);

	for (int i = n-1; i >= 0; i--) cout << numbers[i] << " ";
	cout << endl;
}