#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Grid.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "IsoTriangle.h"
#include "EquTriangle.h"
#include "Shape_Collection.h"
#include "ioutil.h"

#define QUIT 'q'
#define ADD 'a'
#define DELETE 'd'
#define MOVE 'm'

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 3
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: main.cpp

 */


void show_menu();

string getShapeName();
void getUpperLeft (int& xtop, int& ytop);
int getWidth();
int getHeight();
char getShapeType();

void doAdd (Shape_Collection& shapes);
void doDelete (Shape_Collection& shapes);
void doMove (Shape_Collection& shapes);
bool doQuit ();
void eof_message();

int main()
{
    Shape_Collection myShapes;
    char choice;
    char choiceStr[2];
    bool done = false;
    bool eof = false;

    do
    {
	myShapes.write_names (cout);
	cout << endl;
	myShapes.draw_shapes(cout);
	show_menu();
	readString("Please enter choice: ", choiceStr, 1, 1, eof);
	if (eof)
	{
	    choice = QUIT;
	}
	else
	{
	    choice = choiceStr[0];
	}
	switch (choice)
	{
	case ADD:    doAdd (myShapes);
	    break;
	case DELETE: doDelete (myShapes);
	    break;
	case MOVE:   doMove (myShapes);
	    break;
	case QUIT:   done = doQuit ();
	    break;
	default:     cout << choice << " is unknown command" << endl;
	    break;
	}
    }
    while (!done);

    return 0;
}


void show_menu()
{
    cout << "Options:  a(dd shape)" << endl;
    cout << "          d(elete) shape" << endl;
    cout << "          m(ove) shape" << endl;
    cout << "          q(uit) paint program" << endl;
    return;
}

void getUpperLeft (int& xtop, int& ytop)
{
    bool eof;

    do
    {
	xtop = readInt ("Enter x coordinate for upper left corner of bounding box: ", eof);
	if (eof)
	{
	    eof_message();
	}
    } while (eof);

    do
    {
	ytop = readInt ("Enter y coordinate for upper left corner of bounding box: ", eof);
	if (eof)
	{
	    eof_message();
	}
    } while (eof);
    
    return;
}

int getWidth ()
{
    int width = 1;
    bool eof;

    // enter code to read and return a valid shape width
    width = readInt("Enter width > 0: ", eof);
    while(width <= 0 || eof)
    {
	width = readInt("Enter width > 0: ", eof);
    }

    return width;
}

int getHeight ()
{
    int height = 1;
    bool eof;

    // enter code to read and return a valid shape height
    height = readInt("Enter height > 0: ", eof);
    while(height <= 0 || eof)
    {
	height = readInt("Enter height > 0: ", eof);
    }

    return height;
}

char getShapeType ()
{
    char shapeType = 'r';
    bool eof = false,
	success = false;
    char choice[1];

    // enter code to read and return a valid shape type
    while(!success || eof)
    {
	readString("Enter type of shape(r, s, i, e): ", choice, 1, 1, eof);
   
	if(choice[0] != 'r' && choice[0] != 's' && 
	   choice[0] != 'i' && choice[0] != 'e')
	{
	    cout << "Invalid Shape choice; not r,s,i or e." << endl;	    
	}
	else
	    success = true;
    }	
    shapeType = choice[0];

    return shapeType;
}

string getShapeName()
{
    string result;

    cout << "Please enter shape name (no blanks): ";
    cin >> result;
    cin.ignore(256, '\n');   // eliminate any trailing input & the newline

    return result;
}

