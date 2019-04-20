#include "globals.h"
#include "indexList.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void indexSearch(indexPtr head, WORD target, indexPtr& current, indexPtr& pred,
		 bool& found);
void loadNewIndexNode(indexPtr& temp, WORD word);



void updateIndexList (indexPtr &head, WORD word, int maxCount, bool &success)
{
    indexPtr current,
	pred,
	temp;
    bool found = true;

    success = true;

    indexSearch(head, word, current, pred, found);


    if(!found)                               // Pred points at last node
    {
	if(pred == NULL)                     // Empty List
	{
	    loadNewIndexNode(temp, word);
	    head = temp;
	}
	else                                 // Non empty list
	{
	    current = head;
	    pred = NULL;

	    while(current != NULL && 
		  strncmp(word, current -> aWord, WORD_MAX) > 0)

	    {                                // Finds place alphabetically
		pred = current;
		current = current -> next;
	    }

	    if(current == NULL)              // Word goes at end of list
	    {
		loadNewIndexNode(temp, word);
		pred -> next = temp;
	    }
	    else if(pred == NULL)           // Word goes at begining
	    {
		loadNewIndexNode(temp, word);
		temp -> next = head;
		head = temp;
	    }
	    else
	    {
		loadNewIndexNode(temp, word);
		temp -> next = current;
		pred -> next = temp;
	    }

	}

    }
    else                                   // Word is already on list 
    {
	if(current -> count < maxCount)
	{
	    current -> count++;
	}
	else                              // Count exceeds max
	{                                 // Must remove from list

	    success = false;

	    if(pred == NULL)             // Remove from head
	    {
		head = head -> next;
		delete current;
	    }
	    else
	    {
		pred -> next = current -> next;
		delete current;
	    }

	}

    }

}
void writeIndexList (indexPtr head, ostream &os)
{
    int count = 1;
    indexPtr temp = head;

    while(temp != NULL)
    {
	os << setw(5)  << left << count
	   << setw(30) << left << temp -> aWord
	   << left << temp -> count << endl;

	temp = temp -> next;
	count++;
    }

}
void destroyIndexList(indexPtr &head)
{
    indexPtr temp;

    while(head != NULL)
    {
	temp = head;
	head = head -> next;
	delete temp;
    }
}

void loadNewIndexNode(indexPtr& temp, WORD word)
{
    temp = new indexNode;
    temp -> next = NULL;
    temp -> count = 1;
    strncpy(temp -> aWord, word, WORD_MAX);
}

void indexSearch(indexPtr head, WORD target, indexPtr& current, indexPtr& pred,
		 bool& found)
{
    found = false;
    pred = NULL;
    current = head;

    while(current != NULL && !found)
    {

	if(strncmp(current -> aWord, target, WORD_MAX) == 0)
	{
	    found = true;
	}
	else
	{
	    pred = current;
	    current = current -> next;
	}

    }

}

