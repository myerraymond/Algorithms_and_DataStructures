#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // create temporary arrays
    std::vector<int> L(n1), R(n2);

    // copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // merge the temporary arrays back into arr[left..right]
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = left; // initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        // sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        // merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> arr = { 4, 2, 9, 5, 1, 3 };
    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
