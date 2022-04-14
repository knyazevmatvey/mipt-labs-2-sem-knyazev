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


// i'm not sure if it is working, i didn't test it at all
int main() {
	// n -- количество вершин, m -- количество ребер
	int n, m;
	cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// counting the number of line
	m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			m++;
		}
	m = m / 2;

	// ans[i][j] = weight, if the i-th vertice is connected to the m-th line
	int** ans = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[m];

	int current = 0;	// the number of the line we're adding
	while (true) {
		// checking if we're done
		bool finished = true;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 0) finished = false;
			}
		if (finished) break;

		// looking for the first non-zero element of the matrix
		int i_first = -1;
		int j_first = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if ((a[i][j] != 0) && (i_first == -1)) {
					i_first = i;
					j_first = j;
				}
			}

		// deleting the added edge from the original matrix and adding it to the ans matrix
		int weight = a[i_first][j_first];
		a[i_first][j_first] = 0;
		a[j_first][i_first] = 0;

		ans[i_first][current] = weight;
		ans[j_first][current] = weight;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << ans[i][j];
			if (j != m - 1) cout << " ";
			if ((j == m - 1) && (i != n - 1)) cout << endl;
		}

}