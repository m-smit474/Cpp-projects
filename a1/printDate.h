#ifndef PRINT_DATE_H
#define PRINT_DATE_H

#include <iostream>
using namespace std;

/**********************************************************************/
// Function Name:    printDate
// Purpose:          to output a date in words for a valid date or a
//                   meaningful error message.
//
// Details:          if the date is valid the output will be in the format of
//                   "weekday, month day, year"
//                   where weekday and month are the corresponding words
//                   for these values.
//                   To be valid a date must be composed of:
//                      a year >= 0
//                      a month >= 1 and <= 12
//                      a day >= 1 and <= the days in the corresponding
//                        month and year combination which must be valid,
//                        if the month or year are invalid then any day value
//                        > 31 will be considered invalid.
//
//                   if the date has an invalid component then an error
//                   message specifying all invalid components will be
//                   output. 
//
// Input Parameters: day   - an integer representing a day of the week
//                   month - an integer representing a month
//                   year  - an integer representing a year
//                   os    - an open output stream
//
// Output Parameter: os    - the updated output stream containing all output
//                           from this function.
//
/**********************************************************************/

void printDate(int day, int month, int year, ostream &os);

#endif
