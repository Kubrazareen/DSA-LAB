#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
Node* removeLastNode(struct Node* head)
{
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* second_last = head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    delete (second_last->next);
    second_last->next = NULL;
    return head;
}
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node* head = new Node(21);
    head->next = new Node(32);
    head->next->next = new Node(83);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(52);
    cout << "Original list: ";
    printList(head);
    head = removeLastNode(head);
    cout << "List after removing the last node: ";
    printList(head);
    return 0;
}

