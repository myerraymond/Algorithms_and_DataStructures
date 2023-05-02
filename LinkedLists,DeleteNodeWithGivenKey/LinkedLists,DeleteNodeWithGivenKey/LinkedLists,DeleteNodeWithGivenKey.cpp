
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void deleteNode(Node*& head, int key) {
    if (head == nullptr) return; // empty list

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != key) {
        curr = curr->next;
    }
    if (curr->next == nullptr) return; // key not found
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}


    int main() {
        Node* head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        head->next->next->next = new Node(7);
        head->next->next->next->next = new Node(26);
        head->next->next->next->next->next = new Node(45);
        head->next->next->next->next->next->next = new Node(54);

        std::cout << "Before deletion: ";
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;

        deleteNode(head, 26);

        std::cout << "After deletion: ";
        curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;

        // don't forget to deallocate memory!
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        return 0;

}
