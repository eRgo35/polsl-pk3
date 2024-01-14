#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <memory>

template <typename T>
class Node
{
public:
    std::unique_ptr<Node> next;
    T data;

    Node(T _data)
    {
        next = nullptr;
        data = _data;
    }
};

#endif