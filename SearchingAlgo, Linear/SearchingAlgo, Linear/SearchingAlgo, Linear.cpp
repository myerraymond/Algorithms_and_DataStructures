#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // value not found
}

int main() {
    int arr[] = { 5, 3, 8, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        cout << "Value not found" << endl;
    }
    else {
        cout << "Value found at index " << result << endl;
    }
    return 0;
}
