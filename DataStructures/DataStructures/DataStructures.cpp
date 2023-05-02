#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Define a node class for a linked list
class Node {
public:
    int data;
    Node* next;
};

// Define a node class for a binary tree
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Traverse a linked list
void print_linked_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Traverse a binary tree using inorder traversal
void inorder_traversal(TreeNode* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        cout << node->data << " ";
        inorder_traversal(node->right);
    }
}


int main() {
    // Arrays
    int my_array[] = { 1, 2, 3, 4, 5 };
    cout << "Array: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << my_array[i] << " ";
    }
    cout << endl;

    // Linked Lists
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = NULL;
    cout << "Linked List: " << endl;
    print_linked_list(head);

    // Stacks
    stack<int> my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    cout << "Stack: " << endl;
    while (!my_stack.empty()) {
        cout << my_stack.top() << " ";
        my_stack.pop();
    }
    cout << endl;

    // Queues
    queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);
    cout << "Queue: " << endl;
    while (!my_queue.empty()) {
        cout << my_queue.front() << " ";
        my_queue.pop();
    }
    cout << endl;

    // Binary Trees
    TreeNode* root = new TreeNode();
    root->data = 1;
    root->left = new TreeNode();
    root->left->data = 2;
    root->right = new TreeNode();
    root->right->data = 3;
    root->left->left = new TreeNode();
    root->left->left->data = 4;
    root->left->right = new TreeNode();
    root->left->right->data = 5;
    cout << "Binary Tree: " << endl;
    inorder_traversal(root);
    cout << endl;

}
