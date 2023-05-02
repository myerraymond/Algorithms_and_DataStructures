#include <iostream>

using namespace std;

class AVLTree {
private:
    struct Node {
        int key;
        int height;
        Node* left;
        Node* right;

        Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        Node* subtree = newRoot->right;

        newRoot->right = node;
        node->left = subtree;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        Node* subtree = newRoot->left;

        newRoot->left = node;
        node->right = subtree;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

        return newRoot;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        else {
            return node;
        }

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) {
            return rotateRight(node);
        }

        if (balance < -1 && key > node->right->key) {
            return rotateLeft(node);
        }

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void print(Node* node, int indent = 0) {
        if (node == nullptr) {
            return;
        }
        if (node->right != nullptr) {
            print(node->right, indent + 4);
        }
        std::cout << std::string(indent, ' ') << node->key << std::endl;
        if (node->left != nullptr) {
            print(node->left, indent + 4);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void print() {
        print(root);
    }
};
