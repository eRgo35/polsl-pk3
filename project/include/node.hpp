#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <memory>

template <typename T>
class Node
{
private:
    T data;
    std::shared_ptr<Node> head;
};

#endif