#include "Shape.h"
#include "Grid.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 2
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: Shape.cpp

 */
/*********************************************************************
 *
 *  CLASS: Shape
 *
 *  PURPOSE: A group of positions for a shape on a grid
 *
 *
 *  PRIVATE DATA MEMBERS:
 *
 *  left - The leftmost position of the shape
 *  
 *  upper - The upmost position of the shape
 *
 *  right - The rightmost position of the shape
 *
 *  lower - The lowest position of the shape
 *
 *********************************************************************/

/*********************************************************************
 *
 *  FUNCTION: Shape
 *
 *  PURPOSE: initializes a shape to the specified size.
 *
 *  INPUT: lft - the left position of the shape
 *         up - the upper position of the shape
 *         width - the width of the shape
 *
 *********************************************************************/

Shape :: Shape(int lft, int up, int rght, int low)
{
    left = lft;
    upper = up;
    right = rght;
    lower = low;
}

/*********************************************************************
 *
 *  FUNCTION: move
 *
 *  PURPOSE: moves the shape to a new position on the grid
 *
 *  METHOD: - calculates the width of the shape 
 *          - assigns the new positions
 *
 *  INPUT: new_left - the new leftmost position of the shape
 *         new_upper - the new upper position of the shape
 *
 *********************************************************************/

void Shape :: move(int new_left, int new_upper)
{
    int width;

    width = right - left;

    left = new_left;
    upper = new_upper;
    right = left + width;
    lower = upper + width;

}

/*********************************************************************
 *
 *  FUNCTION: get_bounding_box
 *
 *  PURPOSE: gets the postion of the shape on the Grid
 *
 *  METHOD: - assigns the passed vales to the corresponding data members 
 *          
 *  INPUT:  - integers that will be assigned to the position of the shape
 *
 *  RETURNS: - the position values of the shape
 *
 *********************************************************************/

void Shape :: get_bounding_box(int& lft, int& up, int& rght, int& low) const
{
    lft = left;
    up = upper;
    rght = right;
    low = lower;
}
