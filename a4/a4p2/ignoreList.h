#ifndef IGNORE_LIST
#define IGNORE_LIST

/*******************************************************************************
 *
 *  The "ignoreList" class: represents a list of words that should not be
 *  included on a book index. The list is ordered by how the words are
 *  encountered.
 *  The list is populated either from an initial file or from words that are
 *  removed from the index list.
 *
 *  PUBLIC METHOD SPECIFICATION:
 *
 *     load:      takes an input stream and reads the contents of this stream
 *                as words and inserts them into the ignore list
 *
 *     contains: takes a word and determines whether or not this word is on the
 *               ignore list. The function returns true if the word is on the
 *               list; otherwise, it returns false
 *
 *     insert:   takes a word and a boolean indicating the source of the word,
 *               where false means the ignore word file and true means the text
 *               file, and inserts this word at the end of the ignore list.
 *
 *     write:     takes an output stream and writes information about the ignore
 *                list to it.
 *                The format for each line in the output is:
 *                   the first sentence states the count of words on the ignore
 *                   list that were read from the ignore words file,
 *                   if no words from the text were added to the ignore list a
 *                   sentence stating this is to be printed;
 *                   otherwise a list of only words that have been added to the
 *                   ignore list from the text are printed one per line in a
 *                   two-column table with each row consisting of the line number,
 *                   starting from 1, and the word
 *
 *     getWord    takes a position in the list, starting from 1
 *                if this position exists in the list, the function returns the
 *                word at this position and the boolean value of source of this
 *                word, with false being the initial ignore word file and true
 *                being the text file being indexed.
 *                The function returns another boolean value indicating whether
 *                or not a word was found at the specified position. If this value
 *                is false then the other two return values are undefined.
 *
 *     size       returns the length of the ignore list, i.e. the total number
 *                of words on the list.
 *
 ******************************************************************************/

#include "globals.h"
#include <iostream>
using namespace std;

class ignoreList
{
 public:
  ignoreList();
  ~ignoreList();

  void load(istream &in);
  bool contains (const WORD aWord);
  void insert(const WORD aWord, bool fromWhere);
  void write(ostream &os);
  void getWord (int position, WORD aWord, bool &fromWhere, bool &found);
  int size();

 private:
  struct ignoreNode
  {
    WORD aWord;
    bool fromText;
  };

  ignoreNode *ignoreWords;
  int maxSize;
  int fillLevel;

  void newArray(ignoreNode* &temp);


};


#endif
