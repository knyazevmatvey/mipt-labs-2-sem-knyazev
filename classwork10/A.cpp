#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int x = 0;
	int curr = 1;	// number of ways to get to x
	int prev = 0;	// number of ways to get to x-1
	int old = 0;	// number of ways to get to x-2
	while (x < n) {
		int temp = curr + prev + old;
		old = prev;
		prev = curr;
		curr = temp;
		x++;
	}

	cout << curr;
}