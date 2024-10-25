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
Node* deleteHead(Node* head) {
    if (head == NULL)  
        return NULL;
    Node* temp = head;  
    head = head->next;  
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp; 
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    cout << "Original Doubly Linked List: ";
    printList(head);
    head = deleteHead(head);
    cout << "Doubly Linked List after deleting the head: ";
    printList(head);
    return 0;
}

