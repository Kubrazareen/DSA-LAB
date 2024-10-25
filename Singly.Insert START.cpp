#include <iostream>
using namespace std;
struct Node {
    int data; 
    Node* next; 
    Node(int new_data)
    {
        data = new_data;
        next = NULL; 
    }
};
Node* insertAtFront(Node* head, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}
void printList(Node* head)
{
    Node* curr = head;
    while (curr != NULL	) {
        cout << " " << curr->data;
        curr = curr->next;
    }

    cout << endl;
}
int main()
{
    Node* head = new Node(12);
    head->next = new Node(13);
    head->next->next = new Node(14);
    head->next->next->next = new Node(15);

    cout << "Original Linked List:";
    printList(head);
    cout << "After inserting Nodes at the front:";
    int data = 11;
    head = insertAtFront(head, data);
    printList(head);
    return 0;
}

