#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void reverseBST(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Swap the left and right child nodes of the current node
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively reverse the left and right subtrees
    reverseBST(root->left);
    reverseBST(root->right);
}

// Helper function to print the binary search tree inorder
void printInorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
        Example binary search tree:
                4
               / \
              2   5
             / \
            1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);

    cout << "Original tree inorder traversal: ";
    printInorder(root);
    cout << endl;

    reverseBST(root);

    cout << "Reversed tree inorder traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
}
