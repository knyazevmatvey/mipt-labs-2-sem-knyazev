#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char temp;
	int ans = 0;
	bool ok = true;
	// I don't know how to use a stack in this situation if all i need is to count
	while (true) {
		char temp = cin.get();
		if (temp == '\n') break;
		if (temp == ' ') break;
		if (temp == '(') ans++;
		if (temp == ')') ans--;
		if (ans < 0) ok = false;
	}
	if (ans != 0) ok = false;

	cout << 1 - ok;
}