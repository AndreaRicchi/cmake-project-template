#include <gtest/gtest.h>

#include "library_template/lib.hpp"

TEST(LibTest, InterfaceReturn)
{
    Lib lib;
    EXPECT_EQ(lib.helloWorldMsg(), "Hello World!\n");
}