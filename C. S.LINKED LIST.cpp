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
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (last == NULL) { 
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }
    void insertAtMiddle(int value) {
        if (last == NULL) { 
            insertAtStart(value);
            return;
        }

        Node* slow = last->next;
        Node* fast = last->next;

        // Find the middle of the list
        while (fast != last && fast->next != last) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newNode = new Node(value);
        newNode->next = slow->next;
        slow->next = newNode;
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

    // Initial array elements
    int arr[] = {22, 44, 55, 66, 77};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Create the initial list from array
    list.createInitialList(arr, n);

    cout << "Initial Circular Linked List: ";
    list.display();

    int choice, value;
    cout << "\nWhere would you like to insert the new number?" << endl;
    cout << "1. Insert at the start\n2. Insert in the middle\n3. Insert at the end" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the number to insert: ";
    cin >> value;

    if (choice == 1) {
        list.insertAtStart(value);
    } else if (choice == 2) {
        list.insertAtMiddle(value);
    } else if (choice == 3) {
        list.insertAtEnd(value);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "\nCircular Linked List after insertion: ";
    list.display();

    return 0;
}

