#include <iostream>
using namespace std;

int main(){
	int n, ans;
	bool empty = true;
	ans = 0;
	cin >> n;
	while (n != 0) {
		if (n % 2 == 0) {
			if (empty) {
				empty = false;
				ans = n;
			}
			else if (n > ans) {
					ans = n;
			}
		}
		cin >> n;
	}
	if (!empty) {
		cout << ans;
	}
}