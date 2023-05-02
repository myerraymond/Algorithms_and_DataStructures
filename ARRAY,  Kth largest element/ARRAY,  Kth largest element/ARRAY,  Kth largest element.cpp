#include <queue>
#include <vector>
#include <iostream>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k_(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (min_heap_.size() < k_) {
            min_heap_.push(val);
        }
        else if (val > min_heap_.top()) {
            min_heap_.pop();
            min_heap_.push(val);
        }
        return min_heap_.top();
    }

private:
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;
};

int main() {
    std::vector<int> nums = { 4, 5, 8, 2 };
    KthLargest kthLargest(3, nums);

    std::cout << "3rd largest element: " << kthLargest.add(3) << std::endl;
    std::cout << "2nd largest element: " << kthLargest.add(5) << std::endl;
    std::cout << "2nd largest element: " << kthLargest.add(10) << std::endl;
    std::cout << "2nd largest element: " << kthLargest.add(9) << std::endl;
    std::cout << "2nd largest element: " << kthLargest.add(4) << std::endl;

    return 0;
}
