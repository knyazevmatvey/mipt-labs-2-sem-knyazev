#include<iostream>
#include<cmath>

int main() {
	int a, b;
	std::cin >> a >> b;
	float c = std::sqrt(a * a + b * b);
	std::cout << c;
}