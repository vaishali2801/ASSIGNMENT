#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class linkedlist
{
private:
    Node *head;

public:
    linkedlist()
    {
        head = nullptr;
    }

    void insertbegining(int value)
    {
        Node *ptr = new Node(value);
        ptr->next = head;
        head = ptr;
    }

    void deletestart()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = temp->next;
        delete temp;
    }

    void Addlinkedlist(int value, int pos)
    {
        if (pos == 0)
        {
            insertbegining(value);
            return;
        }

        Node *ptr = new Node(value);
        Node *temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Out of range" << endl;
            return;
        }

        ptr->next = temp->next;
        temp->next = ptr;
    }

    void Updatelinkedlist(int newvalue, int pos)
    {
        if (head == nullptr)
        {
            cout << "Linked list is Empty." << endl;
            return;
        }
        Node *temp = head;

        for (int i = 0; i < pos && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Out of range" << endl;
            return;
        }
        temp->data = newvalue;
    }

    void Delete(int pos)
    {
        if (head == nullptr)
        {
            cout << "Linked list is Empty." << endl;
            return;
        }
        if (pos == 0)
        {
            deletestart();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Out of range" << endl;
            return;
        }
        Node *n1 = temp->next;
        temp->next = n1->next;
        delete n1;
    }

    void Displaylinkedlist()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= end)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
    {
        arr[start + k] = temp[k];
    }
}

void mergesort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int partition(vector<int> &arr, int start, int end)
{
    int idx = start - 1;
    int pivot = arr[end];
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quicksort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pidx = partition(arr, start, end);
        quicksort(arr, start, pidx - 1);
        quicksort(arr, pidx + 1, end);
    }
}

int binarysearch(const vector<int> &arr, int start, int end, int svalue)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == svalue)
            return mid;
        else if (arr[mid] < svalue)
            return binarysearch(arr, mid + 1, end, svalue);
        else
            return binarysearch(arr, start, mid - 1, svalue);
    }
    return -1;
}

void Display(vector<int> &arr)
{
    cout << "Array elements: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}
int main()
{
    int choice, ch, data, pos, newvalue;
    linkedlist l1;
    vector<int> arr;

    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    while (1)
    {
        cout << endl
             << "==============MENU=============" << endl;
        cout << "press 1 for linked list" << endl;
        cout << "press 2 for merge sort" << endl;
        cout << " press 3 for quick sort" << endl;
        cout << " press 4 for binary search" << endl;
        cout << " press 5 for Display linked list" << endl;
        cout << " press 6 for Display array" << endl;
        cout << "press 7 for exit" << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            while (1)
            {
                cout << endl<<"===========linked list menu============" << endl;
                cout << "press 1 for Add in linked list" << endl;
                cout << "press 2 for Update in linked list" << endl;
                cout << "press 3 for Delete in linked list" << endl;
                cout << "press 0 for exit " << endl;
                cout << endl <<"Enter your operation: ";
                cin >> ch;

                if (ch == 0)
                    break;

                switch (ch)
                {
                case 1:
                    cout << "Enter data to be inserted :";
                    cin >> data;
                    cout << "Enter position: ";
                    cin >> pos;
                    l1.Addlinkedlist(data, pos);
                    break;
                case 2:
                    cout << "Enter new data: ";
                    cin >> newvalue;
                    cout << "Enter position: ";
                    cin >> pos;
                    l1.Updatelinkedlist(newvalue, pos);
                    break;
                case 3:
                    cout << "Enter position: ";
                    cin >> pos;
                    l1.Delete(pos);
                    break;
                default:
                    cout << "invalid choice..!please Enter another key." << endl;
                }
            }
            break;
        case 2:
            mergesort(arr, 0, arr.size() - 1);
            cout << "Array sorted with Merge Sort." << endl;
            break;
        case 3:
            quicksort(arr, 0, arr.size() - 1);
            cout << "Array sorted with Quick Sort." << endl;
            break;
        case 4:
        {
            int svalue;
            cout << "Enter value to search: ";
            cin >> svalue;
            int idx = binarysearch(arr, 0, arr.size() - 1, svalue);
            if (idx == -1)
                cout << "Element not found." << endl;
            else
                cout << svalue << " found at index " << idx << endl;
            break;
        }
        case 5:
            l1.Displaylinkedlist();
            break;
        case 6:
            Display(arr);
            break;
        case 7:
            exit(0);
        default:
            cout << "You Enter invalid key..!" << endl;
        }
    }
    return 0;
}
