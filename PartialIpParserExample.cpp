#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <array>
#include <utility>
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

/*************/

#include <vector>
#include <sstream>  
#include <algorithm>
#include <cctype>
#include <utility>
#include <optional>

class IpAddress {
public:
    virtual std::string getAddress() = 0;
    virtual int getPort() = 0;
    virtual std::pair<bool, std::optional<std::string>> validateAddress(const std::string &) = 0;
    virtual void setAddress(const std::string &, int) = 0;
};

class IpAddressv4 : public IpAddress {
public:
    std::string getAddress() override { return m_ipaddress; };
    int getPort() override { return m_port; };

    bool validateAddress(const std::string &ipAddress){
        //   getline(str, token, delim);  

        std::array<int, 4> addressArr;   
        int i = 0;
        std::string dummystr;
        std::stringstream x(ipAddress);
        while(std::getline(x,dummystr,'.'))
        {
            if (std::any_of(dummystr.cbegin(), dummystr.cend(), [] (unsigned char ch) { return std::isdigit(ch); } ))
            {
                
            }
            
            try {
            addressArr.at(i) = std::stoi(dummystr);
            } catch (const std::out_of_range &e) {
                std::cerr << "Out of range Exception \n";
                
            }
            i++;
        }

        




    }

    void setAddress(const std::string &ipAddress, int port) override 
    { 
        m_ipaddress = ipAddress; 
        m_port = port; 
        validateAddress(ipAddress);
    };

private:
    std::string m_ipaddress;
    int m_port;
};
class IpAddressv6 : public IpAddress {
    
};
int main() {
    TEST(IsIpAddressv4Created)
    {
        IpAddressv4 ipv4;
        //EXPECT()
    };

    TEST(IsIpAdddressSetv4)
    {
        std::string givenAddress = "0.0.0.0";
        int givenPort = 1;

        IpAddressv4 ipv4;
        ipv4.setAddress(givenAddress, givenPort);

        EXPECT(ipv4.getAddress() == givenAddress);

    };

    
    TEST(IsIpPortSetv4)
    {
        std::string givenAddress = "0.0.0.0";
        int givenPort = 1;

        IpAddressv4 ipv4;
        ipv4.setAddress(givenAddress, givenPort);

        EXPECT(ipv4.getPort() == givenPort);

    };




}