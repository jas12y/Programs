/*
Programmers Name: John Stubbs
      Assignment: Homework #9
            Date: 3/8/12

Description:
            This program give the user the option to view a list of speakers or
            search for a speaker by topic.
*/
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//Constants for char array sizes within the structure
const int NAME_LEN = 15;
const int PHONE_LEN = 14;
const int TOPIC_LEN = 24;

// Structure declaration
struct SpeakerData
{
   char name[NAME_LEN];
   char phone[PHONE_LEN];
   char topic[TOPIC_LEN];
   double fee;
};
// Function prototypes
void menu();
void showData(SpeakerData[], int);
void searchData(SpeakerData[], int);
void convert(char[], int);
void errorMsg(char);
void goodBye();


int main()
{
   //To hold the size of the speaker list
   const int SIZE = 10;
   //Speaker list initialized with data
   SpeakerData speakerList[SIZE]={{"Leeroy Jenkins","(912)635-1832","World of Warcraft      ",1399.99},
                                  {"Tyler Brown   ","(212)555-1212","Memory Allocation      ",1450.00},
                                  {"Sarah Burke   ","(850)344-1257","C++ Programming        ",1259.50},
                                  {"Tony Simon    ","(228)543-9024","Database Management    ",1100.99},
                                  {"Adrienne Smith","(718)234-8790","C++ Programming        ",1200.00},
                                  {"Amanda Nalley ","(850)554-8273","Ethical Hacking        ",1499.99},
                                  {"Chris Miller  ","(478)508-9404","Hacking Countermeasures",1500.00},
                                  {"Josh Owens    ","(308)866-8093","Network Administration ",1376.99},
                                  {"Bill Dawson   ","(734)934-1100","Network Implementation ",1000.00},
                                  {"James Bishop  ","(904)394-8953","Wireless Networking    ",1275.75}};
   //To hold the users menu selection
   char choice;
   
   cout << showpoint << setprecision(2) << fixed;
   
   do
   {
      menu();
      
      cin >> choice;
      
      if (toupper(choice) == 'A')
         
         showData(speakerList, SIZE);
      
      else if (toupper(choice) == 'B')
      
         searchData(speakerList, SIZE);
      
      else if (toupper(choice) == 'C')
      
         goodBye();
      
      else
      
         errorMsg(choice);
      
      
   } while (toupper(choice) != 'C');
   
   return 0;
}
//Display Menu
void menu()
{
   system("CLS");
   
   cout << "\n\n\n\n\n\n\n\n"
        << "\t\t\tComputer Tech Club Speakers Menu\n"
        << "\t\t\t--------------------------------\n"
        << "\t\t\tA. Display all speaker data\n"
        << "\t\t\tB. Search for a speaker by topic\n"
        << "\t\t\tC. Exit\n"
        << "\t\t\t--------------------------------\n\n"
        << "\t\t\tEnter your selection > ";
   
}
//Display all of the Speaker Data
void showData(SpeakerData list[], int size)
{
   system("CLS");
   
   cout << "\t\t\tComputer Tech Club Speaker List\n"
        << "\t\t\t-------------------------------\n\n"
        << "\tName\t\tPhone Number\tTopic\t\t\tFee\n"
        << "\t----------------------------------------------------------------\n";
   
   for (int i = 0; i < size; i++)
   {
      cout << "\t" << list[i].name << "\t" << list[i].phone << "\t" << list[i].topic << "\t$" << list[i].fee << endl;
   }
   cout << endl;
   system("PAUSE");
}
//Search Speaker Data and display results
void searchData(SpeakerData list[], int size)
{
   char stringCopy[TOPIC_LEN];
   char keyWrd[TOPIC_LEN];
   int length;
   int counter = 0;
   
   system("CLS");
   
   cout << "\n\t\tPlease enter a keyword to search for > ";
   cin.ignore();
   cin.getline(keyWrd, TOPIC_LEN);
   
   length = strlen(keyWrd);
   
   convert(keyWrd, length);
   
   cout << "\n\t\tComputer Tech Club Speaker Topic Search\n"
        << "\t\t---------------------------------------\n\n"
        << "\tName\t\tPhone Number\tTopic\t\t\tFee\n"
        << "\t----------------------------------------------------------------\n";
   
   for (int i = 0; i < size; i++)
   {
      strcpy(stringCopy, list[i].topic);
      
      convert(stringCopy, TOPIC_LEN);
      
      if (strstr(stringCopy,keyWrd) != NULL)
      {
         cout << "\t" << list[i].name << "\t" << list[i].phone << "\t" << list[i].topic << "\t$" << list[i].fee << endl;
         
         counter++;
      }
   }
   
   cout << "\nSearch results: " << counter << "\n\n";
   
   system("PAUSE");
}
//To convert a char array to all lower case
void convert(char string[], int size)
{
   for(int i = 0; i < size; i++)
   {
      string[i] = tolower(string[i]);
   }
}
//Display Error Message
void errorMsg(char option)
{
   cout << "\n\n"
        << "\n\t\t\t   " << option << " is NOT a valid entry.\n"
        << "\t\t\t   Please make a valid entry."
        << "\n\n\n\n";
          
   system("PAUSE");
}
//Display a goodbye message
void goodBye()
{
   cout << "\n\n"
        << "\n\t\t\tHave a nice day! Goodbye!"
        << "\n\n\n\n\n";
        
   system("PAUSE");
}
