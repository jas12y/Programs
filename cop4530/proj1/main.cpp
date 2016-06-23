/*
Programmers Name: John Stubbs
      Assignment: #1
            Date: 1/10/14
*/
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void openFile(ifstream &inFile, char* fileName)
{
    inFile.open(fileName);

    while(!inFile)
    {
        cout << "Error opening file..." << endl;
        exit(0);
    }
}
int main(int argc, char *argv[]) 
{
    char data;
    string word;
    int counter, wrd = 0, num = 0;
    char* fileName = argv[1];
    ifstream inFile;
    bool newWord = true;
    map<char, int> charsMap;
    multimap<int, char> mmChars;
    map<string, int> wordOrder, numbOrder, wordsMap, numbsMap;
    multimap<int, string> mmWordOrder, mmNumbOrder, mmWords, mmNumbs;
    typedef map<char, int>::reverse_iterator cmi;
    typedef map<string, int>::iterator smi;
    typedef multimap<int, char>::reverse_iterator cmmi;
    typedef multimap<int, string>::reverse_iterator smmi;
    
    openFile(inFile, fileName);
    
    inFile.get(data);
    
    while (!inFile.eof())
    {
	    ++charsMap[data];
	    
	    if(((isalpha(data) && isalpha(inFile.peek())) || (isdigit(data) && isdigit(inFile.peek()))) && newWord)
        {
            word = tolower(data);
            newWord = false;
        }
        else if(((isalpha(data) && isalpha(inFile.peek())) || (isdigit(data) && isdigit(inFile.peek()))) && !newWord)
        {
            word += tolower(data);
        }
        else if(((tolower(data) == 'a' || tolower(data) == 'i') || isdigit(data)) && newWord)
        {
            word = tolower(data);
            if(isalpha(data))
            {
                ++wordsMap[word];
                wordOrder.insert(pair<string, int>(word, ++wrd));
            }
            else
            {
                ++numbsMap[word];
                numbOrder.insert(pair<string, int>(word, ++num));
            }
        }
        else if((isalpha(data) || isdigit(data)) && !newWord)
        {
            word += tolower(data);
            if(isalpha(data))
            {
                ++wordsMap[word];
                wordOrder.insert(pair<string, int>(word, ++wrd));
            }
            else
            {
                ++numbsMap[word];
                numbOrder.insert(pair<string, int>(word, ++num));
            }
            newWord = true;
        }
	    inFile.get(data);
    }
    
    for (cmi itr = charsMap.rbegin(); itr != charsMap.rend(); ++itr)
        mmChars.insert(make_pair(itr->second, itr->first));
    
    cout << "Total " << mmChars.size() << " different characters, ";
    
        if(mmChars.size() < 10)
            cout << mmChars.size();
        else
            cout << 10;
        cout << " most used characters:\n";
    
    counter = 0;
    
    for (cmmi itr = mmChars.rbegin(); (itr != mmChars.rend() && counter < 10); ++itr)
    {
	    cout << "No. " << counter << ": ";
            
            switch(itr->second)
            {
                case '\n':
                    cout << "\\n";
                    break;
                case '\t':
                    cout << "\\t";
                    break;
                case '\0':
                    cout << "NUL";
                    break;
                default:
                    cout << itr->second;
                    break;
            }
        cout  << "\t\t" << itr->first << "\n";
        ++counter;
    }
    for(smi itr = wordOrder.begin(); itr != wordOrder.end(); ++itr)
        mmWordOrder.insert(make_pair(itr->second, itr->first));
    
    for(smmi itr = mmWordOrder.rbegin(); itr != mmWordOrder.rend(); ++itr)      
        mmWords.insert(make_pair(wordsMap[itr->second], itr->second));
    
    cout << "Total " << mmWords.size() << " different words, ";
    
        if(mmWords.size() < 10)
            cout << mmWords.size();
        else
            cout << 10;
        cout << " most used words:\n";
    
    counter = 0;
    
    for (smmi itr = mmWords.rbegin(); (itr != mmWords.rend() && counter < 10); ++itr)
    {
	    cout << "No. " << counter << ": ";
        cout << itr->second << "\t\t" << itr->first << "\n";
        ++counter;
    }
    
    for(smi itr = numbOrder.begin(); itr != numbOrder.end(); ++itr)
        mmNumbOrder.insert(make_pair(itr->second, itr->first));
    
    for(smmi itr = mmNumbOrder.rbegin(); itr != mmNumbOrder.rend(); ++itr)      
        mmNumbs.insert(make_pair(numbsMap[itr->second], itr->second));
    
    cout << "Total " << mmNumbs.size() << " different numbers, ";
    
        if(mmNumbs.size() < 10)
            cout << mmNumbs.size();
        else
            cout << 10;
        cout << " most used numbers:\n";
    
    counter = 0;
    
    for (smmi itr = mmNumbs.rbegin(); (itr != mmNumbs.rend() && counter < 10); ++itr)
    {
	    cout << "No. " << counter << ": ";
        cout << itr->second << "\t\t" << itr->first << "\n";
        ++counter;
    }
    
    return(EXIT_SUCCESS);
}
