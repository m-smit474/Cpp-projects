#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
using namespace std;
#include "globals.h"

class Grid
{
public:
   Grid ();
   void plot_point (int x, int y);
   void plot_line (int x1, int y1, int x2, int y2);
   void write (ostream&) const;

private:
   char raster[YMAX][XMAX+2];
   bool is_in_bounds (int x, int y) const;
};


ostream& operator << (ostream&, const Grid&);


#endif
