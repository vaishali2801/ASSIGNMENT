#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() {
        head = nullptr;
    }
    void Append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void Insert_at_beginning(int val) {
        Node* n1 = new Node(val);
        n1->next = head;
        head = n1;
    }

    bool Search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void Delete_node(int key) {
        if (head == nullptr)
         return;

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return; 

        prev->next = curr->next;
        delete curr;
    }

    void Reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, key;

    do {
        cout << "\n--- Linked List Menu ---" << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Reverse List" << endl;
        cout << "6. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to append: ";
            cin >> value;
            list.Append(value);
            cout << "value is append...!" << endl;
            break;

        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.Insert_at_beginning(value);
            cout << "value is inserted...!" << endl;
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> key;
            if (list.Search(key))
                cout << key << " found in list." << endl;
            else
                cout << key << " not found in list." << endl;
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> key;
            list.Delete_node(key);
            cout << "value is deleted..!" << endl;
            break;

        case 5:
            list.Reverse();
            cout << "List reversed.you can pressed 6 for display...!" << endl;
            break;

        case 6:
            cout << "Linked List: ";
            list.Display();
            break;

        default:
            cout << "Invalid choice! Press another key...!" << endl;
        }
    } while (choice != 0);

    return 0;
}
