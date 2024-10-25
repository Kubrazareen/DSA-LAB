#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        data = new_data;
        next = NULL;
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
    return head;
}
void printList(Node* node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}
int main() {
    Node* head = new Node(22);
    head->next = new Node(33);
    head->next->next = new Node(44);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(66);
    cout << "Original Linked list is:";
    printList(head);
    head = append(head, 11);
    cout << "\nAfter inserting 1 at the end:";
    printList(head);
    return 0;
}

