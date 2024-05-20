/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Abdul-wahab Abdurrasheed
Student ID#: 131825234
Email      : aabdurrasheed@myseneca.ca
Section    : ZFF
Date       : 05/22/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace seneca {
   FILE* fptr; // File pointer to handle the file operations

   // Opens the file with the given filename in read mode
   // Returns true if the file is successfully opened, false otherwise
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   // Counts the number of records in the file
   // Assumes that each record ends with a newline character
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n'); // Increment the count for each newline character
      }
      rewind(fptr); // Reset the file pointer to the beginning of the file
      return noOfRecs;
   }

   // Closes the file if it is open
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   // Reads a string (name) from the current position in the file
   // Returns true if the reading is successful, false otherwise
   bool read(char *name) {
      int noOfItem = fscanf(fptr, "%[^\n]\n", name); // Read until newline character
      return noOfItem == 1;
   }

   // Reads an integer (employee number) from the current position in the file
   // Returns true if the reading is successful, false otherwise
   bool read(int &number) {
      int noOfItem = fscanf(fptr, "%d,", &number); // Read an integer followed by a comma
      return noOfItem == 1;
   }

   // Reads a double (salary) from the current position in the file
   // Returns true if the reading is successful, false otherwise
   bool read(double &salary) {
      int noOfItem = fscanf(fptr, "%lf,", &salary); // Read a double followed by a comma
      return noOfItem == 1;
   }

}
