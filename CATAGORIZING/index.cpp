#include <iostream>
#include <vector>
using namespace std;

// ---------- Selection Sort ----------
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int small = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}
//--------- merge sort ----------
void merge(vector<int> &arr, int start, int mid, int end)
{

    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
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
int linearSearch(const vector<int> &arr, int sValue)
{

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] == sValue)
        {
            return i;
        }
    }
    return -1;
}
int binarysearch(const vector<int> &arr, int start, int end, int svalue)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == svalue)
        {
            return mid;
        }
        else if (arr[mid] < svalue)
        {
            return binarysearch(arr, mid + 1, end, svalue);
        }
        else
        {
            return binarysearch(arr, start, mid - 1, svalue);
        }
        return -1;
    }
}
void display(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> arr;
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;
    arr.resize(n);

    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter array :";
        cin >> arr[i];
    }

    do
    {
        cout << endl
             << "--- MENU ---" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Binary Search " << endl;
        cout << "5. Display Array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            selectionSort(arr);
            cout << "Array sorted using Selection Sort." << endl;
            break;
        case 2:
            mergesort(arr, 0, arr.size() - 1);
            cout << "Array sorted using Merge Sort." << endl;
            break;
        case 3:
        {
            int key;
            cout << "Enter element to search: ";
            cin >> key;
            int idx = linearSearch(arr, key);
            if (idx == -1)
            {
                cout << "no founded";
            }
            else
            {
                cout << key << " is located at index position " << idx << endl;
            }
            break;
        }
        case 4:
        {
            int key;
            cout << "Enter element to search: ";
            cin >> key;
            cout << "Note: Array must be sorted for Binary Search!"<< endl;
            int idx = binarysearch(arr,0,arr.size()-1,key);

            if (idx != -1)
                cout << "Element found at index " << idx << endl;
            else
                cout << "Element not found.\n";
            break;
        }
        case 5:
            cout << "Array: ";
            display(arr);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
