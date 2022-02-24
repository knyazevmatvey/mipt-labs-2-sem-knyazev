# include <random>
# include <iostream>
# include <fstream>
using namespace std;

bool check_borders(int x, int size) {
    bool ans = false;
    if ((x == 0) || (x == size - 1)) {
        ans = true;
    }
    return ans;
}

int main() {
    int seed = 12;
    mt19937 generator(seed);

    ofstream myfile;
    myfile.open("example.txt");

    const int number_of_tries = 1000;
    const int max_n = 200;

    for (int n = 1; n < max_n; ++n) {
        uniform_int_distribution<int> distr_xy(0, n - 1);
        uniform_int_distribution<int> distr_step(1, 2);


        cout << n << endl;

        for (int k = 0; k < number_of_tries; k++) {
            int x, y;
            x = distr_xy(generator);

            bool stuck = check_borders(x, n);
            int t = 0;
            while (!stuck) {
                int move = distr_step(generator);

                if (move == 1) {
                    x++;
                }
                if (move == 2) {
                    x--;
                }

                stuck = check_borders(x, n);
                t++;
            }

            myfile << t << " ";
        }
        myfile << endl;
    }

    myfile.close();

    return 0;
}