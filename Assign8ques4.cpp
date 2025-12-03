#include <iostream>
#include <limits>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};
//check BST in range (min..max)
bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->key <= minVal || node->key >= maxVal) return false; // no duplicates allowed
    return isBSTUtil(node->left, minVal, node->key) && isBSTUtil(node->right, node->key, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}
// build example and test
int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    cout << (isBST(root) ? "Is BST\n" : "Not BST\n");
    // break BST property
    root->left->right->key = 9; // violates BST (should be <8)
    cout << (isBST(root) ? "Is BST\n" : "Not BST\n");

    return 0;
}
