#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>

template <class T>
class Stack
{
private:
  T *array;
  int size;
  int indicator = 0;

public:
  Stack(T type, int n);
  ~Stack();
  bool push(T element);
  bool pop();
  bool is_empty();
  bool is_full();
  std::string print();
};

template <class T>
Stack<T>::Stack(T type, int n)
{
  if (n <= 0)
    return;

  size = n;
  array = new T[n];
}

template <class T>
Stack<T>::~Stack()
{
  delete[] array;
}

template <class T>
bool Stack<T>::push(T element)
{
  if (indicator >= size)
    return false;

  array[indicator++] = element;
  return true;
}

template <class T>
bool Stack<T>::pop()
{
  if (indicator <= 0)
    return false;

  array[indicator--];
  return true;
}

template <class T>
bool Stack<T>::is_empty()
{
  return indicator == 0;
}

template <class T>
bool Stack<T>::is_full()
{
  return indicator == size;
}

template <class T>
std::string Stack<T>::print()
{
  std::string output = "[ ";
  std::stringstream elements;

  for (int i = 0; i < indicator; i++)
  {
    elements << array[i];
    output += elements.str();
    elements.str("");

    if (i < (indicator - 1))
    {
      output += ", ";
    }
  }

  output += " ]";

  return output;
}

#endif