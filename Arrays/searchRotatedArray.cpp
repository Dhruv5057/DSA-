#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (k < 2 || nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "Length: " << k << endl;

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
    return 0;
}