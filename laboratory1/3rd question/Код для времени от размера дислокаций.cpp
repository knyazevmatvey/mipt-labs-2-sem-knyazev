# include <random>
# include <iostream>
# include <fstream>
# include <ctime>
using namespace std;

const int number_of_tries = 1000;
const int n = 100;

bool is_stuck(int x, int size, int a[n]) {
    // returns true if dislocation is stuck
    bool ans = false;
    if ((x == 0) || (x == size - 1)) {
        ans = true;
    }
    else {
        if ((a[x - 1] != 0) || (a[x + 1] != 0)) {
            ans = true;
        }
    }
    return ans;
}

int get_new_x(int x, int direction) {
    // returns new x on direction
    switch (direction)
    {
    case 1:
        return x + 1;       //я не хочу думать x++ или ++x
    case 2:
        return x - 1;
    default:
        return x;
    }
}

int main() {
    // for measuring time
    const clock_t begin_time = clock();

    ofstream myfile;
    myfile.open("example.txt");

    for (int number_of_dislocations = 1; number_of_dislocations < n; ++number_of_dislocations) {

        cout << number_of_dislocations << endl;

        int seed = 12;
        mt19937 generator(seed);

        int counter = 0;

        for (int k = 0; k < number_of_tries; k++) {
            uniform_int_distribution<int> distr_xy(0, n - 1);
            uniform_int_distribution<int> distr_step(1, 2);

            // creating a space for dislocations
            int space[n] = { 0 };

            // creating dislocations (1's) in space
            for (int i = 0; i < number_of_dislocations; i++) {
                bool new_dislocation = false;
                int x;
                x = distr_xy(generator);
                if (space[x] == 0) new_dislocation = true;
                while (!new_dislocation) {
                    x = distr_xy(generator);
                    if (space[x] == 0) new_dislocation = true;
                }
                space[x] = 1;
            }


            bool finished = false;
            int t = 0;
            while (!finished) {
                // checking space for stuck dislocations and renaming them from 1 to 2
                for (int x = 0; x < n; x++) {
                    if (space[x] == 1) {
                        if (is_stuck(x, n, space)) {
                            space[x] = 2;
                        }
                    }
                }

                // creating a new space and filling it
                int future_space[n] = {0};
                for (int x = 0; x < n; x++) {
                    // dislocation moves to a new place if it is empty or stays in the old place otherwise
                    if (space[x] == 1) {
                        int move = distr_step(generator);
                        int new_x = get_new_x(x, move);

                        if (future_space[new_x] == 0) {
                            future_space[new_x] = 1;
                        }
                        else {
                            future_space[x] = 1;
                        }
                    }

                    // a stuck dislocation remains in its place
                    if (space[x] == 2) {
                        future_space[x] = 2;
                    }
                }

                // changing space to future_space and checking if finished
                finished = true;
                for (int x = 0; x < n; x++) {
                    space[x] = future_space[x];
                    if (space[x] == 1) {
                        finished = false;
                    }
                }

                t++;
            }

            myfile << t << " ";
        }
        myfile << endl;
    }

    cout << float(clock() - begin_time) / CLOCKS_PER_SEC;

    myfile.close();

    return 0;
}