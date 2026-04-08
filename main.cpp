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

    // Insert
    void insert(int id, string name) {
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
    }

    // Display
    void display() {
        Student* temp = head;
        while (temp != NULL) {
            cout << temp->id << " - " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Search
    void search(int id) {
        Student* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Found: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found" << endl;
    }

    // Delete
    void remove(int id) {
        if (head == NULL) return;

        if (head->id == id) {
            head = head->next;
            return;
        }

        Student* temp = head;
        while (temp->next != NULL && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->next = temp->next->next;
        }
    }
};

int main() {
    StudentList list;

    list.insert(1, "Ali");
    list.insert(2, "Sara");
    list.insert(3, "Ahmed");

    list.display();

    list.search(2);
    list.remove(2);

    cout << "After deletion:\n";
    list.display();

    return 0;
}
