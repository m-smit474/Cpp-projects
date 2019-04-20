#ifndef SHAPE_COLLECTION
#define SHAPE_COLLECTION

#include <string>

using namespace std;

#include "Shape.h"

/*********************************************************************
 *
 *  CLASS: Shape_Collection
 *
 *  PURPOSE: A collection of pointers to shape objects.
 *           The order of elements is irrelevant.
 * 
 *  Each shape is associated with a name used for lookup and removal.
 *  The shapes are assumed to have been dynamically allocated from the 
 *  heap by the client.
 *  The collection takes custody of these shapes, and therefore it will 
 *  deallocate them as necessary.
 *
 *  ASSUMPTIONS: 
 *  1. The client never adds duplicate shape pointers
 *  2. The client never adds a shape under an already-existing name
 *
 *********************************************************************
 *
 *  PUBLIC METHODS:
 *
 *********************************************************************
 *
 *  Shape_Collection
 *         PURPOSE: initializes an empty collection
 *
 *********************************************************************
 *
 *  ~Shape_Collection
 *         PURPOSE: deallocates all shape objects
 *
 *********************************************************************
 *
 *  add
 *         PURPOSE: adds the given shape pointer to the collection,
 *                  associating it with the given name.
 *
 *         INPUT: shape - a pointer to a dynamically allocated shape
 *                name  - the name to associated with the shape
 *
 *********************************************************************
 *
 *  remove
 *
 *         PURPOSE: removes the named shape from the collection, if it
 *                  exists.  The shape object is deallocated.
 *
 *         INPUT: name - the name of the shape to remove
 *
 *********************************************************************
 *
 *  lookup
 *
 *         PURPOSE: retrieves the pointer to the named shape
 *
 *         INPUT: name - the name of the shape to look up
 *
 *         RETURNS: the pointer, or NULL if no such shape
 *
 *********************************************************************
 *
 *  draw_shapes
 *
 *         PURPOSE: renders all shapes in the collection
 *
 *         INPUT: out - the output stream to use
 *
 *         OUTUPT: out - the output stream has been written to
 *
 *********************************************************************
 *
 *  write_names
 *
 *         PURPOSE: writes the list of shape names in the collection
 *
 *         INPUT: out - the output stream to use
 *
 *         OUTPUT: out - the output stream has been written to
 *
 *********************************************************************/


class Shape_Collection
{
public:
   Shape_Collection ();
   ~Shape_Collection ();

   void add (Shape* shape, string name);
   void remove (string name);

   Shape* lookup (string name) const;

   void draw_shapes (ostream& out) const;
   void write_names (ostream& out) const;

private:
   struct Node
   {
      Node* next;
      Node* prev;

      Shape* shape;
      string name;
   };

   Shape_Collection (const Shape_Collection& orig);
   Shape_Collection& operator= (const Shape_Collection& rhs);

   void remove_all ();
   Node* lookup_node (string name) const;
   Node* head;
};


#endif
