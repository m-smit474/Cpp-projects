#include "globals.h"
#include "indexList.h"
#include <gtest/gtest.h>

    indexPtr head;
    WORD word;
    int maxCount;
    bool success;


TEST(test_indexList, EmptyListInsert )
{
    head = NULL;
    strncpy(word, "Hello", WORD_MAX);
    maxCount = 6;
    success = false;

    updateIndexList(head, word, maxCount, success);

    ASSERT_EQ(success, true);


}

