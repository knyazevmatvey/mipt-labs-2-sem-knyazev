#include <iostream>
#include <cstdlib>
using namespace std;


int hello_world() {
	int static counter = 0;
	cout << "Hello, world" << endl;
	counter++;
	return counter;
}

int main() {
	int num = rand() / 10;
	int used = 0;
	for (int i = 0; i < num; i++) {
		used = hello_world();
	}
	cout << "Function was used " << used << " times" << endl;
}
