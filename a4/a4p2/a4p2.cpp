/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  4 Part 2
  Due Date:    Wednesday, March 20, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: a4p2.cpp

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
//void loadIgnoreList (ignoreList ignore, ifstream &ignoreFile);

int main ()
{
  ifstream  bookFile, ignoreFile;
  WORD      word, bookFileName, ignoreFileName;
// 2
//bool      eof, success, outputIgnoreList;
  bool      eof, success, outputIgnoreList, fromFile, found;
// 3
//ignorePtr ignoreHead = NULL;
  ignoreList ignore;
// 4
//indexPtr  indexHead = NULL;
  indexList  index;

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
// 5
//      loadIgnoreList(ignoreHead, ignoreFile);
        ignore.load(ignoreFile);
// 6
//      if (ignoreHead == NULL) 
// OR if (ignore.size() == 0)
        ignore.getWord(1, word, fromFile, found);
        if(!found) 
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
// 7
//          if (!findInIgnoreList(ignoreHead, word))
            if (!ignore.contains(word))
            {
// 8
//            updateIndexList(indexHead, word, MAX_COUNT, success);
              index.update(word, MAX_COUNT, success);
              if (!success)
              {
// 9
//              insertInIgnoreList(ignoreHead, word, true);
                ignore.insert(word, true);
              }

            }
          }
        }
        bookFile >> word;
      }

// 10
//    writeIndexList (indexHead, cout);
      index.write(cout);
    
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
// 11
//      writeIgnoreList(ignoreHead, cout);
        ignore.write(cout);
      }
    }
// 12
/*
    destroyIgnoreList(ignoreHead);

    destroyIndexList(indexHead);
*/
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
// 13
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
