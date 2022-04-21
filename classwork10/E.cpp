#include<iostream>
#include<climits>
using namespace std;

void get_string (int l, char* &char_ptr) {
	char_ptr = new char[l];
	int letters = 0;
	while (letters < l) {
		char temp = cin.get();
		if ((temp != ' ') && (temp != '\n')) {
			char_ptr[letters] = temp;
			letters++;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	char* first;
	char* second;
	get_string(n, first);
	get_string(m, second);

	int** a = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) a[i] = new int[m + 1];

	// setting zeroth raw and column equal to zero
	for (int i = 0; i < n + 1; i++) a[i][0] = 0;
	for (int j = 0; j < m + 1; j++) a[0][j] = 0;

	// finding the matrix a of the lengths of the biggest subsequence
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++) {
			if (first[i - 1] == second[j - 1]) a[i][j] = a[i - 1][j - 1] + 1;
			else {
				int ans = -1;
				if (a[i - 1][j] > ans) ans = a[i - 1][j];	
				if (a[i][j - 1] > ans) ans = a[i][j - 1];
				a[i][j] = ans;
			}
		}

	// recreating the sequence from a
	int l = a[n][m];
	char* ans = new char[l];
	int curr = l;
	int i = n;
	int j = m;
	while (curr > 0) {
		if (first[i - 1] == second[j - 1]) {
			ans[curr - 1] = first[i - 1];
			curr--;
			i--;
			j--;
		}
		else {
			if (a[i - 1][j] == a[i][j]) {
				i--;
			}
			else {
				j--;
			}
		}
	}

	for (int i = 0; i < l; i++) cout << ans[i];
}