// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "hw2_src/virtual_to_physical.hpp"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

TEST(VPNTest, TestsIntests)
{
    int page_size, virtual_address, vpn, offset;

    page_size = 4096;
    virtual_address = 65536;
    split_virtual_address(virtual_address, page_size, &vpn, &offset);
    ASSERT_EQ(offset, 0);

    virtual_address = 68999;
    split_virtual_address(virtual_address, page_size, &vpn, &offset);
    ASSERT_EQ(offset, 3463);

    page_size = 1024;
    virtual_address = 65536;
    split_virtual_address(virtual_address, page_size, &vpn, &offset);
    ASSERT_EQ(offset, 0);

    page_size = 1024;
    virtual_address += 3000;
    split_virtual_address(virtual_address, page_size, &vpn, &offset);
    ASSERT_EQ(offset, 952);
}
