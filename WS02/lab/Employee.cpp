/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Abdul-wahab Abdurrasheed
Student ID#: 131825234
Email      : aabdurrasheed@myseneca.ca
Section    : ZFF
date       : 05/22/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"

using namespace std;

namespace seneca {

   int noOfEmployees; // Global variable to store the number of employees
   Employee* employees; // Global pointer to dynamically allocate array of Employee structs
   
   // Function to sort employees by employee number using bubble sort
   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            // Compare employee numbers and swap if necessary
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // Function to load a single employee record from the file
   // Returns true if the record is successfully read, false otherwise
   bool load(Employee &employee) {
      bool ok = false;
      char name[128];
      // Read name, employee number, and salary from the file
      if (read(name) && read(employee.m_empNo) && read(employee.m_salary)) {
         // Dynamically allocate memory for the employee's name and copy the name into it
         employee.m_name = new char[strlen(name) + 1];
         strcpy(employee.m_name, name);
         ok = true;
      }
      return ok;
   }

   // Function to load all employee records from the file
   // Returns true if all records are successfully read, false otherwise
   bool load() {
      bool ok = false;
      if (openFile(DATAFILE)) {
         noOfEmployees = noOfRecords(); // Get the number of records in the file
         employees = new Employee[noOfEmployees]; // Dynamically allocate array for employees
         for (int i = 0; i < noOfEmployees; ++i) {
            if (!load(employees[i])) { // Load each employee record
               cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
               delete[] employees; // Clean up dynamically allocated memory
               employees = nullptr;
               noOfEmployees = 0;
               closeFile(); // Close the file
               return ok;
            }
         }
         closeFile(); // Close the file after reading all records
         ok = true;
      } else {
         cout << "Could not open data file: " << DATAFILE << endl;
      }
      return ok;
   }

   // Function to display a single employee's information
   void display(Employee& employee) {
      cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
   }

   // Function to display all employees' information sorted by employee number
   void display() {
      cout << "Employee Salary report, sorted by employee number\n"
           << "no- Empno, Name, Salary\n"
           << "------------------------------------------------\n";
      sort(); // Sort employees by employee number
      for (int i = 0; i < noOfEmployees; ++i) {
         cout << (i + 1) << "- ";
         display(employees[i]); // Display each employee's information
      }
   }

   // Function to deallocate the memory allocated for employees' names and the employee array
   void deallocateMemory() {
      for (int i = 0; i < noOfEmployees; ++i) {
         delete[] employees[i].m_name; // Deallocate memory for each employee's name
      }
      delete[] employees; // Deallocate memory for the employee array
      employees = nullptr;
      noOfEmployees = 0;
   }

}
