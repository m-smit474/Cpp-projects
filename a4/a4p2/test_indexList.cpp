#include "indexList.h"
#include <gtest/gtest.h>
#include <fstream>

class test_indexList : public testing :: Test {
protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    indexList index;

};


TEST_F(test_indexList, testDefaultConstructorCount)
{
    EXPECT_EQ(0, index.getCount("test\0") );
}

TEST_F(test_indexList, testDefaultConstructorSize)
{
// Might be 1
    EXPECT_EQ(0 ,index.size() );
}


TEST_F(test_indexList, testSearch)
{
// 3 tests 
// Word less than n, word greater than n, word not on list

}


TEST_F(test_indexList, testUpdateNewWord)
{
    bool success = false,
	found = false;
    WORD testWord = "Yo";

    index.update(testWord, 7, success);
    index.getWord(1, testWord, found);  

    EXPECT_EQ(true, found);
    EXPECT_EQ(true, success);
}


/*
TEST_F(test_indexList, testWrite)
{
    ostream output;

    index.write(output);

// Will need to be changed based on output format
//    EXPECT_EQ("1    Yo      1", output);

}

*/
