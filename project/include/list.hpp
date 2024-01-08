#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "node.hpp"

#include <iostream>

template <typename T>
class List {
    public:
    List();
    List(const List& other);
    List(const List&& other);
    ~List();

    List &operator=(List& other);
    List &operator=(List&& other);

    friend std::ostream &operator<<(std::ostream &out, const List &other)
    {
        out << other.data;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, const List &other)
    {
        in >> other.data;
        return in;
    }
    
    void push_front(T data);
    void pop_back();

    void insert(T data, int position);
    void erase(int position);

    void find(T query);
};

template <typename T>
List<T>::List()
{
    
    std::cout << "List initialized" << std::endl;
}

template <typename T>
List<T>::List(const List& other)
{
    std::cout << "List copy" << std::endl;
}

template <typename T>
List<T>::~List()
{
    std::cout << "List destroyed" << std::endl;
}

#endif