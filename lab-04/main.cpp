#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <chrono>
#include <random>
#include "colors.h"

template<class T>
int max_finder(const T &t)
{
  int max = *t.begin();
  typename T::const_iterator it = t.begin();

  for (it; it != t.end(); it++)
    if (*it > max)
      max = *it;

  return max;
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

void push_back_filler(std::vector<int> &v, int *losowe_liczby, int n)
{
  for (int i = 0; i < n; i++)
    v.push_back(losowe_liczby[i]);
}

void range_filler(std::vector<int> &v, int *losowe_liczby, int n)
{
  v = std::vector<int>(losowe_liczby, losowe_liczby + n);
}

void insert_filler(std::multiset<int> &m, int *losowe_liczby, int n)
{
  for (int i = 0; i < n; i++)
    m.insert(losowe_liczby[i]);
}

void srange_filler(std::multiset<int> &m, int *losowe_liczby, int n)
{
  m = std::multiset<int>(losowe_liczby, losowe_liczby + n);
}

int main()
{
  std::cout << BLUE << "Zadanie 1" << CLEAR;
  hr();

  int dane_length = 10;
  int dane[dane_length] = {55, 21, 66, 11, 13, 11, 55, 24, 48, 66};

  std::vector<int> dane_vector;

  std::set<int> dane_set;
  std::multiset<int> dane_multiset;
  std::unordered_set<int> dane_unordered_set;
  std::unordered_multiset<int> dane_unordered_multiset;

  std::map<int, int> dane_map;
  std::multimap<int, int> dane_multimap;
  std::unordered_map<int, int> dane_unordered_map;
  std::unordered_multimap<int, int> dane_unordered_multimap;

  for (int i = 0; i < dane_length; i++)
  {
    dane_vector.push_back(dane[i]);

    dane_set.insert(dane[i]);
    dane_multiset.insert(dane[i]);
    dane_unordered_set.insert(dane[i]);
    dane_unordered_multiset.insert(dane[i]);

    dane_map.insert({dane[i], i});
    dane_multimap.insert({dane[i], i});
    dane_unordered_map.insert({dane[i], i});
    dane_unordered_multimap.insert({dane[i], i});
  }

  std::cout << RED << "array" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane)
    std::cout << i << " ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::vector" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_vector)
    std::cout << i << " ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::set" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_set)
    std::cout << i << " ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::multiset" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_multiset)
    std::cout << i << " ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::unordered_set" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_unordered_set)
    std::cout << i << " ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::unordered_multiset" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_unordered_multiset)
    std::cout << i << " ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::map" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_map)
    std::cout << "{" << i.first << ", " << i.second << "} ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::multimap" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_multimap)
    std::cout << "{" << i.first << ", " << i.second << "} ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::unordered_map" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_unordered_map)
    std::cout << "{" << i.first << ", " << i.second << "} ";
  std::cout << "]" << std::endl;

  std::cout << RED << "std::unordered_multimap" << CLEAR << std::endl;
  std::cout << "[ ";
  for (auto i : dane_unordered_multimap)
    std::cout << "{" << i.first << ", " << i.second << "} ";
  std::cout << "]" << std::endl;

  std::cout << BLUE << "Zadanie 2" << CLEAR;
  hr();

  std::map<std::string, std::string> countries = {{"China", "Beijing"}, {"United States", "Washington"}, {"Poland", "Warsaw"}};

  std::cout << "[ ";
  for (auto country : countries)
    std::cout << "{ " << country.first << ", " << country.second << "} ";
  std::cout << "]" << std::endl;

  countries.insert({"Germany", "Berlin"});
  countries.insert({"Vatican", "Vatican"});
  countries.insert({"Spain", "Madrit"});

  std::cout << "[ ";
  for (auto country : countries)
    std::cout << "{ " << country.first << ", " << country.second << "} ";
  std::cout << "]" << std::endl;

  countries["France"] = "Paris";
  countries["North Korea"] = "Pyongyang";
  countries["Japan"] = "Tokyo";

  std::cout << "[ ";
  for (auto country : countries)
    std::cout << "{ " << country.first << ", " << country.second << "} ";
  std::cout << "]" << std::endl;

  countries["Spain"] = "Madrid";

  std::cout << "[ ";
  for (auto country : countries)
    std::cout << "{ " << country.first << ", " << country.second << "} ";
  std::cout << "]" << std::endl;

  countries.erase("North Korea");

  std::cout << "[ ";
  for (auto country : countries)
    std::cout << "{ " << country.first << ", " << country.second << "} ";
  std::cout << "]" << std::endl;

  std::map<std::string, std::string> new_countries(countries.begin(), countries.find("Spain"));

  std::cout << "[ ";
  for (auto country : new_countries)
    std::cout << "{ " << country.first << ", " << country.second << "} ";
  std::cout << "]" << std::endl;

  std::cout << BLUE << "Zadanie 3" << CLEAR;
  hr();

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1, 1000);

  int n = 1000000;
  int *losowe_liczby = new int[n];

  for (int i = 0; i < n; i++)
    losowe_liczby[i] = distribution(generator);

  std::vector<int> vector;

  auto start = std::chrono::high_resolution_clock::now();
  push_back_filler(vector, losowe_liczby, 1000000);
  auto end = std::chrono::high_resolution_clock::now();

  auto push_back_timer = end - start;
  std::cout << "vector push_back time: " << push_back_timer.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  range_filler(vector, losowe_liczby, 1000000);
  end = std::chrono::high_resolution_clock::now();

  auto range_timer = end - start;
  std::cout << "vector range time: " << range_timer.count() << std::endl;

  std::multiset<int> multiset;

  start = std::chrono::high_resolution_clock::now();
  insert_filler(multiset, losowe_liczby, 1000000);
  end = std::chrono::high_resolution_clock::now();

  auto insert_timer = end - start;
  std::cout << "multiset insert time: " << insert_timer.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  srange_filler(multiset, losowe_liczby, 1000000);
  end = std::chrono::high_resolution_clock::now();

  auto srange_timer = end - start;
  std::cout << "multiset range time: " << srange_timer.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  std::cout << "vector max value: " << max_finder(vector) << std::endl;
  end = std::chrono::high_resolution_clock::now();

  auto vmax_timer = end - start;

  start = std::chrono::high_resolution_clock::now();
  std::cout << "multiset max value: " << max_finder(multiset) << std::endl;
  end = std::chrono::high_resolution_clock::now();
  
  auto mmax_timer = end - start;

  std::cout << "vector max finder time: " << vmax_timer.count() << std::endl;
  std::cout << "multiset max finder time: " << mmax_timer.count() << std::endl;

  delete[] losowe_liczby;

  return 0;
}
