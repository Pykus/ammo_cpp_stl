#include <iostream>
#include <iterator>
#include <vector>
#include "helpers.hpp"
void c_function(int* CArrayPointer, size_t size)
{
    //c_function(vector<int>.data(), vector<int>.size())
}

template <typename FIT>
void displayRange(FIT first, FIT last)
{
    while (first != last)
    {
        std::cout << *first++ <<", ";
    }
}

using pp::br;
int main()
{
    //////////////////////////////////////////////////////////
    std::vector<int> primes {2,3,5,7,11,13};

    int product = 1;
    int sum = 0;

    for (size_t i = 0; i < primes.size(); ++i)
    {
        product *= primes.at(i);
        sum += primes[i];
    }
    std::cout << "Product: "<< product << std::endl << "Sum: "<< sum << std::endl;
 
    std::cout << "Front: " << primes.front() << std::endl << "Back: " << primes.back() <<std::endl;
    std::cout << "Size: " << primes.size() << std::endl;
    br();
    auto it = primes.insert(primes.end(), 17);
    ////auto it = primes.emplace(primes.begin(),17);
    std::cout << *it;
    br();

    br();
    displayRange(primes.rbegin(), primes.rend());//use Forward Iterator to iterate from end to start
    br();
    displayRange(primes.begin(), primes.end());
    br();

    ////////////////////////////////////////////////////////////////////////////
    std::vector<int> v1 {1,2,3,5,6,7,8,9};

    //#include <iterator>
    //OutputIt copy(InputIt first, InputIt last, OutputIt destination_first)
    std::copy(v1.begin(),v1.end(),
            std::ostream_iterator<int>(std::cout,"-"));

 
    return 0;
}