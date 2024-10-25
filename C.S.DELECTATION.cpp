#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = NULL;
    }

    void createInitialList(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insertAtEnd(arr[i]);
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void deleteAtStart() {
        if (last == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = last->next;
        if (last == last->next) { 
            delete last;
            last = NULL;
        } else {
            last->next = temp->next;
            delete temp;
        }
    }

    void deleteAtMiddle() {
        if (last == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (last == last->next) { 
            deleteAtStart();
            return;
        }

        Node* slow = last->next;
        Node* fast = last->next;

        while (fast != last && fast->next != last) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* temp = slow->next;
        slow->next = temp->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (last == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (last == last->next) {
            delete last;
            last = NULL;
        } else {
            Node* temp = last->next;
            while (temp->next != last) {
                temp = temp->next;
            }
            temp->next = last->next;
            delete last;
            last = temp;
        }
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next; 
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    int arr[] = {22, 44, 55, 66, 77};
    int n = sizeof(arr) / sizeof(arr[0]);

    list.createInitialList(arr, n);

    cout << "Initial Circular Linked List: ";
    list.display();

    int choice;
    cout << "\nWhere would you like to delete a number?" << endl;
    cout << "1. Delete from the start\n2. Delete from the middle\n3. Delete from the end" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        list.deleteAtStart();
    } else if (choice == 2) {
        list.deleteAtMiddle();
    } else if (choice == 2) {
        list.deleteAtEnd();
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "\nCircular Linked List after deletion: ";
    list.display();

    return 0;
}

