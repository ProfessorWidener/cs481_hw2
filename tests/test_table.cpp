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

TEST(PageTableTest, TestsIntests)
{
    int PFN;
    bool exception;
    PageTable* table = new PageTable(16);
    TLB* tlb = new TLB(4,2);
    table->add_page(4, 16, 0, 1);
    table->add_page(6, 25, 1, 1);
    table->add_page(8, 0, 1, 0);
    table->add_page(15, 2, 0, 0);

    PFN = table_lookup(table, tlb, 4);
    ASSERT_EQ(PFN, 16);

    try
    {
        exception = false;
        PFN = table_lookup(table, tlb, 6);
    }
    catch (const char* msg)
    {
        ASSERT_STREQ(msg, "Protection Fault!");
        exception = true;
    }
    ASSERT_EQ(exception, true);


    try
    {
        exception = false;
        PFN = table_lookup(table, tlb, 8);
    }
    catch (const char* msg)
    {
        ASSERT_STREQ(msg, "Segmentation Fault!");
        exception = true;
    }
    ASSERT_EQ(exception, true);


    try
    {
        exception = false;
        PFN = table_lookup(table, tlb, 15);
    }
    catch (const char* msg)
    {
        ASSERT_STREQ(msg, "Segmentation Fault!");
        exception = true;
    }
    ASSERT_EQ(exception, true);


    try
    {
        exception = false;
        PFN = table_lookup(table, tlb, 2);
    }
    catch (const char* msg)
    {
        ASSERT_STREQ(msg, "Page Fault!");
        exception = true;
    }
    ASSERT_EQ(exception, true);


    delete tlb;
    delete table; 
}
