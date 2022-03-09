#include <iostream>
using namespace std;

void quicksort(int arr[], int left, int right) {
    int pivot = arr[left];
    int l = left;
    int r = right;

    if (right > left) {
        while (r > l) {
            // moving l and r
            while ((arr[l] < pivot) && (l < right)) l++;
            while ((arr[r] >= pivot) && (r > left)) r--;

            // swapping if needed
            if (r <= l) break;
            if (r > l) {
                int temp = arr[r];
                arr[r] = arr[l];
                arr[l] = temp;
            }
        }

        // finding the border where to cut the array
        // (it's probably close to l and r, but I'm not sure
        int index = left;
        while ((arr[index] <= pivot) && (index < right)) index++;
        quicksort(arr, left, index - 1);
        quicksort(arr, index, right);
    }
    
}

int main() {
    int n;
    cin >> n;

    int* numbers = new int[n];
    for (int i = 0; i < n; i++) cin >> numbers[i];
    quicksort(numbers, 0, n - 1);
    for (int i = 0; i < n; i++) cout << numbers[i] << " ";
}