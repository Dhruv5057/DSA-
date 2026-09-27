#include <iostream>
#include <queue>
#include <vector>
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

void zigzag(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {

        int n = q.size();
        vector<int> level(n);

        for (int i = 0; i < n; i++) {

            Node* current = q.front();
            q.pop();

            int index;

            if (leftToRight)
                index = i;
            else
                index = n - i - 1;

            level[index] = current->data;

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }

        for (int i = 0; i < n; i++) {
            cout << level[i] << " ";
        }

        leftToRight = !leftToRight;
    }
}


int main() {

    // Creating tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Zigzag Traversal: ";
    zigzag(root);

    return 0;
}