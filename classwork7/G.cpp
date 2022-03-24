#include <iostream>
# include <cstring>
using namespace std;

// P. S. Испольузю cstring чтобы сравнивать строки (я не уверен,
// можно ли его использовать, но в примерах в lab7 это было,
// так что почему бы и нет

struct atom {
	int nuclons;
	int charge;
	char name[8];

	bool operator==(atom other) {
		return ((nuclons == other.nuclons) && (charge == other.charge));
	}
};

struct five_letter_word {
	char word[6];

	bool operator==(five_letter_word const &other) const {
		bool ans = true;
		for (int i = 0; i < 6; i++) if (word[i] != other.word[i]) ans = false;
		return ans;
	}
};

int main() {
	int n;
	cin >> n;
	
	atom* all_atoms = new atom[n];

	for (int i = 0; i < n; i++) cin >> all_atoms[i].name >> all_atoms[i].nuclons >> all_atoms[i].charge;

	int m;
	cin >> m;
	for (int t = 0; t < m; t++) {
		char temp_name[20];
		cin >> temp_name;
		int temp_nuclons = 0, temp_charge = 0;

		// looking for the initial A and Z
		for (int i = 0; i < n; i++) {
			if (strcmp(temp_name, all_atoms[i].name) == 0) {
				temp_nuclons = all_atoms[i].nuclons;
				temp_charge = all_atoms[i].charge;
			}
		}

		

		// changing the numbers according to the reaction
		five_letter_word alpha{ "alpha" }, beta_m{ "beta-" }, beta_p{ "beta+" }, reac;
		cin >> reac.word;
		if (reac == alpha) {
			temp_nuclons -= 4;
			temp_charge -= 2;
		}
		if (reac == beta_p) {
			temp_charge -= 1;
		}
		if (reac == beta_m) {
			temp_charge += 1;
		}

		int ans = -1;
		atom temp{ temp_nuclons, temp_charge, "no_name" };
		for (int i = 0; i < n; i++) {
			if (temp == all_atoms[i]) {
				ans = i;
			}
		}
		if (ans == -1) {
			cout << "NO DATA";
		}
		else {
			cout << all_atoms[ans].name;
		}

		if (t < m - 1) cout << " ";
	}
}