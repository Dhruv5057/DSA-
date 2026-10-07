#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (t.length() > s.length()) {
        return "";
    }

    unordered_map<char, int> need;

    for (char c : t) {
        need[c]++;
    }

    int left = 0;
    int count = 0;
    int minLength = INT_MAX;
    int start = 0;

    for (int right = 0; right < s.length(); right++) {

        char c = s[right];

        if (need[c] > 0) {
            count++;
        }

        need[c]--;

        while (count == t.length()) {

            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                start = left;
            }

            need[s[left]]++;

            if (need[s[left]] > 0) {
                count--;
            }

            left++;
        }
    }

    if (minLength == INT_MAX) {
        return "";
    }

    return s.substr(start, minLength);
}

int main() {
    string s, t;

    cin >> s >> t;

    cout << minWindow(s, t) << endl;

    return 0;
}