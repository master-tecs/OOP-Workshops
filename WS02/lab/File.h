/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Abdul-wahab Abdurrasheed
Student ID#: 131825234
Email      : aabdurrasheed@myseneca.ca
Section    : ZFF
date       : 05/22/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_

namespace seneca {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* name);
   bool read(int& number);
   bool read(double& salary);
}

#endif // SENECA_FILE_H_
