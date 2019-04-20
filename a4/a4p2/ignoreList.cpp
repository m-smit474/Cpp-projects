/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  4 Part 2
  Due Date:    Wednesday, March 20, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: ignoreList.cpp

 */
/*
 *
 *    newArray    takes a ignore node pointer
 *                increments max size by 10 and creates a new array that is of
 *                that size. Sets the given pointer to this new array
 *                and returns the pointer 
 *
 */


#include "ignoreList.h"
#include <cstring>
#include <iomanip>

ignoreList :: ignoreList ()
{
    maxSize = 25;
    fillLevel = 0;

    ignoreWords = new ignoreNode [maxSize];
}

ignoreList :: ~ignoreList()
{

    delete [] ignoreWords;

}

void ignoreList :: load (istream &in)
{
    WORD word;
    ignoreNode *temp;

    in >> word;
    while(!in.eof())
    {
	if(fillLevel < maxSize)
	{
	    strncpy(ignoreWords[fillLevel].aWord, word, WORD_MAX);
	    ignoreWords[fillLevel].fromText = false;

	    ++fillLevel;
	}
	else
	{
                                               
	    newArray(temp);                    // Create new array with a size +10

	    delete [] ignoreWords;

	    ignoreWords = temp;

	    strncpy(ignoreWords[fillLevel].aWord, word, WORD_MAX);
	    ignoreWords[fillLevel].fromText = false;

	    ++fillLevel;

	}

	in >> word;
    }
}

bool ignoreList :: contains (const WORD aWord)
{
    bool found = false;
    int index;

    for(index = 0; index <= fillLevel; ++index)
    {
	if(aWord == ignoreWords[index].aWord)
	    found = true;
    }

    return found;
}

void ignoreList :: insert (const WORD aWord, bool fromWhere)
{
    ignoreNode* temp;

    if(fillLevel < maxSize)
    {
	++fillLevel;

	strncpy(ignoreWords[fillLevel].aWord, aWord, WORD_MAX);
	ignoreWords[fillLevel].fromText = fromWhere;
    }
    else
    {
// Create new array +10 size
	newArray(temp);

	delete [] ignoreWords;

	ignoreWords = temp;

	++fillLevel;

	strncpy(ignoreWords[fillLevel].aWord, aWord, WORD_MAX);
	ignoreWords[fillLevel].fromText = fromWhere;

    }
}

void ignoreList :: write (ostream &os)
{
    int fileWordCount = 0,
	lineCount = 1,
	textWordCount,
	index;

    for(index = 0; index <= fillLevel; ++index)
    {
	if(ignoreWords[index].fromText == false)
	    ++fileWordCount;
    }

    textWordCount = fillLevel - fileWordCount;


    os << "There was " << fileWordCount << " word(s) read from the ignore file.\n";

    if(textWordCount == 0)
	os << "No words from the text were added to the ignore list\n";
    else
    {
	for(index = 0; index <= fillLevel; ++index)
	{
	    if(ignoreWords[index].fromText == true)
	    {
		os << setw(5) << left << lineCount
		   << setw(30) << left << ignoreWords[index].aWord
		   << endl; 
	    }
	}
    }

}

void ignoreList :: getWord (int position, WORD aWord, bool &fromWhere, bool &found)
{
    found = false;

    if(position <= fillLevel)
    {
	found = true;

	strncpy(aWord, ignoreWords[position].aWord, WORD_MAX);
	fromWhere = ignoreWords[position].fromText;

    }
}

int ignoreList :: size ()
{

    return fillLevel;
}

void ignoreList :: newArray(ignoreNode* &temp)
{
    int index;

    maxSize += 10;

    temp = new ignoreNode [maxSize];
                                                   // Copy ignoreWords to new array
    for(index = 0; index < fillLevel; ++index)
    {
	temp[index] = ignoreWords[index];
    }
    
}   
