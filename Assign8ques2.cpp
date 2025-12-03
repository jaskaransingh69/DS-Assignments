#include <iostream>
using namespace std;
struct Node {
    int key;
    Node *left, *right, *parent;
    Node(int k): key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* bstInsert(Node* root, int key) {
    if (!root) return new Node(key);
    Node* cur = root;
    Node* parent = nullptr;
    while (cur) {
        parent = cur;
        if (key == cur->key) return root; // no duplicates
        if (key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    Node* node = new Node(key);
    node->parent = parent;
    if (key < parent->key) parent->left = node;
    else parent->right = node;
    return root;
}

// Recursive search
Node* bstSearchRec(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return bstSearchRec(root->left, key);
    return bstSearchRec(root->right, key);
}

// Non-recursive search
Node* bstSearchIter(Node* root, int key) {
    Node* cur = root;
    while (cur && cur->key != key) {
        cur = (key < cur->key) ? cur->left : cur->right;
    }
    return cur;
}

// Minimum element (leftmost)
Node* bstMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// Maximum element (rightmost)
Node* bstMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

// Inorder successor
Node* inorderSuccessor(Node* node) {
    if (!node) return nullptr;
    // If right subtree exists, successor is min in right subtree
    if (node->right) return bstMin(node->right);
    // Otherwise go up until we find a node that is left child of its parent
    Node* p = node->parent;
    while (p && node == p->right) {
        node = p;
        p = p->parent;
    }
    return p;
}

// Inorder predecessor
Node* inorderPredecessor(Node* node) {
    if (!node) return nullptr;
    if (node->left) {
        Node* p = node->left;
        while (p->right) p = p->right;
        return p;
    }
    Node* p = node->parent;
    while (p && node == p->left) {
        node = p;
        p = p->parent;
    }
    return p;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->key << ' ';
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;
    int vals[] = {20, 8, 22, 4, 12, 10, 14};
    for (int v : vals) root = bstInsert(root, v);

    cout << "Inorder traversal: "; inorderPrint(root); cout << '\n';

    int target = 10;
    Node* r1 = bstSearchRec(root, target);
    cout << "Recursive search " << target << (r1 ? " found\n" : " not found\n");

    Node* r2 = bstSearchIter(root, 12);
    cout << "Iterative search 12" << (r2 ? " found\n" : " not found\n");

    cout << "Minimum: " << bstMin(root)->key << '\n';
    cout << "Maximum: " << bstMax(root)->key << '\n';

    Node* n = bstSearchIter(root, 12);
    if (n) {
        Node* succ = inorderSuccessor(n);
        Node* pred = inorderPredecessor(n);
        cout << "Node 12 successor: " << (succ ? to_string(succ->key) : string("None")) << '\n';
        cout << "Node 12 predecessor: " << (pred ? to_string(pred->key) : string("None")) << '\n';
    }
    return 0;
}
