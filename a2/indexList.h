#ifndef INDEX_LIST_H
#define INDEX_LIST_H

#include "globals.h"
#include <iostream>
using namespace std;

typedef struct indexNode *indexPtr;

struct indexNode
{
  WORD aWord;
  int count;
  indexPtr next;
};

void updateIndexList (indexPtr &head, WORD word, int maxCount, bool &success);
void writeIndexList (indexPtr head, ostream &os);
void destroyIndexList(indexPtr &head);

#endif
