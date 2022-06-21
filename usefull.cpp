#include <string>
#include <tuple>
#include <utility>
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