/*
Programmers Name: John Stubbs
      Assignment: #5
            Date: 3/22/13

This driver file asks the user for an input and an output file, opens both and 
reads data from the input file and adds each record to an array of pointers.
Then sorts the data alphabetically by last name and writes the data to the
output file sorted by the student's course.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "student.h"

using namespace std;

// Function Prototypes
void getInput(ifstream &);
void getOutput(ofstream &);
void getData(ifstream &, char*, char*, char*);
void addStudent(Student **, ifstream &, const char*, const char*, const char*, const int);
void sortData(Student **, const int);
void writeData(Student **, ofstream &, const int);
char letterGrade(const double);

// Global constants
const int FILE_NAME = 81;
const int NAME_SIZE = 21;
const int SUB_SIZE = 8;
const int ENG_SIZE = 4;
const int HIS_SIZE = 3;
const int MAT_SIZE = 8;

int main(void)
{
    int numRec;
    char LName[NAME_SIZE];
    char FName[NAME_SIZE];
    char course[NAME_SIZE];
    ifstream inFile;
    ofstream outFile;
    Student **SArray;
    
    // Gets input file name, opens, and checks for errors
    getInput(inFile);

    // Gets output file name, opens, and checks for errors
    getOutput(outFile);
    
    // Reads in the number of records
    inFile >> numRec;
    
    // Dynamically allocated pointer array
    SArray = new Student*[numRec+1];
    
    // Reads in data and creates object in array
    for (int i = 0; i < numRec; i++)
    {
        getData(inFile, LName, FName, course);
        
        addStudent(SArray, inFile, LName, FName, course, i);
    }
    
    // Sorts data alphabetically based on Last Name
    sortData(SArray, numRec);
    
    // Outputs data to file
    writeData(SArray, outFile, numRec);
    
    // Deletes dynamically allocated array
    for (int i = 0; i < numRec; i++)
        delete SArray[i];
    
    delete [] SArray;
    
    // Close both files
    inFile.close();
    outFile.close();
    
    return 0;
}
// Gets input file name and opens file
void getInput(ifstream &inFile)
{
    // Input file name
    char inName[FILE_NAME];
   
    // Get the input file name
    cout << "Enter the input file name: ";
    cin.getline(inName, FILE_NAME);
   
    // Open the input file
    inFile.open(inName);

    // Test for errors
    while(!inFile)
    {
        // Error message
        cout << "Error opening file...Please enter a valid input file: " << endl;
        cin.getline(inName, FILE_NAME);
        inFile.open(inName);
    }
}
// Gets output file name and opens file
void getOutput(ofstream &outFile)
{
    // Output file name
    char outName[FILE_NAME];
   
    // Get the output file name
    cout << "Enter the output file name: ";
    cin.getline(outName, FILE_NAME);
   
    // Open the output file
    outFile.open(outName);
   
    // Test for errors
    if (!outFile)
    {
        // Error message
        cout << "Error opening file...Please enter a valid output file: " << endl;
        cin.getline(outName, FILE_NAME);
        outFile.open(outName);
    }
}
// Reads data in from file
void getData(ifstream &inFile, char* LName, char* FName, char* course)
{
    inFile.ignore();
    inFile.getline(LName, NAME_SIZE, ',');
    inFile.ignore();
    inFile.getline(FName, NAME_SIZE);
    inFile.getline(course, SUB_SIZE, ' ');
}
// Adds a Student object to pointer array based on course
void addStudent(Student **SA, ifstream &inFile, const char* LName, const char* FName, const char* course, const int index)
{
    int engData[ENG_SIZE];
    int hisData[HIS_SIZE];
    int matData[MAT_SIZE];
    
    switch(course[0])
    {
        case 'E':
            for (int j = 0; j < ENG_SIZE; j++)
                inFile >> engData[j];
            SA[index] = new English(LName, FName, course, engData);
            break;
        case 'H':
            for (int j = 0; j < HIS_SIZE; j++)
                inFile >> hisData[j];
            SA[index] = new History(LName, FName, course, hisData);
            break;
        case 'M':
            for (int j = 0; j < MAT_SIZE; j++)
                inFile >> matData[j];
            SA[index] = new Math(LName, FName, course, matData);
    }
}
// Sorts data alphabetically based on Last Name
void sortData(Student **SA, const int num)
{
    bool sort;
    
    do
    {
        sort = false;
        
        for(int i = 0; i < num; i++)
        {
            if(SA[i]->GetLast() > SA[i+1]->GetLast())
            {    
                SA[num] = SA[i];
                SA[i] = SA[i+1];
                SA[i+1] = SA[num];
                
                sort = true;
            }
            else if(SA[i]->GetLast() == SA[i+1]->GetLast())
            {
                if(SA[i]->GetFirst() > SA[i+1]->GetFirst())
                {    
                    SA[num] = SA[i];
                    SA[i] = SA[i+1];
                    SA[i+1] = SA[num];
                
                    sort = true;
                }
            }
        }
    }while(sort);
}
// Writes data to output file
void writeData(Student **SA, ofstream &outFile, const int num)
{
    int spaces;
    
    outFile << setprecision(2) << fixed;
    outFile << "Student Grade Summary\n"
            << "---------------------\n\n";
    outFile << "ENGLISH CLASS\n\n";
    outFile << "Name\t\t\t\tFinal Exam\t\tFinal Avg\tGrade\n" 
            << "-----------------------------------------------------------------------------\n";
    for (int i = 0; i < num; i++)
    {
        if (SA[i]->GetCourse() == "English")
        {
            spaces = SA[i]->GetFirst().length()+SA[i]->GetLast().length()+1;
            outFile << SA[i]->GetFirst() << " " << SA[i]->GetLast() << setw(40-spaces) 
                    << SA[i]->GetFinal() << "\t\t  " << SA[i]->CalcGrade()
                    << "\t\t  " << letterGrade(SA[i]->CalcGrade())<< "\n\n";
        }
    }
    outFile << "\n\nHISTORY CLASS\n\n";
    outFile << "Name\t\t\t\tFinal Exam\t\tFinal Avg\tGrade\n" 
            << "-----------------------------------------------------------------------------\n";
    for (int i = 0; i < num; i++)
    {
        if (SA[i]->GetCourse() == "History")
        {
            spaces = SA[i]->GetFirst().length()+SA[i]->GetLast().length()+1;
            outFile << SA[i]->GetFirst() << " " << SA[i]->GetLast() << setw(40-spaces) 
                    << SA[i]->GetFinal() << "\t\t  " << SA[i]->CalcGrade()
                    << "\t\t  " << letterGrade(SA[i]->CalcGrade())<< "\n\n";
        }
    }
    outFile << "\n\nMATH CLASS\n\n";
    outFile << "Name\t\t\t\tFinal Exam\t\tFinal Avg\tGrade\n" 
            << "-----------------------------------------------------------------------------\n";
    for (int i = 0; i < num; i++)
    {
        if (SA[i]->GetCourse() == "Math   ")
        {
            spaces = SA[i]->GetFirst().length()+SA[i]->GetLast().length()+1;
            outFile << SA[i]->GetFirst() << " " << SA[i]->GetLast() << setw(40-spaces) 
                    << SA[i]->GetFinal() << "\t\t  " << SA[i]->CalcGrade()
                    << "\t\t  " << letterGrade(SA[i]->CalcGrade())<< "\n\n";
        }
    }
}
// Returns letter grade based on final average
char letterGrade(const double avg)
{
    char grade;
    
    if (avg >= 90)
        grade = 'A';
    else if (avg >= 80)
        grade = 'B';
    else if (avg >= 70)
        grade = 'C';
    else if (avg >= 60)
        grade = 'D';
    else
        grade = 'F';
    
    return grade;
}
