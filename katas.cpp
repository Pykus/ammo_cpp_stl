#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "helpers.hpp"
#include <gtest/gtest.h> 

using pp::displayRange;
using pp::br;
TEST(HelloTest, BasicAssertions)
{
    EXPECT_STRNE("hello","world");
    EXPECT_EQ(7*6,42);
}

std::vector<uint64_t> powers_of_two(int n) 
{
 /* Task-1 powers of 2
 powers_of_two(4) ->  std::vector<uint64_t>{1, 2, 4, 8, 16}
 powers_of_two(10) ->  std::vector<uint64_t>{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}*/
    std::vector<uint64_t> result {};
    for(auto i = 0; i <= n; i++)
    {         
        result.emplace_back(pow(2,i));
    }
    return result;
    //for(uint64_t i = 1; n + 1; i <<= 1, --n) res.push_back(i);
}
auto val_min(const std::vector<int>& vec)
{
    return *(std::min_element(vec.begin(),vec.end()));
    /*
    int currentMin = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (list[i] < currentMin) {
            currentMin = list[i];
        }
    }
    return currentMin;*/

}
auto val_max(const std::vector<int>& vec)
{
    return *(std::max_element(vec.begin(),vec.end()));
    //return *std::max_element(std::begin(list), std::end(list)); }
    /*int currentMax = list[0];
        for (int i = 1; i < list.size(); i++) {
            if (list[i] > currentMax) {
                currentMax = list[i];
            }
        }
    return currentMax;*/
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

TEST(Task2_MinFromList, ReturnMinValueFromList)
{
    EXPECT_EQ((val_min({-52, 56, 30, 29, -54, 0, -110})) , -110);
    EXPECT_EQ((val_min({42, 54, 65, 87, 0})) , 0);
    EXPECT_EQ((val_min({42})) , 42);
    
 }
TEST(Task2_MaxFromList, ReturnMaxValueFromList)
{
   EXPECT_EQ((val_max({-52, 56, 30, 29, -54, 0, -110})) , 56);
}


TEST(Task1_PowersOfTwo, GivenANumberReturnsPowersOfTwoUpToThisNumberAsVector)
{
    EXPECT_EQ(std::vector<uint64_t>{1},powers_of_two(0));
    EXPECT_EQ((std::vector<uint64_t>{1,2}),powers_of_two(1));
    EXPECT_EQ((std::vector<uint64_t>{1,2,4}),powers_of_two(2));
    EXPECT_EQ((std::vector<uint64_t>{1,2,4,8}),powers_of_two(3));
}

