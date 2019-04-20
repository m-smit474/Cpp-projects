/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  3 
  Due Date:    Wednesday, March 6, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: a3main.cpp

 ==============================================================================

Purpose: This program creates an image file of a hilbert curve based on the 
         level given.

Details: The base cases of the  drawing functions is the the level 1
         hilbert curve of that direcion. Using only the level one curves
         of the four directionsyou can create any level hilbert curve.
         The side length can be determined after you know the level and the
         screen size. The number of sides is equal to 2^level - 1.

Input    - integer level
         - integer screen size
         - output file name 


Output   - Creates an image file

Assumptions / Limitations:  
                           Level must be > 0
                           Output file name must be of vaild format (.gif, etc)


 */

#include <Magick++.h>
#include <iostream>
#include <cmath>
#include "ioutil.h"
#include "ioutil.cpp"

using namespace std;
using namespace Magick;

struct Coordinates
{
    int x;
    int y;
};


void horizontalLine(int row, int start, int end, Image& hilbertCurve);
void verticalLine(int colum, int start, int end, Image& hilbertCurve);
int findUpper(int numOfSides, int upperLength, int idealSize);
void hilbertCurveUp(int level, Coordinates& start, Coordinates end,
		    int actualLength, Image& hilbertCurve);
void hilbertCurveLeft(int level, Coordinates& start, Coordinates end,
		      int actualLength, Image& hilbertCurve);
void hilbertCurveRight(int level, Coordinates& start, Coordinates end,
		       int actualLength, Image& hilbertCurve);
void hilbertCurveDown(int level, Coordinates& start, Coordinates end,
		      int actualLength, Image& hilbertCurve);



int main()
{
    const char levelPrompt[45] = "Enter hilbert level (min value of 1): ",
	screenSizePrompt[35] = "Enter the desired screen size: ",
	outFileNamePrompt[35] = "Enter output filename: ";


    int size,
	level,
	idealSize,
	borderSize = 100,
	numOfSides,
	upperLength,
	lowerLength,
	actualLength,
	actualSize;
    char outFileName[13];
    bool eof;
    Coordinates startPosition,
	endPosition;

    cout << endl;

    level = readInt(levelPrompt, eof);
    size = readInt(screenSizePrompt, eof);
    readString(outFileNamePrompt, outFileName, 12, 4, eof);

// calculations
    idealSize = size - (borderSize * 2);
    numOfSides = static_cast<int>(pow(2.0, level )) - 1;
    upperLength = findUpper(numOfSides, 0, idealSize);
    lowerLength = upperLength - 1;

    if( idealSize - (numOfSides * lowerLength) < 
	(numOfSides * upperLength) - idealSize )
    {
	actualLength = lowerLength;
    }
    else
    {
	actualLength = upperLength;
    }

    actualSize = actualLength * numOfSides;

    startPosition.x = (size - actualSize) / 2;
    startPosition.y = (size - actualSize) / 2;



    if(level >= 1 && actualLength > 1)
    {
	// make image
       // wasn't able to do Geoometry without doing decleration (sub-obtimal)

	Image hilbertCurve(Geometry(size,size), "white");


	hilbertCurveUp(level, startPosition, endPosition, actualLength,
		       hilbertCurve);


	hilbertCurve.write(outFileName);

    }
    else if (level < 1)
    {
	cout << endl << "Level Invalid -- Below 1" << endl << endl;
    }
    else if (actualLength <= 2)
    {
	cout << endl << "Screen Size Invalid -- Too Small" << endl << endl;
    }
    


    return 0;
}

/*
Purpose: To draw a horizontal line on the image.

Details: Uses the given start position to recursivley draw a pixel on the 
         given row until it reaches the end position.

Input    - The row that will be used
         - The starting x position 
         - The ending x position
         - The image that will be drawn to

Returns  - The updated image variable

 */
void horizontalLine(int row, int start, int end, Image& hilbertCurve)
{
    int length;

    if(start <= end)
    {
	length = end - start;

	if(length > 0)
	{
	    hilbertCurve.pixelColor(start, row, "red");
	    horizontalLine(row, start + 1, end, hilbertCurve);
	}
    }
    else
    {
	length = start - end;

	if(length > 0)
	{
	    hilbertCurve.pixelColor(start, row, "red");
	    horizontalLine(row, start - 1, end, hilbertCurve);
	}
    }

    return;
}
/*
Purpose: To draw a vertical line on the image.

Details: Uses the given start position to recursivley draw a pixel on the 
         given colum until it reaches the end position.

Input    - The colum that will be used
         - The starting y position 
         - The ending y position
         - The image that will be drawn to

Returns  - The updated image variable
 */

void verticalLine(int colum, int start, int end, Image& hilbertCurve)
{
    int length;


    if(start <= end)                          // "Positive" line
    {
	length = end - start;
	if(length > 0)
	{
	    hilbertCurve.pixelColor(colum, start, "red");
	    verticalLine(colum, start + 1, end, hilbertCurve);
	}
    }
    else                                     // "Negative" line
    {
	length = start - end;

	if(length > 0)
	{
	    hilbertCurve.pixelColor(colum, start, "red");
	    verticalLine(colum, start - 1, end, hilbertCurve);
	}
    }


    return;
}

