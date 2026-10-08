#include <iostream>
#include <vector>

using namespace std;

void backtrack(
    int start,
    vector<int>& nums,
    vector<int>& current,
    vector<vector<int>>& result
) {
    // Every current combination is a valid subset
    result.push_back(current);

    for (int i = start; i < nums.size(); i++) {

        // Choose
        current.push_back(nums[i]);

        // Explore
        backtrack(i + 1, nums, current, result);

        // Undo
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;

    backtrack(0, nums, current, result);

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = subsets(nums);

    for (const auto& subset : result) {
        cout << "[ ";

        for (int num : subset) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}