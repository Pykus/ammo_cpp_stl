#ifndef HELPERS
#define HELPERS

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

namespace pp {
void br(std::string desc="")
{
    std::cout << desc <<std::endl;
    
}

template <typename FIT>
void displayRange(FIT first, FIT last)
{
    while (first != last)
    {
        std::cout << *first++ <<", ";
    }
}

}
#endif