/*
 
Purpose: To find the upper side length

Details: Finds the upper side length based on the number of sides and the
         target size.

Input    - The number of sides
         - The starting upperLength (typically 0)
         - The screen size calculated based on the given screen size
           and the border size.

Returns  - The fisrt side length  that would be bigger than the ideal 
           screen size

 */
int findUpper(int numOfSides, int upperLength, int idealSize)
{
    if( (upperLength * numOfSides) < idealSize)
    {
	upperLength = findUpper(numOfSides, upperLength + 1, idealSize);
    }

    return upperLength;
}
/*
Purpose: To create an up facing hilbert curve of a given level.

Details: Has a base case of the up facing level 1 curve. For all other levels
         the curve consists of four variations of the previous level. In this 
         case it goes left, up, up, right with the proper connecting lines.

Input    - The level
         - The starting position
         - The ending position
         - The calculated side length
         - The hilbert curve image variable

Returns  - The new starting position
         - The updated hilber curve image


 */

void hilbertCurveUp(int level, Coordinates& start, Coordinates end,
		    int actualLength, Image& hilbertCurve)
{
    if(level == 1)
    {

//	cout << "Start: "  << start.x << ',' << start.y 
//	     << "  End : " << end.x << ',' << end.y << endl;


	end.y = start.y + actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	end.x = start.x + actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;


	end.y = start.y - actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;


    }
    else
    {
	hilbertCurveLeft(level - 1, start, end, actualLength, hilbertCurve);


	end.y = start.y + actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;


	hilbertCurveUp(level - 1, start, end, actualLength, hilbertCurve);


	end.x = start.x + actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;


	hilbertCurveUp(level - 1, start, end, actualLength, hilbertCurve);


	end.y = start.y - actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	hilbertCurveRight(level - 1, start, end, actualLength, hilbertCurve);

    }

    return;
}
/*
Purpose: To create a left facing hilbert curve of a given level.

Details: Has a base case of the left facing level 1 curve. For all other levels
         the curve consists of four variations of the previous level. In this 
         case it goes up, left, left, down with the proper connecting lines.

Input    - The level
         - The starting position
         - The ending position
         - The calculated side length
         - The hilbert curve image variable

Returns  - The new starting position
         - The updated hilber curve image

 */

void hilbertCurveLeft(int level, Coordinates& start, Coordinates end,
		    int actualLength, Image& hilbertCurve)
{
    if(level == 1)
    {
//	cout << "Start: "  << start.x << ',' << start.y << endl;


	end.x = start.x + actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;


	end.y = start.y + actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;


	end.x = start.x - actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;

    }
    else
    {
	hilbertCurveUp(level - 1, start, end, actualLength, hilbertCurve);


	end.x = start.x + actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;


	hilbertCurveLeft(level - 1, start, end, actualLength, hilbertCurve);

	end.y = start.y + actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	hilbertCurveLeft(level - 1, start, end, actualLength, hilbertCurve);

	end.x = start.x - actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;

	hilbertCurveDown(level - 1, start, end, actualLength, hilbertCurve);


    }


    return;
}

/*
Purpose: To create a right facing hilbert curve of a given level.

Details: Has a base case of the right facing level 1 curve. For all other levels
         the curve consists of four variations of the previous level. In this 
         case it goes down, right, right, up with the proper connecting lines.

Input    - The level
         - The starting position
         - The ending position
         - The calculated side length
         - The hilbert curve image variable

Returns  - The new starting position
         - The updated hilber curve image

 */

void hilbertCurveRight(int level, Coordinates& start, Coordinates end,
		    int actualLength, Image& hilbertCurve)
{
    if (level == 1)
    {
	end.x = start.x - actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;

	end.y = start.y - actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	end.x = start.x + actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;
    }
    else
    {

	hilbertCurveDown(level - 1, start, end, actualLength, hilbertCurve);

	end.x = start.x - actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;


	hilbertCurveRight(level - 1, start, end, actualLength, hilbertCurve);

	end.y = start.y - actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	hilbertCurveRight(level - 1, start, end, actualLength, hilbertCurve);

	end.x = start.x + actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;

	hilbertCurveUp(level - 1, start, end, actualLength, hilbertCurve);


    }

    return;
}

/*
Purpose: To create a down facing hilbert curve of a given level.

Details: Has a base case of the down facing level 1 curve. For all other levels
         the curve consists of four variations of the previous level. In this 
         case it goes right, down, down, left with the proper connecting lines.

Input    - The level
         - The starting position
         - The ending position
         - The calculated side length
         - The hilbert curve image variable

Returns  - The new starting position
         - The updated hilber curve image

 */

void hilbertCurveDown(int level, Coordinates& start, Coordinates end,
		    int actualLength, Image& hilbertCurve)
{
    if (level == 1)
    {
	end.y = start.y - actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	end.x = start.x - actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;

	end.y = start.y + actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;
    }
    else
    {
	hilbertCurveRight(level - 1, start, end, actualLength, hilbertCurve);

	end.y = start.y - actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	hilbertCurveDown(level - 1, start, end, actualLength, hilbertCurve);

	end.x = start.x - actualLength;
	horizontalLine(start.y, start.x, end.x, hilbertCurve);
	start.x = end.x;

	hilbertCurveDown(level - 1, start, end, actualLength, hilbertCurve);

	end.y = start.y + actualLength;
	verticalLine(start.x, start.y, end.y, hilbertCurve);
	start.y = end.y;

	hilbertCurveLeft(level - 1, start, end, actualLength, hilbertCurve);

    }

    return;
}

