#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "helpers.hpp"
//#include <gtest/gtest.h> 
#include <string>
#include <sstream>
#include <iostream>
struct TestCase { std::string name{}; std::ostringstream failures{}; };
template <typename T> void operator | (TestCase& testCase, T&& testBody) {
    testBody(); auto failures = testCase.failures.str();
    if (failures.empty()) std::cout << testCase.name << ": SUCCESS\n";
    else std::cerr << testCase.name << ": FAILURE\n" << failures;
}
void addFailure(std::ostream& os, const char* file, unsigned line, const char* condition) {
    os << file << ":" << line << ": Failed: " << condition << "\n";
}
#define TEST(name) TestCase name{#name}; name | [&, &failures = name.failures]
#define EXPECT(cond) if (cond) {} else addFailure(failures, __FILE__, __LINE__, #cond)
#define ASSERT(cond) if (cond) {} else return addFailure(failures, __FILE__, __LINE__, #cond)

using pp::displayRange;
using pp::br;
/*uncomment if using google test
TEST(HelloTest, BasicAssertions)
{
    EXPECT_STRNE("hello","world");
    EXPECT_EQ(7*6,42);
}*/

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



std::vector<int> digitize(unsigned long n) 
{        
    /* Task-3 split number into digits
Given a random non-negative number, you have to return the digits of this number within an array in reverse order.
Example(Input => Output):
348597 => [7,9,5,8,4,3]
0 => [0]
*/
    std::vector <int> result;
 //   for(;n<10;result.push_back(n%10),n/=10);
 //   displayRange(result.begin(),result.end());
    
    while(n!=0){
        result.push_back(n%10);//fetch the LSB of the number
        n = n / 10;//right shift the number
    };
    /*v3
  std::vector<int> result{};
  while(n>10)
    {
    result.push_back(n%10);
    n/=10;  
  };
  result.push_back(n);
  */
    return result;
  
};

std::string howManyDalmatians(int number){
    /*
        Assert::That(howManyDalmatians(26), Equals("More than a handful!"));
        Assert::That(howManyDalmatians(8), Equals("Hardly any"));
        Assert::That(howManyDalmatians(14), Equals("More than a handful!"));
        Assert::That(howManyDalmatians(80), Equals("Woah that's a lot of dogs!"));
        Assert::That(howManyDalmatians(100), Equals("Woah that's a lot of dogs!"));
        Assert::That(howManyDalmatians(50), Equals("More than a handful!"));
        Assert::That(howManyDalmatians(10), Equals("Hardly any"));
        Assert::That(howManyDalmatians(101), Equals("101 DALMATIONS!!!"));
    */
  std::vector<std::string> dogs { "Hardly any", "More than a handful!",
  "Woah that's a lot of dogs!", "101 DALMATIONS!!!" };
  return  number <= 10  ? dogs[0] :
          number <= 50 ? dogs[1] :
          number == 101 ? dogs[3] :
                          dogs[2];
    /*
    switch(number){
      case 1  ... 10: return "Hardly any";
      case 11 ... 50: return "More than a handful!";
      case 51 ... 100: return "Woah that's a lot of dogs!";
      default: return "101 DALMATIONS!!!";
    */
};


std::vector<int> reverse_range(const int& n)
{
    std::vector<int> result{};
    for(int i=n;i>0;i--)
        result.push_back(i);
    //v2// while ( n ) result.push_back(n--);
    //v3// std::generate(result.begin(), result.end(), [n]()mutable{ return n--; });
    return result;
};

auto countPositivesSumNegatives(const std::vector<int>& input)
{
    /*Return an array, where the first element is the count of positives
     numbers and the second element is sum of negative numbers. 0 is neither positive nor negative.
    //if(input.size()==0) return std::vector<int>{};
    */
    std::pair<int,int> ret{0,0};
    for(const auto& elem : input)
    {
        elem>0 ? ret.first+=1 : ret.second+=elem;
    }
    return ret;//std::pair<int,int>{10,-65};
}


int main(int argc, char **argv)
{
    //auto res =countPositivesSumNegatives({1, -2, -2, 2});
    //std::cout<<res.first<<" "<<res.second;
    //reverse_range(5);
    TEST(countPositivesAndSumNegativesInVector)
    {
    EXPECT(( countPositivesSumNegatives({}) == std::pair<int,int>{} ));
    EXPECT(( countPositivesSumNegatives({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15}) == std::pair<int,int>{10, -65} ));
    };
    
    TEST(Task4_displayListFromNto0)
    {
        EXPECT(( reverse_range(5) == std::vector<int>{5,4,3,2,1} )); 
        //EXPECT(( reverse_range(2) == std::vector<int>{2,1} ));
    };
    TEST(Task3_splitNumberIntoDigits)
    {
        EXPECT((digitize(35231) == std::vector<int>{ 1,3,2,5,3})); //
    };
    TEST(Task2_MinFromList)
    {
    EXPECT((val_min({-52, 56, 30, 29, -54, 0, -110})==-110));
    EXPECT((val_min({42, 54, 65, 87, 0})== 0));
    EXPECT((val_min({42})== 42));
    
    };
    TEST(Task2_MaxFromList)
    {
    EXPECT((val_max({-52, 56, 30, 29, -54, 0, -110}) == 56));
    };
    TEST(Task1_PowersOfTwo)
    {
    EXPECT(( std::vector<uint64_t>{1} == powers_of_two(0) ));
    EXPECT(( std::vector<uint64_t>{1,2} == powers_of_two(1) ));
    EXPECT((std::vector<uint64_t>{1,2,4} == powers_of_two(2) ));
    EXPECT((std::vector<uint64_t>{1,2,4,8} == powers_of_two(3) ));
    };
    TEST(Task_embedded_ternary_working){//instead of embeded ternary you can use switch-> check howManyDalmatioans definition comments
        EXPECT((howManyDalmatians(26)== std::string{"More than a handful!"}));
        EXPECT((howManyDalmatians(8)== std::string{"Hardly any"}));
        EXPECT((howManyDalmatians(14)== std::string{"More than a handful!"}));
        EXPECT((howManyDalmatians(80)== std::string{"Woah that's a lot of dogs!"}));
        EXPECT((howManyDalmatians(100)== std::string{"Woah that's a lot of dogs!"}));
        EXPECT((howManyDalmatians(50)== std::string{"More than a handful!"}));
        EXPECT((howManyDalmatians(10)== std::string{"Hardly any"}));
        EXPECT((howManyDalmatians(101)== std::string{"101 DALMATIONS!!!"}));
    };
    //::testing::InitGoogleTest(&argc,argv);
    //return RUN_ALL_TESTS();
    return 0;
}


/*google test version of tests
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

*/