#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};
// Insert (no duplicates) - recursive
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    // if equal, do nothing (no duplicates)
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}
// Delete node (handles 0,1,2 children)
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        // found
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            // two children: replace with inorder successor (min in right)
            Node* succ = findMin(root->right);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}
// Maximum depth (height)
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
// Minimum depth (shortest path to a leaf)
int minDepth(Node* root) {
    if (!root) return 0;
    // If one subtree is null, you must consider the other
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->key << ' ';
    inorderPrint(root->right);
}
int main() {
    Node* root = nullptr;
    int arr[] = {15, 10, 20, 8, 12, 17, 25, 19};
    for (int x : arr) root = insertNode(root, x);

    cout << "Inorder: "; inorderPrint(root); cout << '\n';
    cout << "Max depth: " << maxDepth(root) << '\n';
    cout << "Min depth: " << minDepth(root) << '\n';

    cout << "Deleting 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder after delete: "; inorderPrint(root); cout << '\n';

    cout << "Deleting 15 (root)\n";
    root = deleteNode(root, 15);
    cout << "Inorder after delete: "; inorderPrint(root); cout << '\n';

    return 0;
}
