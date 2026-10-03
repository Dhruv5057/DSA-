#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string simplifyPath(string path) {
    vector<string> st;
    stringstream ss(path);
    string dir;

    while (getline(ss, dir, '/')) {

        if (dir == "" || dir == ".") {
            continue;
        }

        if (dir == "..") {
            if (!st.empty()) {
                st.pop_back();
            }
        }
        else {
            st.push_back(dir);
        }
    }

    string result = "";

    for (string folder : st) {
        result += "/" + folder;
    }

    if (result.empty()) {
        return "/";
    }

    return result;
}

int main() {
    string path;
    cin >> path;

    cout << simplifyPath(path) << endl;

    return 0;
}