# include <random>
# include <iostream>
# include <fstream>
# include <ctime>
using namespace std;

const int number_of_tries = 1000;
const int n = 20;

bool is_stuck(int x, int y, int num_of_dislocations, int x_coordinates[n*n], int y_coordinates[n*n]) {
    // returns true if dislocation is stuck
    bool ans = false;
    if ((x == 0) || (x == n - 1) || (y == 0) || (y == n - 1)) {
        ans = true;
    }
    int neighbours = 0;
    for (int i = 0; i < num_of_dislocations; i++) {
        if (abs(x_coordinates[i] - x) + abs(y_coordinates[i] - y) <= 1) neighbours++;
    }
    if (neighbours > 1) ans = false;
    return ans;
}

bool already_in_array(int x, int y, int num_of_dislocations, int x_coordinates[n*n], int y_coordinates[n*n]) {
    // returns true if there is already a dislocation with x and y coordinates
    bool ans = false;
    int copies = 0;
    for (int i = 0; i < num_of_dislocations; i++) {
        if ((x_coordinates[i] == x) && (y_coordinates[i] == y)) copies++;
    }
    if (copies > 0) ans = true;
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

int get_new_y(int y, int direction) {
    // returns new y on direction
    switch (direction)
    {
    case 3:
        return y + 1;
    case 4:
        return y - 1;
    default:
        return y;
    }
}

int main() {
    // for measuring time
    const clock_t begin_time = clock();

    ofstream myfile;
    myfile.open("example.txt");

    for (int number_of_dislocations = 1; number_of_dislocations < n * n; ++number_of_dislocations) {

        cout << number_of_dislocations << endl;
        

        int seed = 12;
        mt19937 generator(seed);

        int counter = 0;

        uniform_int_distribution<int> distr_xy(0, n - 1);
        uniform_int_distribution<int> distr_step(1, 4);

        for (int k = 0; k < number_of_tries; k++) {


            // xs and ys - arrays with x and y coordinates of dislocation (we'll use only first number_of_dislocations elements)
            int xs[n*n] = { 0 };
            int ys[n*n] = { 0 };

            // stuck[i] = true when i's location is stuck
            bool stuck[n];
            for (int i = 0; i < n; i++) stuck[i] = false;

            // creating dislocations
            for (int i = 0; i < number_of_dislocations; i++) {
                bool new_dislocation = false;
                int x, y;
                x = distr_xy(generator);
                y = distr_xy(generator);
                if (!already_in_array(x, y, i, xs, ys)) new_dislocation = true;
                while (!new_dislocation) {
                    x = distr_xy(generator);
                    y = distr_xy(generator);
                    if (!already_in_array(x, y, i, xs, ys)) new_dislocation = true;
                }
                xs[i] = x;
                ys[i] = y;
            }


            bool finished = false;
            int t = 0;
            while (!finished) {

                // checking if dislocation is stuck and moving it if it isn't
                for (int i = 0; i < number_of_dislocations; i++) {
                    if (is_stuck(xs[i], ys[i], number_of_dislocations, xs, ys)) stuck[i] = true;
                    if (!stuck[i]) {
                        int move = distr_step(generator);
                        xs[i] = get_new_x(xs[i], move);
                        ys[i] = get_new_y(ys[i], move);
                    }
                }

                // checking if finished
                finished = true;
                for (int i = 0; i < number_of_dislocations; i++) {
                    if (!stuck[i]) finished = false;
                }

                t++;
            }

            myfile << t << " ";
        }
        myfile << endl;
    }

    cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;

    myfile.close();

    return 0;
}