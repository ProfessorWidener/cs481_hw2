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

TEST(TLBTest, TestsIntests)
{
    int PFN;
    TLB* tlb = new TLB(4,4);
    tlb->add_entry(0, 16, 256);
    tlb->add_entry(1, 16, 312);
    tlb->add_entry(2, 16, 1024);
    tlb->add_entry(3, 16, 0);

    PFN = TLB_lookup(tlb, 64);
    ASSERT_EQ(PFN, 256);

    PFN = TLB_lookup(tlb, 65);
    ASSERT_EQ(PFN, 312);

    PFN = TLB_lookup(tlb, 66);
    ASSERT_EQ(PFN, 1024);

    PFN = TLB_lookup(tlb, 67);
    ASSERT_EQ(PFN, 0);

    delete tlb; 
}
