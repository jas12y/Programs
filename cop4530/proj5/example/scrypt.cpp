#include <iostream>
#include <utility>
#include <unistd.h>
#include <string>
#include <cstring>

using namespace std;

int main()
{
  //pair <string, string> p;
  // char salt[] = "$1$........";
  char salt[] = "$1$########";
  string key = "ForrestGump";

  char * password = new char [100];
  strcpy ( password, crypt(key.c_str(), salt));
  cout << password << endl;
  return 0;
}