void doMove (Shape_Collection& myShapes)
{

    // stub
    // enter code to move a shape
    //
    // get the name of the shape
    // if the name does not exist in the shape collection
    // then
    //    report and terminate
    // else
    //    get new upper left coordinates
    //    "ask the shape to do the move"
    string name;
    bool eof;
    Shape* shapePtr;
    int newLeft, newUpper;

//    readString("Enter the name of the shape: ", name, 12, 1, eof);
//    while(eof)
//    {
//	readString("Enter the name of the shape: ", name, 12, 1, eof);
//    }

    name = getShapeName();

    shapePtr = myShapes.lookup(name);

    if(shapePtr == NULL)
	cout << "Shape not found." << endl;
    else
    {
	newLeft = readInt("Enter new left position: ", eof);
	while(eof)
	{
	    newLeft = readInt("Enter new left position: ", eof);
	}

	newUpper = readInt("Enter new upper position: ", eof);
	while(eof)
	{
	    newUpper = readInt("Enter new upper position: ", eof);
	}

	// move shape
	shapePtr->move(newLeft,newUpper);

    }

    return;
}

void doDelete (Shape_Collection& myShapes)
{

    // stub
    // enter code to delete a shape
    //
    // get the name of the shape
    // if the name does not exist in the shape collection
    // then
    //    report and terminate
    // else
    //    "ask the shape collection to do the delete"
    string name;
    Shape* shapePtr;

//    readString("Enter the name of the shape: ", name, 12, 1, eof);
//    while(eof)
//    {
//	readString("Enter the name of the shape: ", name, 12, 1, eof);
//    }

    name = getShapeName();

    shapePtr = myShapes.lookup(name);

    if(shapePtr == NULL)
	cout << "Shape was not found." << endl;
    else
	myShapes.remove(name);

    return;
}

void doAdd (Shape_Collection& myShapes)
{

    // stub
    // enter code to add a shape
    //
    // get the name of the new shape
    // if the name exists in the shape collection
    // then
    //    report and terminate
    // else
    //    get the type of shape
    //    get the required positional and size information for the shape
    //    "ask the shape collection to do the add"

    string name;
//    char name[13];
    char typeOfShape;
    bool eof = false;
    Shape* shapePtr = NULL;
    int left, upper, width, height;

/*    readString("Enter the name of the shape: ", name, 12, 1, eof);
      while(eof)
      {
      readString("Enter the name of the shape: ", name, 12, 1, eof);
      }
*/

    name = getShapeName();

    shapePtr = myShapes.lookup(name);

    if(shapePtr != NULL)       // Name was found on list
    {
	cout << "Name is already used; cannot add." << endl;
    }
    else
    {
	typeOfShape = getShapeType();
	
// read position
	eof = false;

	left = readInt("Enter left position: ", eof);
	while(eof)
	{
	    left = readInt("Enter left position: ", eof);
	}
	upper = readInt("Enter upper position: ", eof);
	while(eof)
	{
	    upper = readInt("Enter upper position: ", eof);
	}


	if(typeOfShape == 'r')
	{
	    // Add rectangle
	    width = getWidth();
	    height = getHeight();

	    shapePtr = new Rectangle(left, upper, width, height);
	}
	else if(typeOfShape == 's')
	{
	    // add square 
	    width = getWidth();

	    shapePtr = new Square(left, upper, width);
	}
	else if(typeOfShape == 'i')
	{
	    // add iso triangle
	    width = getWidth();
	    height = getHeight();

	    shapePtr = new IsoTriangle(left, upper, width, height);
	}
	else if(typeOfShape == 'e')
	{
	    // add equ triangle
	    width = getWidth();

	    shapePtr = new EquTriangle(left, upper, width);
	}
		

// add shape to list
	myShapes.add(shapePtr, name);
	

	
    }

    return;
}

bool doQuit ()
{
    bool done;
    bool eof;

    done = readBool ("Are you sure you are done painting? (y/n) ", eof);
    if (done || eof)
	cout << "I've had fun painting with you! Bye..." << endl;
    else
	cout << "Back we go..." << endl;

    return done;
}

void eof_message()
{
    cout << "typing CTRL-d is not acceptable here - "
	 << "if you wish to terminate the program type CTRL-c" << endl;

    return;
}
