#include <iostream>
#include <string>
#include <vector>
#include <memory>

template <typename T>
constexpr std::string_view type_name()
{
    using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view()(p.data() + 34, p.size() -34 -1);
#elif defined (__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
# if __cplusplus <201402
    return string_view(p.data() +35, p.size() -36 -1);
# else
    return string_view(p.data() + 49,p.find(';',49) - 49);
#endif // __clang__
#endif
}

template <typename T>
void func(T& param){
    std::cout<< type_name<T>()<<'\n';
    std::cout<<type_name<decltype(param)>()<<'\n';
}
template <typename T>
void func(T&& param){
    std::cout<< type_name<T>()<<'\n';
    std::cout<<type_name<decltype(param)>()<<'\n';
}


auto func2() ->std::vector<int>{
    return {0};
}
template <typename T>
auto func3(T const& t, T const& u) -> decltype(t+u){
    return t+u;
}

int main(){
    //auto x = {1.0f,2.1f};
    auto x = std::make_unique<int> (42);
    //func(func3(1.0,2.0));
    func(x);
    return 0;
}
