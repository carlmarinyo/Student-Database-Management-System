#include <iostream>
#include <cstring>
using namespace std;
 
const int maximum = 100;
struct Student{
    int studentID;
    char firstName[50];       // student structure
    char lastName[50];
    float GPA;

};
Student students;

void addStudent(Student students[], int &numStudents) {
    system("cls");
cout<<"------------------------------\n\tAdd Student\n------------------------------"<<endl;
    if (numStudents > 100) {
        system("cls");
        cout<<"Maximum limit has been reached.";  //prohibits entry when there are already 100 students
    }
    else {
    cout<<"Enter student ID: ";
    cin>>students[numStudents].studentID;
    cout<<"Enter student first name: ";
    cin.ignore();
    cin.get(students[numStudents].firstName, 50);
    cout<<"Enter student last name: ";
    cin.ignore();
    cin.get(students[numStudents].lastName, 50);
    cout<<"Enter GPA: ";
    cin>>(students[numStudents].GPA);
    numStudents++;
    system("cls");
    cout<<"Student successfully added."<<endl;
    }
    
}

void displayStudents(const Student students[], int numStudents) {
    system("cls");
    cout<<"------------------------------\n\tDisplay Student\n------------------------------"<<endl;
    if (numStudents == 0) {  // checks if there are student records before proceeding
        system("cls");            
        cout<<"No student record yet."<<endl;
    }
    else {
        for (int i = 0; i < numStudents; i++) {
            cout<<"Student ["<<i+1<<"]";                      // loops through each student array to display info
            cout<<"\nFirst name: "<<students[i].firstName;
            cout<<"\nLast name: "<<students[i].lastName;
            cout<<"\nGPA: "<<students[i].GPA<<"\n\n";
        }
    }   
}

float calculateAverageGPA(const Student students[], int numStudents) {
    system("cls");
    cout<<"\n------------------------------\n   Calculate average GPA\n------------------------------"<<endl;
float sum = 0, average = 0;
        for (int i = 0; i < numStudents; i++) {  // loops through every student gpa and sums it up before dividing it  
            sum +=students[i].GPA;           // to the number of students to get the average
        }
        return sum / numStudents;
    }

void findStudentsByLastName(const Student students[], int numStudents, const char lastName[]) {
    system("cls");
    cout<<"------------------------------\n\tFind by Last Name\n------------------------------"<<endl;
    if (numStudents == 0) { // checks if there are student records before proceeding
        system("cls");
        cout<<"No student record yet."<<endl; 
    }
    else {
    char name[50];
    cout<<"Input last name to find student: ";
        cin.ignore();
        cin.get(name,50);
        for (int i = 0; i < numStudents; i++) {   // loops through every student to access each of their last names
        
            if (strcmp(name, students[i].lastName) == 0) { // compares the inputted surname to the current last name on 
            cout<<"\nStudent with the surname "<<students[i].lastName;; // array structure to check if the inputted
            cout<<"\nFirst name: "<<students[i].firstName; // surname is in the list of added students
            cout<<"\nLast name: "<<students[i].lastName;
            cout<<"\nGPA: "<<students[i].GPA<<endl;
            }    
            }
        }   
    }
    
int main() {
    Student students[maximum];
    int choice, numStudents = 0;
    float average = 0, sum = 0;
    do {
        cout<<"------------------------------\n\t   MENU\n------------------------------"<<endl;
    cout<<"1. Add student\n2. Display all students\n3. Calculate Average GPA\n4. Find students by Last Name\n5. Exit\nYour Choice: ";
cin>>choice;
while (choice < 1 || choice > 5) {
    cout<<"Choose from 1-5 only: ";
    cin>>choice;
}
switch (choice) {
    case 1: 
    addStudent(students, numStudents);
    break;
    case 2:
    displayStudents(students, numStudents);
    break;
    case 3:
    if (numStudents == 0) {
        system("cls"); // checks if there are student records before proceeding
        cout<<"No student record yet."<<endl;
        
    }
    else {
    average = calculateAverageGPA(students, numStudents); // used the return value of calculate average function 
    cout<<"Average of ["<<numStudents<<"] student(s) is "<<average<<"\n\n";
    }
    break;
    case 4:
    findStudentsByLastName(students, numStudents, students[0].lastName);
    break;
    case 5:
        cout<<"\nThank you for using the program!";
    break;
}   
    }
while (choice != 5); //loops the whole program unless 5 is inputted on menu(exit)
    return 0;
}

