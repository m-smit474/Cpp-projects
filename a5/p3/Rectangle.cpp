#include "Rectangle.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 3
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: Rectangle.cpp

 */

Rectangle :: Rectangle(int lft, int up, int width, int height) :
    Shape(lft, up, lft + width, up + height)
{
}

void Rectangle :: draw(Grid& aGrid)
{
    int left, upper, right, lower;

    get_bounding_box(left, upper, right, lower);

    aGrid.plot_line(left,upper, right,upper);     // Top line
    aGrid.plot_line(left,upper, left,lower);      // Left line
    aGrid.plot_line(right,upper, right,lower);    // Right line
    aGrid.plot_line(left,lower, right,lower);     // Bottom line
}
