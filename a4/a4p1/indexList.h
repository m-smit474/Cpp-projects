#ifndef INDEX_LIST
#define INDEX_LIST

/*******************************************************************************
 *
 *  The "indexList" class: represents a list of words and word counts that is
 *  stored in alphabetic order. Valid word counts will range between 1 and a
 *  maximum value, exclusive.
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
 ******************************************************************************/

#include "globals.h"
#include <iostream>
using namespace std;

class indexList
{
 public:
  void update(const WORD aWord, int max_count, bool &success);
  void write(ostream &os);

 private:
};


#endif
