#include <iostream>
using namespace std;

class Student {
public:
    int id;
    string name;
    Student* next;

    Student(int i, string n) {
        id = i;
        name = n;
        next = NULL;
    }
};

class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = NULL;
    }

    // Insert student
    void insert() {
        int id;
        string name;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;

        Student* newStudent = new Student(id, name);

        if (head == NULL) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }

        cout << "Student Added Successfully!\n";
    }

    // Display students
    void display() {
        if (head == NULL) {
            cout << "No records found.\n";
            return;
        }

        Student* temp = head;
        while (temp != NULL) {
            cout << temp->id << " - " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Search student
    void search() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        Student* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Found: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Student not found.\n";
    }

    // Delete student
    void remove() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->id == id) {
            head = head->next;
            cout << "Deleted successfully.\n";
            return;
        }

        Student* temp = head;
        while (temp->next != NULL && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->next = temp->next->next;
            cout << "Deleted successfully.\n";
        } else {
            cout << "Student not found.\n";
        }
    }
};

int main() {
    StudentList list;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Insert Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.insert();
                break;
            case 2:
                list.display();
                break;
            case 3:
                list.search();
                break;
            case 4:
                list.remove();
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
