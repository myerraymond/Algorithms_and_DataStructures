#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// define a node class for a linked list 
class Node {
public:
	int data;
	Node* next;
};

// define a node class for a binary tree
class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
};

//traverese a linked list
void print_linked_list(Node* head) {
	Node* current = head;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

//traverse a binary tree using inorder traversal
void inorder_traversal(TreeNode* node) {
	if (node != NULL) {
		inorder_traversal(node->left);
		cout << node->data << " ";
		inorder_traversal(node->right);
	}
}


//Binary Search with array
int binarySearch(int arrb[], int n, int x) {
	int lower = 0;
	int upper = n - 1;
	while (lower <= upper) {
		int mid = (lower + upper) / 2;
		if (arrb[mid] == x) {
			return mid;
		}
		else if (arrb[mid] < x) {
			lower = mid + 1;
		}
		else {
			upper = mid - 1;
		}
	}
	return -1; //value not found
}


//LinearSearch with array
int linearSearch(int arr[], int a, int b) {
	for (int i = 0; i < a; i++) {
		if (arr[i] == b) {
			return i;
		}
	}
	return -1; //value not found
}

//SortinAlgo
void selectionSort(int arra[], int p) {
	int i, j, minIndex, tmp;
	for (i = 0; i < p - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < p; j++) 
			if (arra[j] < arra[minIndex]) 
				minIndex = j;
			if (minIndex != i) {
				tmp = arra[i];
				arra[i] = arra[minIndex];
				arra[minIndex] = tmp;
			}
	}
}

//Bubble sort
void bubbleSort(int arrc[], int w) {
	for (int i = 0; i < w - 1; i++) {
		for (int j = 0; j < w - i - 1; j++) {
			if (arrc[j] > arrc[j + 1]) {
				//Swapp arrc[j] and arrc[j+1]
				int temp = arrc[j];
				arrc[j] = arrc[j + 1];
				arrc[j + 1] = temp;
			}
		}
	}
	return;
}


//Insert sorting algo

void insertionSort(vector<int>& ar) {
	int n = ar.size();
	for (int i = 1; i < n; ++i) {
		int key = ar[i];
		int j = i - 1;

		while (j >= 0 && ar[j] > key) {
			ar[j + 1] = ar[j];
			--j;
		}
		ar[j + 1] = key;
	}

}



int main() {
	//Arrays
	int my_array[] = { 1, 2, 3, 4, 5 };
	cout << "Array: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << my_array[i] << " ";
	}
	cout << endl;

	//Linked Lists
	Node* head = new Node();
	head->data = 1;
	head->next = new Node();
	head->next->data = 2;
	head->next->next = new Node();
	head->next->next->data = 3;
	head->next->next->next = NULL;
	cout << "Linked List: " << endl;
	print_linked_list(head);

	//Stacks
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

	//Queues
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

	//Binary Trees
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
	cout << endl;

	//Binary Search with array
	int arrb[] = { 2, 3, 4, 5, 8 };
	int n = sizeof(arrb) / sizeof(arrb[0]);
	int x = 8;
	int result = binarySearch(arrb, n, x);
	if (result == -1) {
		cout << "Value not found" << endl;
	}
	else {
		cout << "Value found at index " << result << endl;
	}
	cout << endl;

	//LinearSearch //way quicker
	int arr[] = { 2, 3, 4, 5, 8 };
	int a = sizeof(arr) / sizeof(arr[0]);
	int b = 4;
	int result1 = linearSearch(arr, a, b);

	if (result1 == -1) {
		cout << "Value not found" << endl;
	}
	else {
		cout << "Value found at index " << result1 << endl;
	}

	cout << endl;

	//SelectionSortAlgo
	int arra[] = { 10, 2, 4, 6, 3, 8, 1, 7, 9, 5 };
	int p = sizeof(arra) / sizeof(arra[0]);

	selectionSort(arra, p);
	cout << "Selection Sorted array: " << endl;
	for (int i = 0; i < p; i++) {
		cout << arra[i] << " ";
	}
	cout << endl;
	cout << endl;

	//Bubble Sort
	int arrc[] = { 5, 4, 6, 3, 2 , 7, 8, };
	int w = sizeof(arrc) / sizeof(arrc[0]);
	bubbleSort(arrc, w);
	cout << "Bubble Sorted array: ";
	for (int i = 0; i < w; i++) {
		cout << arrc[i] << " ";
	}
	cout << endl;
	cout << endl;

	//InsertSort
	vector<int> ar = { 4,5,6,7,8,3,5,3 };
	insertionSort(ar);

	cout << "Insert Sorted array: ";
	for (int i = 0; i < ar.size(); i++) {
		cout << ar[i] << " ";
	}

	cout << endl;


}
