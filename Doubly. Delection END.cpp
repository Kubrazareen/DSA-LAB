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
Node* removeLastNode(Node* head) {
    if (head == NULL) {
        return NULL; 
    }
    if (head->next == NULL) {
        delete head;  
        return NULL;
    }
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    Node* second_last = last->prev;  
    delete last;
    if (second_last != NULL) {
        second_last->next = NULL;  
    }
    return head;
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = new Node(21);
    head->next = new Node(32);
    head->next->prev = head;
    head->next->next = new Node(83);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(52);
    head->next->next->next->next->prev = head->next->next->next;
    cout << "Original Doubly Linked List: ";
    printList(head);
    head = removeLastNode(head);
    cout << "Doubly Linked List after removing the last node: ";
    printList(head);
    return 0;
}

