#include <iostream>
#include "stack.h"
#include "colors.h"

template<typename T>

T sum(T a, T b)
{
  return a + b;
}

template<>
std::string sum<std::string>(std::string a, std::string b)
{
  std::string concat;
  concat = a + b;
  return concat;
}

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
  hr();
  std::cout << RED << "1)" << CLEAR << std::endl;

  int a1 = 124;
  int b1 = 52;

  std::cout << a1 << " + " << b1 << " = " << sum(a1, b1) << std::endl;

  double a2 = 43.45;
  double b2 = 994.31;

  std::cout << a2 << " + " << b2 << " = " << sum(a2, b2) << std::endl;

  hr();
  std::cout << RED << "2)" << CLEAR << std::endl;

  std::string a3 = "Foo";
  std::string b3 = "Bar";

  std::cout << sum(a3, b3) << std::endl;

  hr();
  std::cout << RED << "3)" << CLEAR << std::endl;

  int s1 = 13;
  int s2 = 45;
  int s3 = 85;
  int s4 = 9;
  int s5 = 33;

  Stack<int> stack(s1, 5);
  std::cout << stack.is_empty() << std::endl;
  stack.push(s1);
  std::cout << stack.is_empty() << std::endl;
  std::cout << stack.is_full() << std::endl;
  stack.push(s2);
  stack.push(s3);
  stack.push(s4);
  stack.push(s5);
  std::cout << stack.is_full() << std::endl;
  
  std::cout << stack.print() << std::endl;
  
  stack.push(s5);
  stack.push(s5);

  std::cout << stack.print() << std::endl;

  stack.pop();
  stack.pop();
  stack.pop();

  std::cout << stack.print() << std::endl;

  hr();

  double d1 = 3.14;
  double d2 = 2.71;
  double d3 = 1.41;
  double d4 = 1.73;
  double d5 = 2.11;

  Stack<double> doubleStack(d1, 3);

  doubleStack.push(d1);
  std::cout << doubleStack.print() << std::endl;

  doubleStack.pop();
  std::cout << doubleStack.print() << std::endl;

  std::cout << doubleStack.is_empty() << std::endl;

  hr();

  std::string t1 = "Hello World";
  std::string t2 = "Cat";
  std::string t3 = "Linux";
  std::string t4 = "Just_A_Random_String";
  std::string t5 = "Ave Caesar";

  Stack<std::string> stringStack(t1, 3);

  stringStack.push(t1);
  std::cout << stringStack.print() << std::endl;

  stringStack.pop();
  std::cout << stringStack.print() << std::endl;

  std::cout << stringStack.is_empty() << std::endl;
  std::cout << stringStack.is_full() << std::endl;

  stringStack.push(t2);
  stringStack.push(t4);
  stringStack.push(t5);
  stringStack.push(t3);

  std::cout << stringStack.print() << std::endl;

  return 0;
}