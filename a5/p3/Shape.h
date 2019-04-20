#ifndef SHAPE
#define SHAPE

#include "Grid.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 2
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: Shape.h

 */

class Shape
{
public:
    Shape(int lft, int up, int rght, int low);

    void move(int new_left, int new_upper);

    virtual void draw(Grid& aGrid) = 0;

protected:
    void get_bounding_box(int& lft, int& up, int& rght, int& low) const;

private:
    int left;
    int upper;
    int right;
    int lower;

};

#endif
