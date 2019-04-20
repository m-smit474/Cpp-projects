#include "globals.h"
#include "ignoreList.h"
#include <iostream>
#include <cstring>
using namespace std;

void ignoreSeach(ignorePtr head, WORD target, ignorePtr& current, 
		 ignorePtr& pred, bool& found);
void loadNewIgnoreNode(ignorePtr& temp, WORD aWord, bool whereFrom);



void insertInIgnoreList (ignorePtr &head, WORD aWord, bool whereFrom)
{
    ignorePtr temp = NULL;
    ignorePtr current = NULL;
    ignorePtr pred = NULL;
    bool found = false;

    ignoreSeach(head, aWord, current, pred, found);
    // Check if word is already on list

    if(!found)
    {
	if(pred == NULL)                  // Empty List
	{
	    loadNewIgnoreNode(temp, aWord, whereFrom);
	    head = temp;
	    temp = NULL;
	}
	else                             // Non empty list
	{
	    loadNewIgnoreNode(temp, aWord, whereFrom);
	    pred -> next = temp;
	    pred = NULL;
	    temp = NULL;   
	}

    }

}
bool findInIgnoreList(ignorePtr head, WORD aWord)
{
    ignorePtr current = NULL;
    ignorePtr pred = NULL;
    bool found = false;

    ignoreSeach(head, aWord, current, pred, found);

    return found;
}
void writeIgnoreList (ignorePtr head, ostream &os)
{
    int count;
    ignorePtr trav = NULL;

    for(trav = head, count = 0 ; trav != NULL ; trav = trav -> next)
    {
	if(trav -> fromText == false)
	    count++;
    }

    os << count << " words on the ignore list were read from file \n";

    for(trav = head, count = 1 ; trav != NULL ; trav = trav -> next)
    {
	if(trav -> fromText == true)
	{
	    os << count << "   " << trav -> aWord << endl;
	    count++;
	}

    }

}
void destroyIgnoreList(ignorePtr &head)
{
    ignorePtr temp = NULL;

    while(head != NULL)
    {
	temp = head;
	head = head -> next;
	delete temp;
	temp = NULL;                 // Might be unnecessary
    }

}

void ignoreSeach(ignorePtr head, WORD target, ignorePtr& current, 
		 ignorePtr& pred, bool& found)
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


void loadNewIgnoreNode(ignorePtr& temp, WORD aWord, bool whereFrom)
{
    temp = new ignoreNode;
    temp -> next = NULL;
    temp -> fromText = whereFrom;
    strncpy(temp -> aWord, aWord, WORD_MAX);
}
