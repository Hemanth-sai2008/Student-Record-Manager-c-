#include <iostream>
#include <string>
using namespace std;

const int SUBJECTS = 5;
const int MAX_MARKS = 100;

// Student class
class Student {
public:
    int rollNo;
    string name;
    float marks[SUBJECTS];

    // Function to input student details
    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        string subjects[SUBJECTS] = {
            "C++",
            "DSA",
            "Java",
            "English",
            "DAE"
        };

        cout << "\nEnter Marks (Maximum 100 for each subject):\n";

        for (int i = 0; i < SUBJECTS; i++) {
            do {
                cout << subjects[i] << ": ";
                cin >> marks[i];

                if (marks[i] < 0 || marks[i] > MAX_MARKS) {
                    cout << "Invalid marks! Enter marks between 0 and 50.\n";
                }

            } while (marks[i] < 0 || marks[i] > MAX_MARKS);
        }
    }

    // Function to display student details
    void display() {
        string subjects[SUBJECTS] = {
            "C++",
            "DSA",
            "Java",
            "English",
            "DAE"
        };

        cout << "Roll No: " << rollNo << endl;
        cout << "Name   : " << name << endl;

        cout << "Marks:\n";

        for (int i = 0; i < SUBJECTS; i++) {
            cout << subjects[i] << " : " << marks[i] << "/50" << endl;
        }
    }
};


// Student Record Manager class
class StudentRecordManager {
private:
    Student students[100];
    int count;

public:

    // Constructor
    StudentRecordManager() {
        count = 0;
    }

    // Add a student
    void addStudent() {
        if (count >= 100) {
            cout << "\nStudent limit reached!\n";
            return;
        }

        cout << "\n--- Add Student ---\n";

        students[count].input();
        count++;

        cout << "\nStudent added successfully!\n";
    }

    // Display all students
    void displayStudents() {
        if (count == 0) {
            cout << "\nNo student records available.\n";
            return;
        }

        cout << "\n===== All Student Records =====\n";

        for (int i = 0; i < count; i++) {
            cout << "\nStudent " << i + 1 << endl;
            cout << "--------------------------\n";

            students[i].display();
        }
    }

    // Search student using roll number
    void searchStudent() {
        if (count == 0) {
            cout << "\nNo student records available.\n";
            return;
        }

        int roll;

        cout << "\nEnter Roll Number to Search: ";
        cin >> roll;

        for (int i = 0; i < count; i++) {

            if (students[i].rollNo == roll) {

                cout << "\nStudent Found!\n";
                cout << "--------------------------\n";

                students[i].display();

                return;
            }
        }

        cout << "\nStudent not found.\n";
    }

    // Find total, highest, lowest and average marks
    void marksAnalysis() {
        if (count == 0) {
            cout << "\nNo student records available.\n";
            return;
        }

        string subjects[SUBJECTS] = {
            "C++",
            "DSA",
            "Java",
            "English",
            "DAE"
        };

        cout << "\n===== Marks Analysis =====\n";

        for (int i = 0; i < count; i++) {

            float total = 0;
            float highest = students[i].marks[0];
            float lowest = students[i].marks[0];

            int highestSubject = 0;
            int lowestSubject = 0;

            for (int j = 0; j < SUBJECTS; j++) {

                total += students[i].marks[j];

                if (students[i].marks[j] > highest) {
                    highest = students[i].marks[j];
                    highestSubject = j;
                }

                if (students[i].marks[j] < lowest) {
                    lowest = students[i].marks[j];
                    lowestSubject = j;
                }
            }

            float average = total / SUBJECTS;

            cout << "\nStudent: " << students[i].name;
            cout << "\nRoll No: " << students[i].rollNo;

            cout << "\nTotal Marks: " << total << "/500";
            cout << "\nHighest Marks: " << highest
                 << " (" << subjects[highestSubject] << ")";

            cout << "\nLowest Marks: " << lowest
                 << " (" << subjects[lowestSubject] << ")";

            cout << "\nAverage Marks: " << average << "/100";

            cout << "\nPercentage: " << (total / 500) * 100 << "%";

            cout << "\n";
        }
    }

    // Update student details
    void updateStudent() {
        if (count == 0) {
            cout << "\nNo student records available.\n";
            return;
        }

        int roll;

        cout << "\nEnter Roll Number to Update: ";
        cin >> roll;

        for (int i = 0; i < count; i++) {

            if (students[i].rollNo == roll) {

                cout << "\nEnter New Details:\n";

                students[i].input();

                cout << "\nStudent details updated successfully!\n";

                return;
            }
        }

        cout << "\nStudent not found.\n";
    }

    // Delete student record
    void deleteStudent() {
        if (count == 0) {
            cout << "\nNo student records available.\n";
            return;
        }

        int roll;

        cout << "\nEnter Roll Number to Delete: ";
        cin >> roll;

        for (int i = 0; i < count; i++) {

            if (students[i].rollNo == roll) {

                // Shift remaining records
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }

                count--;

                cout << "\nStudent record deleted successfully!\n";

                return;
            }
        }

        cout << "\nStudent not found.\n";
    }

    // Display menu
    void menu() {

        int choice;

        do {

            cout << "\n\n================================";
            cout << "\n     STUDENT RECORD MANAGER";
            cout << "\n================================";

            cout << "\n1. Add Student";
            cout << "\n2. Display All Students";
            cout << "\n3. Search Student";
            cout << "\n4. Marks Analysis";
            cout << "\n5. Update Student";
            cout << "\n6. Delete Student";
            cout << "\n7. Exit";

            cout << "\n================================";

            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {

                case 1:
                    addStudent();
                    break;

                case 2:
                    displayStudents();
                    break;

                case 3:
                    searchStudent();
                    break;

                case 4:
                    marksAnalysis();
                    break;

                case 5:
                    updateStudent();
                    break;

                case 6:
                    deleteStudent();
                    break;

                case 7:
                    cout << "\nThank you for using Student Record Manager!\n";
                    break;

                default:
                    cout << "\nInvalid choice! Please try again.\n";
            }

        } while (choice != 7);
    }
};


// Main function
int main() {

    StudentRecordManager manager;

    manager.menu();

    return 0;
}