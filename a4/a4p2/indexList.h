#ifndef INDEX_LIST
#define INDEX_LIST

/*******************************************************************************
 *
 *  The "indexList" class: represents a list of words and word counts that is
 *  stored in alphabetic order. Valid word counts will range between 1 and a
 *  maximum value - 1, inclusive.
 *
 *  PUBLIC METHOD SPECIFICATION:
 *
 *     update:    takes a word and an integer specifying the maximum allowable
 *                count.
 *                If the word is not presently on the list it will be added in
 *                alphabetic order.
 *                If the word is already on the list, its count will be
 *                incremented. If the incremented value is less than the specified
 *                maximum count, the word is left on the list. If the incremented
 *                word count exceeds the maximum count, the word is removed from
 *                the list.
 *                The function returns a success flag. The flag will be true if
 *                the word remains on the list. The flag will be false if the
 *                word was removed from the list.
 *
 *     write:     takes an output stream and writes the index list to it.
 *                The format for each line in the output is:
 *                    line number, word and word count
 *
 *     getWord    takes a position in the list, starting from 1.
 *                if a word exists at this position in the list, then
 *                the function returns the word at this position
 *                the function returns another boolean value indicating whether
 *                (true) or not (false) a word exists at the specified position.
 *                If a false is returned for this value then the returned word
 *                value is undefined.
 *
 *     getCount   takes a word and if this word is found on the index list its
 *                count is returned.
 *
 *     size       returns the length of the index list, i.e. the total number
 *                of words on the list.
 *
 *
 ******************************************************************************/

#include "globals.h"
#include <iostream>
using namespace std;

class indexList
{
 public:
  indexList();
  ~indexList();

  void update(const WORD aWord, int max_count, bool &success);
  void write(ostream &os);
// the following three functions are provided for testing purposes only
  void getWord (int position, WORD aWord, bool &found) const;
  int getCount (const WORD aWord) const;
  int size() const;

 private:
  struct indexNode
  {
    indexNode *next;
    indexNode *prev;
    WORD word;                   // WORD type declared in global.h
    int   count;
  };
  typedef indexNode *indexPtr;

  void search (const WORD aWord, indexPtr &here, bool &found) const;

  indexNode head, tail;         // Notice: actual NODES not pointers!!!

  void alphaOrder (indexPtr &here, const WORD aWord) const;

};


#endif
