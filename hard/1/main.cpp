#include <iostream>
#include <random>

int main()
{
  int64_t lower,upper,guess,count = 0;
  bool found = false;
  std::random_device rd;
  std::mt19937 gen(rd());

  std::cout << "Enter the range:";
  std::cin >> lower >> upper;

  while(!found)
  {
    std::cout << "Is your guess 1) Less than, 2) Equal to OR 3) Greater than\n";
    std::uniform_int_distribution<> dis(lower,upper);
    guess = dis(gen); 
    std::cout << guess << std::endl;
    char result;
    std::cin >> result;
    switch(result){
      case '1': upper = guess - 1;
                break;
      case '2': found = true;
                break;
      case '3': lower = guess + 1;
                break;
    }
    ++count;
  }

  std::cout << "Guessed the right answer in " << count << " tries!" << std::endl;
  return 0;
}



