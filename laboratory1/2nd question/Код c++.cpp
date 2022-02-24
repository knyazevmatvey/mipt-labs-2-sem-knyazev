# include <random>
# include <iostream>
# include <fstream>
# include <ctime>
using namespace std;

const int number_of_tries = 1000;
const int n = 20;

bool is_stuck(int x, int y, int size, int a[n][n]) {
    // returns true if dislocation is stuck
    bool ans = false;
    if ((x == 0) || (x == size - 1) || (y == 0) || (y == size - 1)) {
        ans = true;
    }
    else {
        if ((a[x - 1][y] != 0) || (a[x+1][y] != 0) || (a[x][y-1] != 0) || (a[x][y+1] != 0)) {
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
        return x+1;       //я не хочу думать x++ или ++x
    case 2:
        return x-1;
    default:
        return x;
    }
}

int get_new_y(int y, int direction) {
    // returns new y on direction
    switch (direction)
    {
    case 3:
        return y+1;
    case 4:
        return y-1;
    default:
        return y;
    }
}

int main() {
    // for measuring time
    const clock_t begin_time = clock();

    ofstream myfile;
    myfile.open("example.txt");

    for (int number_of_dislocations = 1; number_of_dislocations < n*n; ++number_of_dislocations) {

        cout << number_of_dislocations << endl;

        int seed = 12;
        mt19937 generator(seed);
        
        int counter = 0;

        for (int k = 0; k < number_of_tries; k++) {
            uniform_int_distribution<int> distr_xy(0, n - 1);
            uniform_int_distribution<int> distr_step(1, 4);

            // creating a space for dislocations
            int space[n][n] = { {0} };

            // creating dislocations (1's) in space
            for (int i = 0; i < number_of_dislocations; i++) {
                bool new_dislocation = false;
                int x, y;
                x = distr_xy(generator);
                y = distr_xy(generator);
                if (space[x][y] == 0) new_dislocation = true;
                while (!new_dislocation) {
                    x = distr_xy(generator);
                    y = distr_xy(generator);
                    if (space[x][y] == 0) new_dislocation = true;
                }
                space[x][y] = 1;
            }
            
            
            bool finished = false;
            int t = 0;
            while (!finished) {
                // checking space for stuck dislocations and renaming them from 1 to 2
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (space[x][y] == 1) {
                            if (is_stuck(x, y, n, space)) {
                                space[x][y] = 2;
                            }
                        }
                    }
                }

                // creating a new space and filling it
                int future_space[n][n] = { {0} };
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        // dislocation moves to a new place if it is empty or stays in the old place otherwise
                        if (space[x][y] == 1) {
                            int move = distr_step(generator);
                            int new_x = get_new_x(x, move);
                            int new_y = get_new_y(y, move);
                            
                            if (future_space[new_x][new_y] == 0) {
                                future_space[new_x][new_y] = 1;
                            }
                            else {
                                future_space[x][y] = 1;
                            }
                        }

                        // a stuck dislocation remains in its place
                        if (space[x][y] == 2) {
                            future_space[x][y] = 2;
                        }
                    }
                }
                
                // changing space to future_space and checking if finished
                finished = true;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        space[x][y] = future_space[x][y];
                        if (space[x][y] == 1) {
                            finished = false;
                        }
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