#include <string>
#include <tuple>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
struct P
{           
    int x;
    int y;
};
P p = {1,2};//p.x p.y
auto[x,y] = p; //x y

struct P2
{
    int x;
    int y;
    std::string s;
};
auto func() -> P2 {
    //std::tuple<int,int,std::string> t {1,2, std::string("abc")};
    return {1,2, std::string("abc")}; //t;
}
auto[x,y,z] = func();




void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value :values)
		func(value);
/*
 * std::vector<int> values = {1,2,3,4,5};
 * ForEach(values, [](int value) { std::cout<< "Value: "<< value << std::endl;});
 */
	
}



