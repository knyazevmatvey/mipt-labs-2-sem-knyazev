#include<iostream>
using namespace std;

int gcd(int x, int y){
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

	int nod = gcd(n, m);
	int nok = n * m / nod;

	cout << "Greatest common divisor: " << nod << endl;
	cout << "Least common denominator: " << nok << endl;
}
