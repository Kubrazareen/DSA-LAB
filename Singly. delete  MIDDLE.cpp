#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize node data and pointer
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to delete a node at a given position
Node* deleteNode(Node* head, int position) {
    Node* prev;
    Node* temp = head;
    
    if (temp == NULL) {
        return head;  // If list is empty, return head
    }

    // If the node to be deleted is the head node
    if (position == 1) {
        head = temp->next;  // Update head to next node
        delete temp;  // Properly delete the node
        return head;
    }

    // Traverse to the node at the given position
    for (int i = 1; i != position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If temp is not null, perform deletion
    if (temp != NULL) {
        prev->next = temp->next;  // Update the link of the previous node
        delete temp;  // Properly delete the node
    } else {
        cout << "Position out of range" << endl;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);
    head->next->next->next = new Node(44);
    head->next->next->next->next = new Node(55);
    
    cout << "Original list: ";
    printList(head);
    
    int position = 2;
    head = deleteNode(head, position);  // Delete node at position 2
    
    cout << "List after deletion: ";
    printList(head);
    
    return 0;
}

