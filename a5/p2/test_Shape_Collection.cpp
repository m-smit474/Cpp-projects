#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "Grid.h"
#include "Shape.h"
#include "Shape_Collection.h"
#include <gtest/gtest.h>


class Shape_CollectionTests : public testing::Test
{
protected:
  virtual void SetUp()
  {
  }

  virtual void TearDown()
  {
  }
 
    Grid c;

};

TEST_F(Shape_CollectionTests, WriteNamesTest)
{
    Shape_Collection myShapes;
    stringstream actualOutput;
    string expected = "";

    myShapes.write_names(actualOutput);

    EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_CollectionTests, AddTest)
{
    Shape_Collection myShapes;
    stringstream actualOutput;
    string expected = "s2, s1";
    Shape* shapePtr = new Shape(0,0,5); 

    myShapes.add(shapePtr, "s1");
    shapePtr = new Shape(0,6,5);       
    myShapes.add(shapePtr, "s2");
    myShapes.write_names(actualOutput);

    EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_CollectionTests, DrawShapesTest)
{
    Shape_Collection myShapes;
    stringstream actualOutput;
    string expected = "";
    Shape* shapePtr = new Shape(0,0,5); 


    expected += "--------------------------------------------------\n";
    expected += "*****                                             \n";
    expected += "*   *                                             \n";
    expected += "*   *                                             \n";
    expected += "*   *                                             \n";
    expected += "*****                                             \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "                                                  \n";
    expected += "--------------------------------------------------\n";


    myShapes.add(shapePtr, "s1");
    myShapes.draw_shapes(actualOutput);

    EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_CollectionTests, RemoveTest)         // not a very effective test
{
    Shape_Collection myShapes;
    stringstream actualOutput;
    string expected = "s1";
    Shape* shapePtr = new Shape(0,0,5); 

    myShapes.add(shapePtr, "s1");
    shapePtr = new Shape(0,6,5);
    myShapes.add(shapePtr, "s2");
    myShapes.remove("s2");
    myShapes.write_names(actualOutput);

    EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_CollectionTests, LookupTest)
{
    Shape_Collection myShapes;
    Shape* shapePtr = new Shape(0,0,5); 
    Shape* actual;

    myShapes.add(shapePtr, "s1");
    actual = myShapes.lookup("s2");

    EXPECT_EQ(NULL, actual);
}
