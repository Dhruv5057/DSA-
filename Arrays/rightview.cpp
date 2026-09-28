#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

bool mirror(TreeNode* left, TreeNode* right) {

    // Both are NULL
    if (left == NULL && right == NULL)
        return true;

    // One is NULL
    if (left == NULL || right == NULL)
        return false;

    // Values are different
    if (left->val != right->val)
        return false;

    // Check mirror condition
    return mirror(left->left, right->right) &&
           mirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {

    if (root == NULL)
        return true;

    return mirror(root->left, root->right);
}

int main() {

    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root))
        cout << "Tree is symmetric" << endl;
    else
        cout << "Tree is not symmetric" << endl;

    return 0;
}