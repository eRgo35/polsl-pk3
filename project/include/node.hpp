#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <memory>

/// @brief Node template class
/// @tparam T 
template <typename T>
class Node
{
public:
    std::unique_ptr<Node> next;
    T data;

    /// @brief constructors that creates a new instance of the class with provided data
    /// @param _data 
    Node(T _data)
    {
        next = nullptr;
        data = _data;
    }
};

#endif