#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "DLList.h"
#include "student.h"

char getChoice();
void process(DLList<Student> &studentList);
void buildList(DLList<Student> &studentList);
void displayStudents(DLList<Student> &studentList);

void countStudents(DLList<Student> &studentList);
void addNewStudent(DLList<Student> &studentList);
void removeStudent(DLList<Student> &studentList);
void findStudent(DLList<Student> &studentList);

int main()
{
  DLList<Student> studentList;

  buildList(studentList);
  process(studentList);

  return 0;
}

char getChoice()
{
  char choice;
  bool valid;

  cout << "========MENU======\n"
       << " A:  Add a new Student \n"
       << " C:  Get the total number of Students \n"
       << " D:  Display the Student List \n"
       << " F:  Find a Student Record \n"
       << " R:  Remove a Student \n"
       << " Q: Quit  \n\n"
       << "Enter your choice: ";

  do
  {
    cin >> choice;
    choice = toupper(choice);

    switch (choice)
    {
    case 'A':
    case 'C':
    case 'D':
    case 'F':
    case 'R':
    case 'Q':
      valid = true;
      break;
    default:
      valid = false;
      cout << "\aInvalid choice\n"
           << "Please try again: ";
      break;
    }
  } while (!valid);

  return choice;
}

void process(DLList<Student> &studentList)
{
  char choice;

  do
  {
    choice = getChoice();

    switch (choice)
    {
    case 'A':
      addNewStudent(studentList);
      break;
    case 'C':
      countStudents(studentList);
      break;
    case 'D':
      displayStudents(studentList);
      break;
    case 'F':
      findStudent(studentList);
      break;
    case 'R':
      removeStudent(studentList);
      break;
    case 'Q':
      break;
    }
  } while (choice != 'Q');
}

void buildList(DLList<Student> &studentList)
{
  Student student;
  ifstream studentData;

  studentData.open("studentFile.txt");

  while (studentData >> student.id)
  {
    studentData.ignore();
    studentData.getline(student.name, 100);
    studentData.getline(student.cityState, 100);
    studentData >> student.phone >> student.gender >> student.year >> student.credits >> student.gpa >> student.major;

    studentList.insert(student);
  }

  studentData.close();
}

void displayStudents(DLList<Student> &studentList)
{
  cout << setw(35) << "REVERSE STUDENT LIST" << endl
       << "==========================================================" << endl
       << left
       << setw(12) << "ID"
       << setw(30) << "NAME"
       << setw(10) << "MAJOR"
       << setw(6) << "GPA" << endl;
  cout << "==========================================================" << endl;
  studentList.displayReverse();
}

void countStudents(DLList<Student> &studentList)
{
  cout << "Total number of students: " << studentList.getNumValues() << endl;
}

void addNewStudent(DLList<Student> &studentList)
{
  Student student;

  cout << "Enter Student ID: ";
  cin >> student.id;
  cin.ignore();

  cout << "Enter Student Name: ";
  cin.getline(student.name, 50);

  cout << "Enter City and State";
  cin.getline(student.cityState, 50);

  cout << "Enter Phone Number: ";
  cin >> student.phone;

  cout << "Enter Gender (M/F): ";
  cin >> student.gender;

  cout << "Enter Year: ";
  cin >> student.year;

  cout << "Enter Number of Credits: ";
  cin >> student.credits;

  cout << "Enter GPA: ";
  cin >> student.gpa;

  cout << "Enter Major: ";
  cin >> student.major;

  studentList.insert(student);
  cout << "Student added successfully.\n";
}

void removeStudent(DLList<Student> &studentList)
{
  Student student;

  cout << "Enter the ID of the student to remove: ";
  cin >> student.id;

  if (studentList.remove(student))
  {
    cout << "Student removed: " << student << endl;
  }
  else
  {
    cout << "Student with ID " << student.id << " not found.\n";
  }
}

void findStudent(DLList<Student> &studentList)
{
  Student student;

  cout << "Please enter the Student ID: ";
  cin >> student.id;

  if (studentList.retrieve(student))
  {
    cout << "Student found: ";
    cout << student << endl;
  }
  else
  {
    cout << "Student with ID " << student.id << " not found.";
  }
}
