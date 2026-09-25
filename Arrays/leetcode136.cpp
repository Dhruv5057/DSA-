#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    int ans = 0;

    for (int num : nums) {
        ans = ans ^ num;
    }

    cout << "Single number: " << ans << endl;

    return 0;
}