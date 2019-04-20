#include "IsoTriangle.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 3
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: IsoTriangle.cpp

 */

IsoTriangle :: IsoTriangle(int lft, int up, int baseWidth, int height) :
    Shape(lft, up, lft + baseWidth, up + height)
{
}

void IsoTriangle :: draw(Grid& aGrid)
{
    int left, upper, right, lower, width;

    get_bounding_box(left, upper, right, lower);
    width = right - left;

    aGrid.plot_line(left + (width/2),upper, left,lower);  // Left line
    aGrid.plot_line(left + (width/2),upper, right,lower); // Right line 
    aGrid.plot_line(left,lower, right,lower);             // Bottom line
}
