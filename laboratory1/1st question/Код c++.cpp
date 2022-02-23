# include <random>
# include <iostream>
# include <fstream>
using namespace std;

bool check_borders(int x, int y, int size) {
    bool ans = false;
    if ((x == 0) || (x == size - 1)) {
        ans = true;
    }
    if ((y == 0) || (y == size - 1)) {
        ans = true;
    }
    return ans;
}

int main(int argc, char* argv[]) {
    int seed = 12;
    mt19937 generator(seed);

    ofstream myfile;
    myfile.open("example.txt");

    const int number_of_tries = 100;
    const int max_n = 200;
    
    for (int n = 1; n < max_n; ++n) {
        uniform_int_distribution<int> distr_xy(0, n - 1);
        uniform_int_distribution<int> distr_step(1, 4);


        cout << n << endl;

        for (int k = 0; k < number_of_tries; k++) {
            int x, y;
            x = distr_xy(generator);
            y = distr_xy(generator);

            bool stuck = check_borders(x, y, n);
            int t = 0;
            while (!stuck) {
                int move = distr_step(generator);

                if (move == 1) {
                    x++;
                }
                if (move == 2) {
                    x--;
                }
                if (move == 3) {
                    y++;
                }
                if (move == 4) {
                    y--;
                }

                stuck = check_borders(x, y, n);
                t++;
            }

            myfile << t << " ";
        }
        myfile << endl;
    }

    myfile.close();

    return 0;
}