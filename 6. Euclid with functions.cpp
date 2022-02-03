#include<iostream>
using namespace std;

int lcd(int x, int y){
	int a = max(x, y);
	int b = min(x, y);

	while (b > 0) {
		a = a % b;
		int temp1, temp2;
		temp1 = a;
		temp2 = b;
		a = temp2;
		b = temp1;
	}

	return a;
}


int main() {
	int n, m;
	cin >> n >> m;

	int nod = lcd(n, m);
	int nok = n * m / nod;

	cout << "Least common denominator: " << nod << endl;
	cout << "NOK: " << nok << endl;
}