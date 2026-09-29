#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};

    int k = 2;

    cout << kthLargest(nums, k);

    return 0;
}