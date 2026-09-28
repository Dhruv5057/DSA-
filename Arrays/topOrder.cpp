#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// Node of Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to find Top View
vector<int> topView(Node* root) {

    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    // Stores: Horizontal Distance -> Node value
    map<int, int> mp;

    // Stores: Node + Horizontal Distance
    queue<pair<Node*, int>> q;

    // Root has horizontal distance 0
    q.push({root, 0});

    while (!q.empty()) {

        Node* node = q.front().first;
        int hd = q.front().second;

        q.pop();

        // Store only the first node at this horizontal distance
        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
        }

        // Left child -> HD - 1
        if (node->left != NULL) {
            q.push({node->left, hd - 1});
        }

        // Right child -> HD + 1
        if (node->right != NULL) {
            q.push({node->right, hd + 1});
        }
    }

    // map automatically gives HDs in sorted order
    for (auto x : mp) {
        ans.push_back(x.second);
    }

    return ans;
}

int main() {

    /*
             1
            / \
           2   3
          / \   \
         4   5   6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    vector<int> result = topView(root);

    cout << "Top View: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}