#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Std {
public:
    int id;
    string name;

    Std(int id, string name) {
        this->id = id;
        this->name = name;
    }

    int getId() {  
        return id;
    }
};

class List {
public:
    vector<Std> list;

    List(){}

    void AddStudent(int id, string name) 
    {
        Std s(id, name);
        list.push_back(s);
        cout << "Student added successfully...!" << endl;
    }

    void SearchStudentById(int id) 
    {
        for (Std &e : this->list) {
            if (e.getId() == id) {
                cout << e.id << " | " << e.name << endl;
            }
        }
    }

    void RemoveStudent(int id) {
       
        for (int i = 0; i < list.size(); i++) 
        { 
            if (list[i].id == id) {
                list.erase(list.begin() + i);
                cout << "Student with ID " << id << " removed successfully..!" << endl;
            }
        }
    }

    void DisplayStudents() {
        if (list.empty()) 
        {
            cout << "No students to display." << endl;
        } 
        else{
            cout << "All Students: " << endl;
            for (Std &e : list) {
                cout << "ID : " << e.id << " , Name: " << e.name << endl;
            }
        }
    }
};
int main() {
    int id;
    string name;
    int choice;
    List list;

    while (choice != 0) {
        cout << "====================================" << endl;
        cout << "Press 1 for Add a Student." << endl;
        cout << "Press 2 for Display Students." << endl;
        cout << "Press 3 for Remove Student." << endl;
        cout << "Press 4 for Search Student by ID." << endl;
        cout << "Press 0 for Exit." << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        cout << "====================================" << endl;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Student name: ";
                cin >> name;
                list.AddStudent(id, name);
                break;
            case 2:
                list.DisplayStudents();
                break;
            case 3:
                cout << "Enter ID: ";
                cin >> id;
                list.RemoveStudent(id);
                break;
            case 4:
                cout << "Enter ID: ";
                cin >> id;
                list.SearchStudentById(id);
                break;
            default:
                cout << "Invalid choice.Please Try again." << endl;
        }
    }

    return 0;
}
