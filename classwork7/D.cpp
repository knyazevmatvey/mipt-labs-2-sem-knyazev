#include <iostream>
using namespace std;

struct vector {
	float x;
	float y;

	vector operator+(vector& other) {
		float new_x = x + other.x;
		float new_y = y + other.y;
		return vector{ new_x, new_y };
	}

	vector operator*(double a) {
		float new_x = a * x;
		float new_y = a * y;
		return vector{ new_x, new_y };
	}

	bool operator==(vector& other) {
		return ((x == other.x) && (y == other.y));
	}
};

struct line {
	// line is given by equation a*x+b*y+c=0
	float a;
	float b;
	float c;
};

float insert_in_line_eq(vector v, line s) {
	return (s.a * v.x + s.b * v.y + s.c);
}

line line_through_two_points(vector a, vector b) {
	return line{ b.y - a.y, -b.x + a.x, -a.x * (b.y - a.y) + a.y * (b.x - a.x) };
}

int main() {
	vector A1, A2, B1, B2;
	cin >> A1.x >> A1.y >> A2.x >> A2.y >> B1.x >> B1.y >> B2.x >> B2.y;
	line b_line = line_through_two_points(B1, B2);

	// если вдруг одна из точек A лежит на прямой B1-B2, немного подвинем её чтобы не рассматривать случаи
	// ответ к задаче при этом не меняется, если только не рассматривать уж очень вырожденные случаи
	// например, когда конец одной прямой совпадает с концом другой (т.е. 2-й пример)
	// ну и соответственно float сравниваем с 0, ибо если сравниваемый float маленький то и так все плохо
	if ((A1 == B1) || (A1 == B2) || (A2 == B1) || (A2 == B2)) {
		cout << "NO";
	}
	else {
		float small = 0.00001;
		if (insert_in_line_eq(A1, b_line) == 0) {
			A1.x += small;
			if (insert_in_line_eq(A1, b_line) == 0) A1.y += small;
		}
		if (insert_in_line_eq(A2, b_line) == 0) {
			A2.x += small;
			if (insert_in_line_eq(A2, b_line) == 0) A2.y += small;
		}


		if (insert_in_line_eq(A1, b_line) * insert_in_line_eq(A2, b_line) >= 0) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	cout << endl;
}