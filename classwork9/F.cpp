#include <iostream>
using namespace std;

int* add(int* arr, int value, int size) {
	int* new_arr = new int[size + 1];
	for (int i = 0; i < size; i++) new_arr[i] = arr[i];
	new_arr[size] = value;
	delete[] arr;
	return new_arr;
}

bool is_in_arr(int* arr, int value, int size) {
	bool ans = false;
	for (int i = 0; i < size; i++) if (arr[i] == value) ans = true;
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;

	// a[i][j] = вес, если i-я вершина соединяется j-м ребром
	int** a = new int*[m];
	for (int i = 0; i < m; i++) a[i] = new int[n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int size = 1;
	int* linked = new int[1];
	linked[0] = 0;


	// finding first and second elements that the i-th road connects
	int* first = new int[n];
	int* second = new int[n];
	for (int j = 0; j < n; j++) {
		bool encountered = false;
		for (int i = 0; i < m; i++) {
			if (a[i][j] != 0) {
				if (!encountered) {
					first[j] = i;
					encountered = true;
				}
				else {
					second[j] = i;
				}
			}
		}
	}

	int ans = 0;
	bool finished = (m == 1);
	int i_min = -1;
	int j_min = -1;
	while (!finished) {
		int minimal = -1;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < n; j++) {
				if (a[linked[i]][j] != 0) {
					if ((minimal == -1) || (a[linked[i]][j] < minimal)) {
						bool already_in_the_grid = true;
						if (!is_in_arr(linked, first[j], size)) already_in_the_grid = false;
						if (!is_in_arr(linked, second[j], size)) already_in_the_grid = false;
						if (!already_in_the_grid) {
							minimal = a[linked[i]][j];
							i_min = i;
							j_min = j;
						}
					}
				}
			}
		}

		int new_vertice = -1;
		for (int i = 0; i < m; i++) {
			if ((a[i][j_min] != 0) && (i != linked[i_min])) new_vertice = i;
		}

		linked = add(linked, new_vertice, size);
		size++;

		ans += a[linked[i_min]][j_min];

		// deleting all the roads between already linked towns
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[linked[i]][linked[j]] = 0;
			}
		}*/

		if (size == m) finished = true;
	}

	cout << ans*98;

}