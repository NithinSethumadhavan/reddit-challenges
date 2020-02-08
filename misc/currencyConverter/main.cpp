#include <iostream>
#include "CurrencyFetcher.hpp"

int main(int argc, char * argv[])
{
  double rate = currencyFetch::getCurrency(); 
  std::string eurStr = argv[1];
  double eurVal = std::stod(eurStr);
  double ans = eurVal * rate;
  std::cout << ans << std::endl;
  return 0;

}
