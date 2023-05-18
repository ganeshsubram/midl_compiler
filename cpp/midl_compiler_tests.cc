
#include "messages.hh"

#include <gtest/gtest.h>

// Define your test cases and tests

TEST(MidlCompilerTests, ScratchTest)
{
    examples::messages::ExampleMsg msg;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
