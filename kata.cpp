#include "TEST_miniframework.cpp"
#include <math.h>
#include <string>
#include <vector>
const double phi = 1.61803398874989484820;
#include "helpers.hpp"

bool isPerfectSquare(int x) {
  int s = sqrt(x);
  return (s * s == x);
};
bool isFibonacci(int n) {
  // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or
  // both is a perfect square
  return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

typedef unsigned long long ull;

ull BinetNFibonacciNumber(const ull n) {
  // std::cout << (pow(phi, n) - pow(-phi, n)) / (std::sqrt(5));
  return (pow(phi, n) - pow(-phi, n)) / (std::sqrt(5));
};

int fib(int n) {
  if (n < 3)
    return 1;

  return fib(n - 2) + fib(n - 1);
}
void pushBackReturn(ull li, bool YesOrNo, std::vector<ull> &ret) {
  ret.push_back(fib(li));
  ret.push_back(fib(li + 1));
  ret.push_back(YesOrNo);
};

class ProdFib {
public:
  static std::vector<ull> productFib(ull prod) {
    std::vector<ull> ret{};
    ull n = std::sqrt(prod);
    ull li = (log(n) + (log(5) / 2)) / (log(phi));
    ull local_prod = fib(li) * fib(li + 1);

    if (prod == local_prod) {
      pushBackReturn(li, true, ret);
    } else if (prod < local_prod) {
      pushBackReturn(li, false, ret);
    } else { // prod>loca_prod
      bool increment_li = true;
      while (increment_li) {
        li += 1;
        local_prod = fib(li) * fib(li + 1);
        if (prod < local_prod) {
          increment_li = false;
          pushBackReturn(li, false, ret);
        };
      };
    };
    return ret;
  };
};

;
// std::cout << prod << " " << local_prod << " " << (prod == local_prod);
int main() {

  TEST(Task7_Fib_produ) {
    EXPECT((ProdFib::productFib(4895) == std::vector<ull>{55, 89, true}));
    EXPECT((ProdFib::productFib(5895) == std::vector<ull>{89, 144, false}));
    EXPECT(
        (ProdFib::productFib(74049690) == std::vector<ull>{6765, 10946, 1ULL}));
  };

  return 0;
}
