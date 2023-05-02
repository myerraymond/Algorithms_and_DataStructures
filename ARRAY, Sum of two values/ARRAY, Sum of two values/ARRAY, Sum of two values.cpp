#include <iostream>
#include <unordered_set>
#include <vector>

bool hasSumPair(std::vector<int>& arr, int target) {
    std::unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(target - num)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    std::vector<int> arr = { 1, 4, 5, 8, 10 };
    int target = 13;
    if (hasSumPair(arr, target)) {
        std::cout << "There are two integers in the array that add up to " << target << std::endl;
    }
    else {
        std::cout << "There are no two integers in the array that add up to " << target << std::endl;
    }
    return 0;
}
