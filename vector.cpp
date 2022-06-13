#include <iostream>
#include <iterator>
#include <vector>
#include "helpers.hpp"
void c_function(int* CArrayPointer, size_t size)
{
    //c_function(vector<int>.data(), vector<int>.size())
}


using pp::br;
using pp::displayRange;
int main()
{
    br("////////////////////////////////////////////////////////////////////////////");
    std::vector<int> primes {2,3,5,7,11,13};
    br("Primes examples with: ");
    displayRange(primes.begin(),primes.end());
    br();

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
    
    br("Insert 17 at primes.end()");
    auto it = primes.insert(primes.end(), 17);
    ////auto it = primes.emplace(primes.begin(),17);
    std::cout << *it;
    br("<-*it showed this");
    br("Primes now:");
    displayRange(primes.rbegin(), primes.rend());  br("from .rbegin() to .rend()");
    displayRange(primes.begin(), primes.end());
    br("from .begin() to .end()");

    br("////////////////////////////////////////////////////////////////////////////");
    
    br("Examples with vector:");
    std::vector<int> v1 {1,2,3,4,5,6,7,8,9};
    //#include <iterator>
    //OutputIt copy(InputIt first, InputIt last, OutputIt destination_first)
    std::copy(v1.begin(),v1.end(),
            std::ostream_iterator<int>(std::cout,","));
    br("//copy to ostream_iterator used");
    
    br(".erase");
    v1.erase(v1.begin());
    displayRange(v1.begin(),v1.end());
    v1.emplace(v1.begin(),1);
    br();
    displayRange(v1.begin(),v1.end());


    br(".pop_back (deleted last, no return)");
    v1.pop_back(); //-> delete last, no return
    v1.emplace_back(9);
    br("pop_back deleted last element (9) so emplace_back added 9 manualy");
    displayRange(v1.begin(),v1.end());

    br("After .resize(6) and resize(9) -> data lost");
    v1.resize(6);
    v1.resize(9);
    displayRange(v1.begin(), v1.end());
    v1.at(6) =7;
    v1.at(7) =8;
    v1.at(8) =9;
    displayRange(v1.begin(), v1.end());
    br();


    br("v1 and v2");
    std::vector<int> v2 {0};
    displayRange(v1.begin(),v1.end()); br("<-v1");
    displayRange(v2.begin(),v2.end()); br("<-v2");
    v1.swap(v2); br("after v1.swap(v2);");
    displayRange(v1.begin(),v1.end()); br("<-v1");
    displayRange(v2.begin(),v2.end()); br("<-v2");
    
    
 
    return 0;
}