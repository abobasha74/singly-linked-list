#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert At Beginning
void insertAtBeginning(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " inserted at the beginning.\n";
}

// Insert At End
void insertAtEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    cout << value << " inserted at the end.\n";
}

// Delete
void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    Node *current = head;
    Node *prev = NULL;

    if (current->data == value)
    {
        head = current->next;
        delete current;
        cout << value << " deleted successfully.\n";
        return;
    }

    while (current != NULL && current->data != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "Value not found.\n";
        return;
    }

    prev->next = current->next;
    delete current;
    cout << value << " deleted successfully.\n";
}

// Display
void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

int main()
{
    int choice, value;

    do
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete by value\n";
        cout << "4. Display list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
            break;

        case 4:
            cout << "Linked List: ";
            display();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
