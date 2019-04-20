/*

 */
#include "ioutil.h"
#include "globals.h"
#include "indexList.h"
#include "ignoreList.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int main()
{
    const char bookPrompt[35] = "Enter file name for book: ",
	ignorePrompt[35] = "Enter file name for ignore words: ",
	writeIgnorePrompt[50] = "Do you want to print ignore words added?(y/n):";

    indexPtr indexHead = NULL;
    ignorePtr ignoreHead = NULL;
    char bookFileName[WORD_MAX],
	ignoreFileName[WORD_MAX],
	response[2];
    int maxlen = WORD_MAX,
	minlen = 1,
	index = 0,
	maxCount = 6;
    bool bookEOF = false,
	ignoreEOF = false,
	success = true;
    ifstream bookFile,
	ignoreFile;
    ofstream ignoreFormat;
    WORD word;


    readString(bookPrompt, bookFileName, maxlen, minlen, bookEOF);

    bookFile.open(bookFileName);

    if(!bookFile.fail())
    {
	readString(ignorePrompt, ignoreFileName, maxlen, minlen, ignoreEOF);

	ignoreFile.open(ignoreFileName);

	if(ignoreFile.fail())
	    cout << "Failed to open ignore words file \n";
	else
	{                    // Fill ignore list
	    ignoreFile >> word;
	    while(!ignoreFile.eof())
	    {
		insertInIgnoreList(ignoreHead, word, false);

		ignoreFile >> word;
	    }
	    cout << endl;	    
	    writeIgnoreList(ignoreHead, cout); 

	}



	bookFile >> word;          // Reading word from book unitl end of file
	while(!bookFile.eof())
	{
// Making word lower case
	    for(index = 0 ; word[index] != '\0' ; index++) 
	    {
		word[index] = static_cast<char>( tolower(word[index]) );
	    }
// Test if word should be added to index list:
// If word is more than 3 charecters and
// If word is not on ignore list and
// If word does not begin with a digit then process
	    if(strnlen(word,WORD_MAX) >= 4 && !findInIgnoreList(ignoreHead,word)
		&& word[0] >= 'a' && word[0] <= 'z')
	    {
		updateIndexList(indexHead, word, maxCount, success);

		if(!success)                       // word count too high
		{
		    insertInIgnoreList(ignoreHead, word, true);
		}
	    }


	    bookFile >> word;
	}
	writeIndexList(indexHead, cout);

	readString(writeIgnorePrompt, response, 1, 1, ignoreEOF);
	cout << endl;

	if(response[0] == 'y')
	{
	    writeIgnoreList(ignoreHead, cout);
	}


                                  	// Delete all nodes
	destroyIndexList(indexHead);
	destroyIgnoreList(ignoreHead);


    }
    else
	cout <<"failed to open file\n";


    bookFile.close();
    ignoreFile.close();

    return 0;
} 
