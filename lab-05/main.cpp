#include <iostream>
#include <fstream>
#include <chrono>
#include <exception>
#include "colors.h"

std::string get_timestamp()
{
  auto time = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
  std::string formatted_time = std::format("{0:%F-%T}", time);

  return formatted_time;
}

class ErrorLog
{
public:
  static ErrorLog &getInstance()
  {
    static ErrorLog errorLog;
    return errorLog;
  }

  template <typename T>
  ErrorLog &operator<<(const T &message)
  {
    file << "[" << get_timestamp() << "] " << message << std::endl;
    return *this;
  }

private:
  std::fstream file;

  ErrorLog()
  {
    file.open("log.txt", std::ios::app | std::ios::ate);
  }

  ~ErrorLog()
  {
    file.close();

    // stworzyłem dodatkowo możliwość trzymania archiwum poprzednich plików log
    // aby być zgodnym z treścią zadania, pozostawiam ten blok zakomentowany

    // std::stringstream filename;
    // filename << "log-" << get_timestamp() << ".txt";

    // try {
    //   std::rename("log.txt", filename.str().c_str());
    // }
    // catch(const std::exception&)
    // {
    //   std::rename("log.txt", "log.old.txt");
    // }
  }

  ErrorLog(const ErrorLog &) = delete;
  ErrorLog &operator=(const ErrorLog &) = delete;
  ErrorLog(ErrorLog &&) = delete;
  ErrorLog &operator=(ErrorLog &&) = delete;
};

template <typename S>
class DynamicTable
{
private:
  S *array;
  long long int size;

public:
  DynamicTable(long long int size)
  {
    ErrorLog::getInstance() << "Dynamic Table constructed!";

    this->size = size;
    array = new (std::nothrow) S[size]();
    
    if (array == nullptr)
      throw std::bad_alloc();
  }

  ~DynamicTable()
  {
    ErrorLog::getInstance() << "Dynamic Table destructed!";
    delete[] array;
  }

  void insert(S value, long long int position)
  {
    if (position > size || position < 0)
      throw std::length_error("Provided position out of bounds!");
    
    array[position] = value;
  }
  
  S get(long long int position)
  {
    if (position > size || position < 0)
      throw std::length_error("Provided position out of bounds!");

    return array[position];
  }
};

int main()
{
  ErrorLog::getInstance() << "Initializing...";

  ErrorLog::getInstance() << "Testing strings";

  for (int i = 0; i < 10; i++)
    ErrorLog::getInstance() << i;

  ErrorLog::getInstance() << 3.14159;

  std::cout << "Refer to log.txt for details." << std::endl;

  long long int i32limit = 2147483647;

  try
  {
    DynamicTable<double> oob(i32limit + i32limit);
  }
  catch (std::exception& err)
  {
    ErrorLog::getInstance() << err.what();
  }

  DynamicTable<int> numbers(i32limit);

  try
  {
    numbers.insert(69, i32limit + 1);
  }
  catch(std::exception& err)
  {
    ErrorLog::getInstance() << err.what();
  }

  numbers.insert(69, 69);
  ErrorLog::getInstance() << numbers.get(69);

  ErrorLog::getInstance() << "Terminating...";
  return 0;
}