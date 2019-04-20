#include <cstdlib>
#include "Grid.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 1
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: Grid.cpp

 */

Grid :: Grid ( )
{
   int i, j;


   for (j = 0; j < YMAX; j++)
   {
      for (i = 0; i < XMAX; i++)
      {
         raster[j][i] = ' ';
      }
      raster[j][XMAX] = EOLN;
      raster[j][XMAX+1] = EOSTR;
   } 
   return;
}

void Grid :: plot_point (int x, int y)
{
   if (is_in_bounds (x, y))
      raster[y][x] = '*';
   return;
}

void Grid :: plot_line (int x1, int y1, int x2, int y2)
{
   int deltax, deltay;                         // required run for line
   int x, y;                                   // coordinates of a point
   int xinc1, xinc2;                           // x increments per pixel
   int yinc1, yinc2;                           // y increments per pixel
   int numerator, denominator;                 // ratio of per pixel changes
   int numeratorincrement;                     // numerator increment per pixel
   int numPixels;                              // largest run

   int pixCount;                               // loop control variables
   deltax = abs(x2 - x1);
   deltay = abs(y2 - y1);


   if (x2 >= x1)
   {
      xinc1 = 1;
      xinc2 = 1;
   }
   else
   {
      xinc1 = -1;
      xinc2 = -1;
   }
   if (y2 >= y1)
   {
      yinc1 = 1;
      yinc2 = 1;
   }
   else
   {
      yinc1 = -1;
      yinc2 = -1;
   }
   if (deltax >= deltay)
   {
      xinc1 = 0;
      yinc2 = 0;
      denominator = deltax;
      numerator = deltax / 2;
      numeratorincrement = deltay;
      numPixels = deltax;
   }
   else
   {
      xinc2 = 0;
      yinc1 = 0;
      denominator = deltay;
      numerator = deltay / 2;
      numeratorincrement = deltax;
      numPixels = deltay;
   }
   x = x1;
   y = y1;

   for (pixCount = 0; pixCount <= numPixels; pixCount++)
   {
      plot_point(x, y);
      numerator += numeratorincrement;
      if (numerator >= denominator)
      {
         numerator -= denominator;
         x += xinc1;
         y += yinc1;
      }
      x += xinc2;
      y += yinc2;
   }

   return;
}


void Grid :: write (ostream& out) const
{
   int i;

   for (i = 0; i < XMAX; i++)
      out << '-';
   out << endl;
   for (i = 0; i < YMAX; i++)
   {
     out << raster[i];
   }
   for (i = 0; i < XMAX; i++)
      out << '-';
   out << endl;

   return;
}


ostream& operator << (ostream& out, const Grid& g)
{
   g.write(out);
   
   return out;
}


bool Grid :: is_in_bounds (int x, int y) const
{
   return ((0 <= x && x < XMAX) && (0 <= y && y < YMAX));
}
