#include <iostream>
#include <vector>
#include <math.h>
#include "helpers.hpp"
#include <gtest/gtest.h> 

using pp::displayRange;
using pp::br;

TEST(HelloTest, BasicAssertions)
{
    EXPECT_STRNE("hello","world");
    std::cout<<"hello?";
    EXPECT_EQ(7*6,42);
}


std::vector<uint64_t> powers_of_two(int n) 
{
 /* Task-1 powers of 2
 powers_of_two(0) ->  std::vector<uint64_t>{1}
 powers_of_two(2) ->  std::vector<uint64_t>{1, 2, 4}
 powers_of_two(4) ->  std::vector<uint64_t>{1, 2, 4, 8, 16}
 powers_of_two(10) ->  std::vector<uint64_t>{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}
*/
    std::vector<uint64_t> result {};
    for(auto i = 0; i <= n; i++)
    {         
        result.emplace_back(pow(2,i));
    }
    return result;
   /*main() Task-1 solution
    std::vector<uint64_t> v1;
    v1 = powers_of_two(4);
    displayRange(v1.begin(), v1.end());
    s/*/
 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}