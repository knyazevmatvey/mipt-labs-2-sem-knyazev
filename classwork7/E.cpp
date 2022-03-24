#include <iostream>
using namespace std;

struct interval {
	float beginning;
	float end;
};

interval intersection(interval first, interval second) {
	float beginning = 0, end = 0;
	if (first.beginning > second.beginning) {
		beginning = first.beginning;
	}
	else {
		beginning = second.beginning;
	}

	if (first.end < second.end) {
		end = first.end;
	}
	else {
		end = second.end;
	}

	interval ans{ beginning, end };
	return ans;
}



int main() {
	int n;
	cin >> n;

	interval* lines = new interval[n];
	for (int i = 0; i < n; i++) {
		float a, b;
		cin >> a >> b;
		if (a > b) {
			lines[i].beginning = b;
			lines[i].end = a;
		}
		else {
			lines[i].beginning = a;
			lines[i].end = b;
		}
	}

	interval total = lines[0];
	for (int i = 0; i < n - 1; i++) {
		total = intersection(total, lines[i + 1]);
	}

	if (total.end >= total.beginning) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}