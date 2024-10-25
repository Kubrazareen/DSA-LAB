#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int new_data) {
        data = new_data;
        next = NULL;
        prev = NULL;
    }
};
Node* append(Node* head, int new_data) {
    Node* new_node = new Node(new_data);  
    if (head == NULL) {
        return new_node;
}
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return head;
}
void printList(Node* node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(22);
    head->next = new Node(33);
    head->next->prev = head;
    head->next->next = new Node(44);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(66);
    head->next->next->next->next->prev = head->next->next->next;
    cout << "Original Doubly Linked List is:";
    printList(head);
    head = append(head, 11);
    cout << "\nAfter inserting 11 at the end:";
    printList(head);
    return 0;
}

