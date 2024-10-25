#include <iostream>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *insertInMiddle(Node *head, int x) {
    if (head == NULL) {
        return new Node(x);
    }
    Node *newNode = new Node(x);
    Node *currNode = head;
    int len = 0;
    while (currNode != NULL) {
        len++;
        currNode = currNode->next;
    }
      int mid;
    if (len % 2 == 0) {
        mid = len / 2;
    }
    else {
        mid = (len + 1) / 2;
    }
    currNode = head;
    while (mid > 1) {
        currNode = currNode->next;
          mid--;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}
void printList(Node *head) {
      Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    Node *head = new Node(13);
    head->next = new Node(22);
    head->next->next = new Node(45);
    head->next->next->next = new Node(59);
    int x = 3;
    head = insertInMiddle(head, x);
    printList(head);
    return 0;
}

