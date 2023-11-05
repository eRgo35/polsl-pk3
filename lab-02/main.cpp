#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
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

template <typename T>
void show(T value)
{
  std::cout << value << std::endl;
}

class negative
{
public:
  int operator()(int x)
  {
    return -x;
  }
};

class Incrementator
{
private:
  int t = 5;
public:
  Incrementator(int t)
  {
    this->t = t;
  }

  int operator()(int x, int y)
  {
    return x + y + t;
  }
};

int main()
{
  hr();
  std::cout << RED << "Zad 1." << CLEAR << std::endl;

  std::list<int> list_int = {1, 2, 3, 4, 5, 6, 7, 7, 7, 9};
  std::list<double> list_double = {1.5, 2.0, 3.0, 5.0, 4.5, 3.5, 2.5};

  int count_int = std::count(list_int.begin(), list_int.end(), 7);

  std::cout << "Ilość siódemek: " << count_int << std::endl;

  std::for_each(list_int.begin(), list_int.end(), show<int>);

  std::cout << "Lista double" << std::endl;

  std::for_each(list_double.begin(), list_double.end(), show<double>);

  hr();
  std::cout << RED << "Zad 2." << CLEAR << std::endl;

  std::vector<int> array_int = {10, 2, 4, 5, 7, 8, 9, 1, 0, 3};

  std::cout << "Array przed zmianami: " << std::endl;
  std::for_each(array_int.begin(), array_int.end(), show<int>);

  std::transform(array_int.begin(), array_int.end(), array_int.begin(), negative());

  std::cout << "Array po obiekcie funkcyjnym: " << std::endl;
  std::for_each(array_int.begin(), array_int.end(), show<int>);

  std::transform(array_int.begin(), array_int.end(), array_int.begin(), [](int x)
                 { return -x; });

  std::cout << "Array po lambda: (dwa razy negacja, więc jest znów dodatnie) " << std::endl;
  std::for_each(array_int.begin(), array_int.end(), show<int>);

  hr();
  std::cout << RED << "Zad 3." << CLEAR << std::endl;

  std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
  std::vector<int> v2 = {7, 8, 9, 10, 11, 12};

  std::vector<int> v3;

  std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(v3), [](int x, int y)
                 { return x * y; });

  std::cout << "Iloczyn kolejnych elementów: " << std::endl;
  std::for_each(v3.begin(), v3.end(), show<int>);

  std::vector<int> v4;

  Incrementator incrementator(10);

  std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(v4), incrementator);

  std::cout << "Suma powiększona o t: " << std::endl;
  std::for_each(v4.begin(), v4.end(), show<int>);

  return 0;
}