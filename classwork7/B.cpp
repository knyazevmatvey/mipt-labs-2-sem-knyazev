#include <iostream>
using namespace std;

int number_of_students = 10;

struct person {
	char name[20];
	float score;

	bool operator<(const person& other) const {
		return ((score < other.score) || ((score == other.score) && (name < other.name)));
	}

    bool operator<=(const person& other) const {
        return ((score < other.score) || ((score == other.score) && name <= other.name));
    }

	bool operator>(const person& other) const {
		return !((score < other.score) || ((score == other.score) && name <= other.name));
	}

	bool operator>=(const person& other) const {
		return !((score < other.score) || ((score == other.score) && (name < other.name)));
	}
};

void pyramidal_scheme(person arr[], int n) {
	// right border after which the array is sorted
	// (sorted elements at the end of the loop's body will start from index = right-1)
	int right = n;

	while (right > 1) {
		// setting i to zero and increasing while we can
		int i = right / 2 - 1;

		// making the first check
		if (2 * i + 2 <= right - 1) {
			if (arr[i] < arr[2 * i + 2]) {
				person temp = arr[2 * i + 2];
				arr[2 * i + 2] = arr[i];
				arr[i] = temp;
			}
		}
		if (arr[i] < arr[2 * i + 1]) {
			person temp = arr[2 * i + 1];
			arr[2 * i + 1] = arr[i];
			arr[i] = temp;
		}
		i--;

		// making other checks
		// p.s. я делаю проверки лишь один раз за цикл, т. е. не дожидаюсь пока условие станет верным во всех вершинач
		while (i >= 0) {
			if ((arr[i] < arr[2 * i + 2]) || (arr[i] < arr[2 * i + 1])) {
				if (arr[2 * i + 1] > arr[2 * i + 2]) {
					person temp = arr[i];
					arr[i] = arr[2 * i + 1];
					arr[2 * i + 1] = temp;
				}
				else {
					person temp = arr[i];
					arr[i] = arr[2 * i + 2];
					arr[2 * i + 2] = temp;
				}
			}
			i--;
		}

		// replacing elements
		person temp = arr[right - 1];
		arr[right - 1] = arr[0];
		arr[0] = temp;

		right--;
	}
}

int main() {
	person* students = new person[number_of_students];

	for (int i = 0; i < number_of_students; i++) {
		char* temp_name = new char[20];
		cin >> students[i].name;
		cin >> students[i].score;
	}

	int m;
	cin >> m;
		 
    pyramidal_scheme(students, number_of_students);

	int i = 0;
	while ((students[i].score < m) && (i < number_of_students)) i++;

	while (i < number_of_students) {
		cout << students[i].name;
		if (i < number_of_students - 1) cout << " ";
		i++;
	}

	cout << endl;
}