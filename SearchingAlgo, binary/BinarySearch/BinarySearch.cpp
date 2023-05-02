#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int lower = 0;
    int upper = n - 1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            lower = mid + 1;
        }
        else {
            upper = mid - 1;
        }
    }
    return -1; // value not found
}

int main() {
    int arr[] = { 2, 3, 4, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 0;
    int result = binarySearch(arr, n, x);
    if (result == -1) {
        cout << "Value not found" << endl;
    }
    else {
        cout << "Value found at index " << result << endl;
    }
    return 0;
}
