#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
class Student {
private:
    T id;
    string name;

public:
    // Constructor
    Student(T i, string n) {
        id = i;
        name = n;
    }

    // Display method
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    // Getter for ID
    T getId() const {
        return id;
    }
};

// Add a student to vector
template <class T>
void AddStudent(vector<Student<T>>& list, T id, string name) {
    Student<T> s(id, name);
    list.push_back(s);
    cout << "Student added successfully.\n";
}

// Display all students
template <class T>
void DisplayStudents(const vector<Student<T>>& list) {
    cout << "All Students:\n";
    for (const auto& s : list) {
        s.display();
    }
}

// Remove student by ID
template <class T>
void RemoveStudentById(vector<Student<T>>& list, T id) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->getId() == id) {
            list.erase(it);
            cout << "Student with ID " << id << " removed.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Search student by ID
template <class T>
void SearchStudentById(const vector<Student<T>>& list, T id) {
    for (const auto& s : list) {
        if (s.getId() == id) {
            cout << "Student found: ";
            s.display();
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

// Main Function
int main() {
    vector<Student<int>> studentList;

    AddStudent(studentList, 1, "Vaishali");
    AddStudent(studentList, 2, "bhoomi");

    DisplayStudents(studentList);

    SearchStudentById(studentList, 2);
    RemoveStudentById(studentList, 1);

    DisplayStudents(studentList);

    return 0;
}
