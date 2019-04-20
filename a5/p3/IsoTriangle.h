#ifndef ISOTRIANGLE
#define ISOTRIANGLE

#include "Shape.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 3
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: IsoTriangle.cpp

 */

class IsoTriangle : public Shape
{
public:

    IsoTriangle(int lft, int up, int baseWidth, int height);

    void draw(Grid& aGrid);

};

#endif
