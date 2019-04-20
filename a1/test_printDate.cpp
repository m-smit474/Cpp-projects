/*
  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  1
  Due Date:    Monday, January 28, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

=============================================================================

Purpose: This program test the functionality of the print date function

Details: There are 26 test cases cover the different possible inputs
         that a user could perform              
 */

#include "printDate.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(test_printDate, lowerYearBoundary)
{
    stringstream result;

    printDate(15,3,0,result);

    ASSERT_EQ(result.str(),"Thursday, March 15, 0\n"); 

}

TEST(test_printDate, fiveDigitYear)
{

    stringstream result;

    printDate(7,2,11111,result);

    ASSERT_EQ(result.str(), "Tuesday, February 7, 11111\n");

}

TEST(test_printDate, leapYear)
{

    stringstream result;
    
    printDate(29,2,2000,result);

    ASSERT_EQ(result.str(), "Tuesday, February 29, 2000\n");


}

TEST(test_printDate, lowerMonthBoundary)
{

    stringstream result;

    printDate(8,1,1999,result);

    ASSERT_EQ(result.str(), "Friday, January 8, 1999\n" );

}

TEST(test_printDate, upperMonthBoundary)
{

    stringstream result;

    printDate(7,12,2000,result);

    ASSERT_EQ(result.str(), "Thursday, December 7, 2000\n" );


}

TEST(test_printDate, lowerDayBoundary)
{

    stringstream result;

    printDate(1,3,1999,result);

    ASSERT_EQ(result.str(), "Monday, March 1, 1999\n" );

}

TEST(test_printDate, leapYearLowerDayBoundary)
{

    stringstream result;

    printDate(1,3,2000,result);

    ASSERT_EQ(result.str(), "Wednesday, March 1, 2000\n" );

}

TEST(test_printDate, upperDayBoundaryFebruary)
{

    stringstream result;

    printDate(28,2,1999, result);

    ASSERT_EQ(result.str(), "Sunday, February 28, 1999\n" );

}

TEST(test_printDate, upperDayBoundaryApril)
{

    stringstream result;

    printDate(30,4,1999,result);

    ASSERT_EQ(result.str(), "Friday, April 30, 1999\n" );

}

TEST(test_printDate, leapYearUpperDayBoundaryApril)
{

    stringstream result;

    printDate(30,4,2000,result);

    ASSERT_EQ(result.str(), "Sunday, April 30, 2000\n" );

}

TEST(test_printDate, upperDayBoundaryMarch)
{

    stringstream result;

    printDate(31,3,1999,result);

    ASSERT_EQ(result.str(), "Wednesday, March 31, 1999\n" );

}

TEST(test_printDate, leapYearUpperDayBoundaryMarch)
{

    stringstream result;

    printDate(31,3,2000,result);

    ASSERT_EQ(result.str(), "Friday, March 31, 2000\n" );

}

TEST(test_printDate, monthAndDayLowerBoundary)
{

    stringstream result;

    printDate(1,1,2000,result);

    ASSERT_EQ(result.str(), "Saturday, January 1, 2000\n" );

}

TEST(test_printDate, monthAndDayUpperBoundary)
{

    stringstream result;

    printDate(31,12,1999,result);

    ASSERT_EQ(result.str(), "Friday, December 31, 1999\n" );


}

TEST(test_printDate, negativeYear)
{

    stringstream result;

    printDate(8,5,-100,result);

    ASSERT_EQ(result.str(), "negative year\n" );

}

TEST(test_printDate, negativeMonth)
{

    stringstream result;

    printDate(8,-5,100,result);

    ASSERT_EQ(result.str(), "negative month\n" );

}

TEST(test_printDate, negativeDay)
{

    stringstream result;

    printDate(-8,5,100,result);

    ASSERT_EQ(result.str(), "negative day\n" );

}

TEST(test_printDate, dayExceedingFebruary)
{

    stringstream result;

    printDate(29,2,1999,result);

    ASSERT_EQ(result.str(), "day greater than max for this month\n" );

}

TEST(test_printDate, dayExceedingFebruaryLeapYear)
{

    stringstream result;

    printDate(30,2,2000,result);

     ASSERT_EQ(result.str(), "day greater than max for this month\n" );

}

TEST(test_printDate, dayExceedingApril)
{

    stringstream result;

    printDate(31,4,2000,result);

    ASSERT_EQ(result.str(), "day greater than max for this month\n" );

}

TEST(test_printDate, dayExceedingMarch)
{

    stringstream result;

    printDate(32,3,2000,result);

    ASSERT_EQ(result.str(), "day greater than max for this month\n" );

}

TEST(test_printDate, monthGreaterThan12)
{

    stringstream result;

    printDate(7,13,2000,result);

    ASSERT_EQ(result.str(), "month greater than December\n" );

}

TEST(test_printDate, dayLessThan1)
{

    stringstream result;

    printDate(0,3,1999,result);

    ASSERT_EQ(result.str(), "zero day\n" );

}

TEST(test_printDate, monthLessThan1)
{

    stringstream result;

    printDate(7,0,2000,result);

    ASSERT_EQ(result.str(), "zero month\n" );

}

TEST(test_printDate, negativeYearAndDay)
{

    stringstream result;

    printDate(-7,4,-100,result);

    ASSERT_EQ(result.str(), "negative year, negative day\n" );

}

TEST(test_printDate, negativeMonthAndDay)
{

    stringstream result;

    printDate(-7,-4,100,result);

    ASSERT_EQ(result.str(), "negative month, negative day\n" );

}
