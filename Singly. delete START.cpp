#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};
Node* deleteHead(Node* head)
{
    if (head == NULL)
        return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
void printList(Node* head)
{ while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original list: ";
    printList(head);
    head = deleteHead(head);
    cout << "List after deleting the head: ";
    printList(head);
    return 0;
}
