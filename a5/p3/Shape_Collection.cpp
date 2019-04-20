#include "Shape_Collection.h"

/*

  Name: Matthew Smith
  MRU E-mail:  msmit474@mtroyal.ca
  Course:      COMP 1633-001
  Assignment:  5 part 2
  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
  Instructor:  Paul Pospisil

  Source File: Shape_Collection.cpp

 */
/*********************************************************************
 *
 *  CLASS: Shape_Collection
 *
 *  PURPOSE: A collection of pointers to shape objects.
 *           The order of elements is irrelevant.
 *
 *  PRIVATE DATA MEMBERS:
 *
 *  head - a pointer to the head node of a doubly linked list, NULL if
 *         the list is empty
 *
 *  NOTES:
 *  Each node contains:
 *
 *       - a pointer to the "next" node, NULL for tail node
 *
 *       - a pointer to the "prev" (previous) node, NULL for head node
 *
 *       - shape: a pointer to a dynamically allocated shape object
 *
 *       - name: the name associated with that shape
 *
 *  The list is doubly linked to simplify the implementation of "remove".
 *  The "lookup_node" helper function returns a pointer to a node.  
 *  Therefore, "remove" can simply take this node, unlink it from its 
 *  "prev" and "next" neighbours (if any), and then deallocate.
 *
 *********************************************************************/

/*********************************************************************
 *
 *  FUNCTION: Shape_Collection
 *
 *  PURPOSE: initializes an empty collection.
 *
 *********************************************************************/

Shape_Collection :: Shape_Collection () : head (NULL)
{
}


/*********************************************************************
 *
 *  FUNCTION: ~Shape_Collection
 *
 *  PURPOSE: deallocates all dynamically allocated
 *           memory by removing all nodes.
 *
 *********************************************************************/

Shape_Collection :: ~Shape_Collection ()
{
   while (head != NULL)
      remove(head->name);
}


/*********************************************************************
 *
 *  FUNCTION: add
 *
 *  PURPOSE: adds the given shape pointer to the collection,
 *           associating it with the given name.
 *
 *  METHOD: - allocate the node
 *          - link it in at the front of the list
 *          - store the shape pointer and name inside
 *
 *  INPUT: shape - a pointer to a dynamically allocated shape
 *         name  - the name to associated with the shape
 *
 *********************************************************************/

void Shape_Collection :: add (Shape* shape, string name)
{
   Node* new_node = new Node;

   new_node->next = head;
   new_node->prev = NULL;
   new_node->shape = shape;
   new_node->name = name;

   if (head != NULL)
     head->prev = new_node;

   head = new_node;
}

/*********************************************************************
 *
 *  FUNCTION: remove
 *
 *  PURPOSE: removes the named shape from the collection, if it exists.
 *           The shape object is deallocated.
 *
 *  METHOD: - look up the node
 *          - if it exists:
 *               - if it has a successor, set successor's 
 *                 predecessor to by-pass this node
 *               - if it has a predecessor, set predecessor's
 *                 successor to by-pass this node
 *               - if it has no predecessor (i.e. it was at the
 *                 front of the list) update the head pointer
 *               - deallocate the shape object
 *               - deallocate the node
 *
 *  INPUT: name - the name of the shape to remove
 *
 *********************************************************************/

void Shape_Collection :: remove (string name)
{
   Node* gone = lookup_node (name);

   if (gone != NULL)
   {
      if (gone->next != NULL)
         gone->next->prev = gone->prev;
   
      if (gone->prev != NULL)
         gone->prev->next = gone->next;
      else
         head = gone->next;

      delete gone->shape;
      delete gone;
   }
}


/*********************************************************************
 *
 *  FUNCTION: lookup
 *
 *  PURPOSE: retrieves the pointer to the named shape
 *
 *  INPUT: name - the name of the shape to look up
 *
 *  RETURNS: the pointer, or NULL if no such shape
 *
 *********************************************************************/

Shape* Shape_Collection :: lookup (string name) const
{
   Shape* found = NULL;
   Node* gotit = lookup_node(name);

   if (gotit != NULL)
      found = gotit->shape;

   return found;
}

/*********************************************************************
 *
 *  FUNCTION: draw_shapes
 *
 *  PURPOSE: draws all the shapes in the collection to the screen
 *           
 *
 *  METHOD: - instantiates a grid object
 *          - create a temporary pointer and make equal to head
 *          - goes through the list starting at the head:
 *               - draws the shape at the current node to the grid
 *          - write the grid to the output stream
 *          
 *  INPUT: out - the output stream that will be written to
 *
 *  OUTPUT: out - the output stream that has been written to
 *
 *********************************************************************/

void Shape_Collection :: draw_shapes (ostream& out) const
{
    Grid grid;
    Node* temp = head;

    while(temp != NULL)
    {
	temp->shape->draw(grid);

	temp = temp->next;
    }

    grid.write(out);             
    

}

/*********************************************************************
 *
 *  FUNCTION: draw_shapes
 *
 *  PURPOSE: draws all the shapes in the collection to the screen
 *           
 *
 *  METHOD: - create a temporary pointer and make equal to head
 *          - goes through the list starting at the head:
 *               - write the name of the shape at the current node to the stream
 *               - if the list has more nodes, prints a comma
 *          
 *  INPUT: out - the output stream that will be written to
 *
 *  OUTPUT: out - the output stream that has been written to
 *
 *********************************************************************/

void Shape_Collection :: write_names (ostream& out) const
{
    Node* temp = head;

    while(temp != NULL)
    {
                                       // Might need square brackets
	out << temp->name;

	if(temp->next != NULL)
	{
	    out << ", ";
	}

	temp = temp->next;
    }

}

/*********************************************************************

 *********************************************************************/

Shape_Collection :: Shape_Collection (const Shape_Collection& orig)
{
  // DUMMY IMPLEMENTATION - NOT CALLABLE FROM CLIENT
}


/*********************************************************************

 *********************************************************************/

Shape_Collection& Shape_Collection :: operator = (const Shape_Collection& rhs)
{
  // DUMMY IMPLEMENTATION - NOT CALLABLE FROM CLIENT
  return *this;
}


/*********************************************************************
 *
 *  FUNCTION: lookup_node
 *
 *  PURPOSE: looks up the node with the given name
 *
 *  METHOD: sequential search algorithm
 *
 *  INPUT: name - the name of the shape to look up
 *
 *  RETURNS: a pointer to the node containing the named shape, NULL
 *           if not found
 *
 *  REMARKS:
 *      Node is defined in the private data area of the Shape_Collection
 *      class. As a consequence, when it is returned directly, its 
 *      "location" must be resolved by using the scope operator as a
 *      prefix
 *      i.e.  return type of Shape_Collection::Node*
 *            says "you can find this definition in
 *            the Shape_Collection class"
 *********************************************************************/

Shape_Collection::Node* Shape_Collection :: lookup_node (string name) const
{
   bool found = false;
   Node* curr = head;

   while (!found && curr != NULL)
   {
      if (curr->name == name)            // can use with C++ string class
         found = true;
      else
         curr = curr->next;
   }
   return curr;
}
