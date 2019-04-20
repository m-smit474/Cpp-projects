/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  4 
  Due Date:    Tuesday, March 12, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: a4p1.cpp

 ==============================================================================

 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "ioutil.h"
#include "globals.h"
#include "indexList.h"
#include "ignoreList.h"
using namespace std;

const int MAX_COUNT = 7;
const int MIN_WORD_LENGTH = 3;

void lowercaseWord (WORD aWord);
// 1
//void loadIgnoreList (ignorePtr &head, ifstream &ignoreFile);

int main ()
{
  ifstream  bookFile, ignoreFile;
  WORD      word, bookFileName, ignoreFileName;
  bool      eof, success, outputIgnoreList;
// 2
//  ignorePtr ignoreHead = NULL;
  ignoreList ignoreWords;
// 3
//  indexPtr  indexHead = NULL;
  indexList indexWords;

  do
  {
    readString ("Enter the name of the text file: ", bookFileName, 
                WORD_MAX, 1, eof);
    if(eof)
    {
      cout << "\n\tCtrl-d entered and ignored - to exit program type Ctrl-c\n";
    }
  } while (eof);

  bookFile.open (bookFileName);
  if (bookFile.fail())
    cout << "Unable to open text file - processing terminated\n";
  else
  {
    do
    {
      readString ("Enter the name of the words to ignore file: ", 
                  ignoreFileName, WORD_MAX, 0, eof);
      if(eof)
      {
        cout << "\n\tCtrl-d entered and ignored - to exit program type Ctrl-c\n";
      }
    } while (eof);
    
    if (static_cast<int> (strlen(ignoreFileName)) == 0)
      cout << "No file name entered for ignore words" << endl;
    else
    {
      ignoreFile.open(ignoreFileName);
      if (ignoreFile.fail())
        cout << "The ignore words file failed to open." << endl;
      else
      {
// 4
//        loadIgnoreList(ignoreHead, ignoreFile);
	  ignoreWords.load(ignoreFile);
// 5
//        if (ignoreHead == NULL) 
	  if(ignoreWords.size() == 0)
          cout << "The ignore words file contained no words." << endl;
     }
    }

    bookFile >> word;
    if (bookFile.eof())
    {
      cout << "The text file is empty, so no index is produced" << endl;
    }
    else
    {
      while (!bookFile.eof())
      {
        lowercaseWord(word);
        if (word[0] >= 'a' && word[0] <= 'z')
        {
          if (static_cast<int> (strlen(word)) > MIN_WORD_LENGTH)
          {
// 6
//            if (!findInIgnoreList(ignoreHead, word))
	      if(!ignoreWords.contains(word))
            {
// 7
//              updateIndexList(indexHead, word, MAX_COUNT, success);
		indexWords.update(word, MAX_COUNT, success);
              if (!success)
              {
// 8
//                insertInIgnoreList(ignoreHead, word, true);
		  ignoreWords.insert(word, true); 
              }
            }
          }
        }
        bookFile >> word;
      }
// 9
//      writeIndexList (indexHead, cout);
      indexWords.write(cout);
    
      do
      {
        outputIgnoreList = readBool("Print ignore list? (y/n): ", eof);
        if(eof)
        {
          cout << "\n\tCtrl-d entered and ignored - to exit program type Ctrl-c\n";
        }
      } while (eof);

      if (outputIgnoreList)
      {
// 10
//        writeIgnoreList(ignoreHead, cout);
	  ignoreWords.write(cout);
      }
    }
// 11
//    destroyIgnoreList(ignoreHead);

// 12
//    destroyIndexList(indexHead);
  }
  return 0;
}

void lowercaseWord (WORD aWord)
{
  int i, length;

  length = static_cast <int> (strlen(aWord));
  for (i = 0; i < length; i++)
  {
    aWord[i] = static_cast<char>(tolower(aWord[i]));
  }
}

/*
void loadIgnoreList (ignorePtr &head, ifstream &ignoreFile)
{
  WORD word;

  ignoreFile >> word;
  while (!ignoreFile.eof())
  {
    insertInIgnoreList(head, word, false);
    ignoreFile >> word;
  }
  return;
}
*/
