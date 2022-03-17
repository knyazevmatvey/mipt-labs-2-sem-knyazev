#include <iostream>
using namespace std;

int number_of_students = 10;

struct person {
	char name[20];
	float score;
};

int main() {
	person* students = new person[number_of_students];

	for (int i = 0; i < number_of_students; i++) {
		char* temp_name = new char[20];
		cin >> students[i].name;
		cin >> students[i].score;
	}
	
	int m;
	cin >> m;

	for (int i = 0; i < number_of_students; i++) {
		if (students[i].score >= m) {
			cout << students[i].name;
			if (i < number_of_students - 1) cout << " "; // an so that we don't have extra space at the end
		}
	}
	cout << endl;
}