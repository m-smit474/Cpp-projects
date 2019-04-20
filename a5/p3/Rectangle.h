#ifndef RECTANGLE
#define RECTANGLE

#include "Shape.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 3
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: Rectangle.h

 */

class Rectangle : public Shape
{
public:

    Rectangle(int lft, int up, int width, int height);

    void draw(Grid& aGrid);

};

#endif
