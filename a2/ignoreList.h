#ifndef IGNORE_LIST_H
#define IGNORE_LIST_H

#include "globals.h"
#include <iostream>
using namespace std;

typedef struct ignoreNode *ignorePtr;

struct ignoreNode
{
  WORD aWord;
  bool fromText;
  ignorePtr next;
};

void insertInIgnoreList (ignorePtr &head, WORD aWord, bool whereFrom);
bool findInIgnoreList(ignorePtr head, WORD aWord);
void writeIgnoreList (ignorePtr head, ostream &os);
void destroyIgnoreList(ignorePtr &head);

#endif
