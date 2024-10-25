#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
Node* deleteNode(Node* head, int position) {
    if (head == NULL) {  
        return head;
    }
    Node* temp = head;
    if (position == 1) {
        head = temp->next;  
        if (head != NULL) {
            head->prev = NULL; 
        }
        delete temp;  
        return head;
    }
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;  
    } else {
        cout << "Position out of range" << endl;
    }
    return head;
}
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
    head->next->prev = head;
    head->next->next = new Node(33);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(44);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(55);
    head->next->next->next->next->prev = head->next->next->next;
    cout << "Original Doubly Linked List: ";
    printList(head);
    int position = 2;
    head = deleteNode(head, position);
    cout << "Doubly Linked List after deleting position " << position << ": ";
    printList(head);
    return 0;
}

