#include <iostream>
using namespace std;


// Принимаю на вход количество вершин + матрицу смежности
int main() {
	// n -- количество вершин, m -- количество ребер
	int n, m;
	cin >> n;

	// создаем массив для хранения матрицы смежности и считываем его
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// counting the number of lines
	m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0) m++;
		}
	m = m / 2;

	// ans[i][j] = weight, if the i-th vertice is connected to the m-th line
	int** ans = new int* [n];
	for (int i = 0; i < n; i++) ans[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) ans[i][j] = 0;

	int current = 0;	// the number of the line we're adding
	while (true) {
		// checking if we're done (if we deleted all the elements from a and added them to ans
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
		current++;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << ans[i][j];
			if (j != m - 1) cout << " ";
			if ((j == m - 1) && (i != n - 1)) cout << endl;
		}

}