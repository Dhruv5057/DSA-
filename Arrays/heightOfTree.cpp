#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

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

int height(Node* root) {

    // Base case
    if (root == NULL)
        return 0;

    // Find height of left subtree
    int leftHeight = height(root->left);

    // Find height of right subtree
    int rightHeight = height(root->right);

    // Current node + maximum of left and right height
    return 1 + max(leftHeight, rightHeight);
}

int main(){

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    cout << "Height of the tree is: " << height(root) << endl;

    return 0;
}