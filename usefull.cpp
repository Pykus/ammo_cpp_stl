#include <string>
#include <tuple>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
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




void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)//void(*func)(int)
{
	for (int value :values)
		func(value);
/*
 * std::vector<int> values = {1,2,3,4,5};
    auto lambda = [](int value) { std::cout<< "Value: "<< value << std::endl;}

 * ForEach(values, lambda);
 */
	
}

template <typename T, size_t N>    //template to nie tylko T
void func(const std::array<T, N>& arr)
{
    std::cout << std::size(arr);
    /*
    std::array arr{ 1, 2, 3, 4, 5 };
    func(arr);
    */
}


    


