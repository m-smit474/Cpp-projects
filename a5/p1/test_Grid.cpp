#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "Grid.h"
#include <gtest/gtest.h>


class GridTests : public testing::Test
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


TEST_F(GridTests, DefaultConstructorTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
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
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(GridTests, plotPointTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "*                                                 \n";
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
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_point(0,0);
  c.write(actualOutput);

  EXPECT_EQ(expected, actualOutput.str());

}

TEST_F(GridTests, plotVerticalLineTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(0,0, 0,14);
  c.write(actualOutput);

  EXPECT_EQ(expected, actualOutput.str());

}

TEST_F(GridTests, plotHorizontalLineTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "**************************************************\n";
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
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(0,0, 49,0);
  c.write(actualOutput);

  EXPECT_EQ(expected, actualOutput.str());

}

TEST_F(GridTests, plotNegativeVerticalLineTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "*                                                 \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(0,14, 0,0);
  c.write(actualOutput);

  EXPECT_EQ(expected, actualOutput.str());

}

TEST_F(GridTests, plotNegativeHorizontalLineTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "**************************************************\n";
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
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(49,0, 0,0);
  c.write(actualOutput);

  EXPECT_EQ(expected, actualOutput.str());

}

TEST_F(GridTests, plotDiagonalLineTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "*                                                 \n";
  expected += " *                                                \n";
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
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(0,0, 1,1);
  c.write(actualOutput);

  EXPECT_EQ(expected, actualOutput.str());

}

TEST_F(GridTests, OveridenOperatorTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
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
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}
