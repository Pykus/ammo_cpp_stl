#include "helpers.hpp"
#include <array>

using pp::displayRange;
using pp::br;
int main()
{
    std::array<int, 3> a1 {1,2,3};
    a1.fill(7);
    displayRange(a1.begin(),a1.end());
    br();
    //.empty()   .size()   .max_size()

    std::array<int,3> a2 {5,4,3};
    a1.swap(a2);
    std::printf("a1:");
    displayRange(a1.begin(),a1.end());
    br();
    
    br("//EOF/");
    return 0;

}