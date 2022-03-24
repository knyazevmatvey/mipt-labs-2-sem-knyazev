#include <iostream>
using namespace std;

struct Time {
	int hour;
	int minute;
	int second;

	Time operator+(const Time& other) const {
		int full = (second + other.second) + 60 * (minute + other.minute) + 60 * 60 * (hour + other.hour);
		int new_second = full % 60;
		full = full / 60;
		int new_minute = full % 60;
		full = full / 60;
		int new_hour = full % 24;
		return Time{ new_hour, new_minute, new_second };
	}

	friend  ostream& operator<<(ostream& output, const Time& other) {
		output << other.hour << ":" << other.minute << ":" << other.second;
		return output;
	}
};

int main() {
	int temp_h, temp_m, temp_s;
	cin >> temp_h >> temp_m >> temp_s;
	Time beginning = Time{ temp_h, temp_m, temp_s };

	cin >> temp_h >> temp_m >> temp_s;
	Time duration = Time{ temp_h, temp_m, temp_s };

	Time end;
	end = beginning + duration;

	cout << end;
}