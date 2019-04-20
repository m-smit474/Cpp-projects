/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  4 Part 2
  Due Date:    Wednesday, March 20, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: indexList.cpp

 */
/*
 *  The indexList Private memebers: has a index node structure which consits
 *  of 4 fields. the two node pointer next and prev, a word and the word count.
 *  The index node struct will be used for the nodes in the link list.
 *  There are static head and tail nodes that replace head and tail pointers.
 *
 *     search     takes a word
 *                the index list is search for this word and if it is found, 
 *                the boolean, found, parameter is set to true and the pointer,
 *                here, is set to point to the node containing the word; 
 *                otherwise if the word is not found, the found parameter is 
 *                set to false and here is set to point to the node with the 
 *                word that would follow the word being searched for, 
 *                i.e. the word’s alphabetic successor.
 *
 *                Details:
 *                Since the list can be traversed in either direction, this 
 *                function will start searching from the head node for words 
 *                that start with the letters ‘a’ through ‘m’; the search will
 *                start from the tail node for words starting with the letters
 *                'n' through 'z'.
 *
 *  alphaOrder    takes a pointer "here" and a word
 *                traverses through the list and sets "here" to point to the node 
 *                with the first word that comes after the target alphabetically.
 *
 */
#include "indexList.h"
#include <cstring>
#include <iomanip>



indexList :: indexList ()
{
    head.next = &tail;
    tail.prev = &head;
}

indexList :: ~indexList ()
{
    indexPtr temp;

    while(head.next != &tail)
    {
	temp = head.next;
	head.next = head.next -> next;
	delete temp;
    }
}

void indexList :: update (const WORD aWord, int max_count, bool &success)
{
    indexPtr here,
	temp;
    bool found;

    success = true;

    search(aWord, here, found);

    if(!found)
    {
	alphaOrder(here, aWord);           // Might be redundant

	temp = new indexNode;
	temp -> next = here;
	temp -> prev = here -> prev;
	here -> prev -> next = temp;
	here -> prev = temp;
    }
    else
    {
	++(here -> count);

	if(here -> count > max_count)
	{
	    success = false;

	    here -> prev -> next = here -> next;
	    here -> next -> prev = here -> prev;
	    delete here;
	}
    }
}

void indexList :: write (ostream &os)
{
    int count = 1;
    indexPtr temp = head.next;

    while(temp != &tail)
    {
	os << setw(5) << left << count
	   << setw(30) << left << temp -> word
	   << left << temp -> count << endl;

	temp = temp -> next;
	++count;
    }
}

void indexList :: getWord(int position, WORD aWord, bool &found) const
{
    int count = 1;
    indexPtr temp = head.next;

    found = false;

    if(position > 0)
    {
	while(temp != &tail && count < position)
	{
	    ++count;
	    
	    temp = temp -> next;
	}
	
	if(count == position && head.next != &tail)
	{
	    found = true;

	    aWord = temp -> word;
	}
    }
}

int indexList :: getCount(const WORD aWord) const
{
    int count;
    indexPtr here;
    bool found = false;

    search(aWord, here, found);

    if(found)
    {
	count = here -> count;
    }
    else
	count = 0;

    return count;
}

int indexList :: size() const
{
    int counter = 0;
    indexPtr temp;

    temp = head.next;
    while(temp != &tail)
    {
	++counter;
	temp = temp -> next;
    }

    return counter;
}

void indexList :: search(const WORD aWord, indexPtr &here, bool &found) const
{
    here = head.next;
    found = false;

    while(here != &tail && here -> word[0] < 'n' && !found)
    {
	if(strncmp(here -> word, aWord, WORD_MAX) == 0)
	    found = true;
	else
	    here = here -> next;
    }
    if(!found)
    {
	here = tail.prev;

	while(here != &head && here -> word[0] > 'm' && !found)
	{
	    if(strncmp(here -> word, aWord, WORD_MAX) == 0)
		found = true;
	    else
		here = here -> prev;
	}
    }

    if(!found)
    {
	alphaOrder(here, aWord);
    }
}

void indexList :: alphaOrder (indexPtr &here, const WORD aWord) const
{
    here = head.next;

    while(here != &tail && strncmp(here -> word, aWord, WORD_MAX) < 0)
    {
	here = here -> next;
    }

}
