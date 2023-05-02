#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr) {
    int max_num = *max_element(arr.begin(), arr.end());
    vector<int> count(max_num + 1, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_num; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = { 4, 2, 2, 8, 3, 3, 1 };
    countingSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
