#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <string>

#include "colors.h"

void hr()
{
  std::cout
      << std::endl
      << BLUE
      << "-----------------------------------"
      << CLEAR
      << std::endl;
}

int main()
{
  std::cout << BLUE << "Zadanie 1" << CLEAR;
  hr();

  std::vector<int> numbers = {100, 54, 90, 420, 69};

  std::vector<int>::iterator numbers_it = numbers.begin();

  for (numbers_it; numbers_it != numbers.end(); numbers_it++)
    std::cout << *numbers_it << std::endl;

  std::cout << ORANGE << "----" << CLEAR << std::endl;

  std::vector<int>::reverse_iterator numbers_it_rev = numbers.rbegin();

  for (numbers_it_rev; numbers_it_rev != numbers.rend(); numbers_it_rev++)
    std::cout << *numbers_it_rev << std::endl;

  std::cout << ORANGE << "----" << CLEAR << std::endl;

  std::vector<int>::iterator doubler = numbers.begin();

  for (doubler; doubler != numbers.end(); doubler++)
  {
    *doubler *= 2;
    std::cout << *doubler << std::endl;
  }

  std::cout << ORANGE << "----" << CLEAR << std::endl;

  std::vector<int>::const_iterator read_only = numbers.cbegin();

  for (read_only; read_only != numbers.cend(); read_only++)
  {
    // *read_only -= 100; // expression must be a modifiable lvalue
    std::cout << *read_only << std::endl;
  }

  std::cout << ORANGE << "----" << CLEAR << std::endl;

  const std::vector<int>::const_iterator first = numbers.cbegin();

  // no operator "++" matches these operands
  // for (first; first != numbers.cend(); first++)
  // std::cout << *first << std::endl;

  std::cout << BLUE << "Zadanie 2" << CLEAR;
  hr();

  std::vector<int> nums;

  std::transform(numbers.begin(), numbers.begin() + 3, std::back_inserter(nums), [](int number)
                 { return number; });

  std::vector<int>::iterator nums_it = nums.begin();

  std::back_insert_iterator<std::vector<int>> nums_ones(nums);

  for (int i = 0; i < 3; i++)
    *(nums_ones++) = 1;

  std::reverse(nums.begin(), nums.end());
  std::back_insert_iterator<std::vector<int>> nums_zeros(nums);

  for (int i = 0; i < 3; i++)
    *(nums_ones++) = 0;

  std::reverse(nums.begin(), nums.end());
  
  for (auto el : nums)
    std::cout << el << std::endl;

  std::cout << BLUE << "Zadanie 3" << CLEAR;
  hr();

  std::ifstream file("dane.txt");
  std::istream_iterator<std::string> start(file), end;

  for (start; start != end; start++)
  {
    std::cout << *start << std::endl;
  }

  file.close();

  std::ifstream file2("dane.txt");
  std::istream_iterator<std::string> start2(file2), end2;
  std::vector<std::string> empty;

  std::copy(start2, end2, std::back_inserter(empty));

  std::cout << ORANGE << "----" << CLEAR << std::endl;

  for (auto el : empty)
  {
    std::cout << el << std::endl;
  }

  file2.close();

  return 0;
}