#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "Grid.h"
#include "Shape.h"
#include <gtest/gtest.h>


class ShapeTests : public testing::Test
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


TEST_F(ShapeTests, MoveTest)
{
  stringstream actualOutput;
  string expected = "";
  Shape square(0,0,5);

  expected += "--------------------------------------------------\n";
  expected += "    *****                                         \n";
  expected += "    *   *                                         \n";
  expected += "    *   *                                         \n";
  expected += "    *   *                                         \n";
  expected += "    *****                                         \n";
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

  square.move(4,0);
  square.draw(c);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str()); 
}

TEST_F(ShapeTests, DefaultConstructorTest)
{
  stringstream actualOutput;
  string expected = "";
  Shape square(0,0,5);

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

  square.draw(c);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}
