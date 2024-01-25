#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "node.hpp"

#include <iostream>
#include <memory>

/// @brief main list template implementation
/// @tparam T 
template <typename T>
class List
{
private:
    std::unique_ptr<Node<T>> head;

public:
    /// @brief default constructor creating an empty head
    List()
    {
        head = nullptr;
    }

    /// @brief copy constructor
    List(const List &list)
    {
        Node<T> *point = list.head.get();

        std::unique_ptr<Node<T>> new_head = std::move(std::make_unique<Node<T>>(point->data));
        Node<T> *point_copy = new_head.get();
        point = point->next.get();

        while (point)
        {
            point_copy->next = std::move(std::make_unique<Node<T>>(point->data));
            point_copy = point_copy->next.get();
            point = point->next.get();
        }

        head = std::move(new_head);
    }

    /// @brief move constructor
    List(List &&list)
    {
        head = std::move(list.head);
    }

    /// @brief destructor just calls a clear function
    ~List()
    {
        clear();
    }

    /// @brief copy equals operator
    T operator=(List &list)
    {
        Node<T> *point = list.head.get();

        std::unique_ptr<Node<T>> new_head = std::move(std::make_unique<Node<T>>(point->data));
        Node<T> *point_copy = new_head.get();
        point = point->next.get();

        while (point)
        {
            point_copy->next = std::move(std::make_unique<Node<T>>(point->data));
            point_copy = point_copy->next.get();
            point = point->next.get();
        }

        head = std::move(new_head);

        T data = list.pop_back();
        return data;
    }

    /// @brief move equals operator
    T operator=(List &&list)
    {   
        head = std::move(list.head);
        T data = list.pop_back();
        return data;
    }

    /// @brief stream operators defined outside of the class
    template <typename U>
    friend std::istream &operator>>(std::istream &is, const List<U> &list);

    /// @brief stream operators defined outside of the class
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const List<U> &list);

    /// @brief returns a first element of the list
    T front()
    {
        return head->data;
    }

    /// @brief clears all nodes of the list
    void clear()
    {
        while (head)
        {
            head = std::move(head->next);
        }
    }

    /// @brief adds a new element to the beginning of the list
    void push_front(T data)
    {
        std::unique_ptr<Node<T>> new_head = std::make_unique<Node<T>>(data);

        if (head)
            new_head->next = std::move(head);

        head = std::move(new_head);
    }

    /// @brief removes an element from the beginning of the list
    T pop_front()
    {
        if (head == nullptr)
            throw std::out_of_range("List is empty");

        std::unique_ptr<Node<T>> behead = std::move(head);
        head = std::move(behead->next);

        return behead->data;
    }

    /// @brief returns an element at a given position
    T at(int position)
    {
        if (position < 0)
            throw std::length_error("Provided position out of bounds!");

        T result;
        Node<T> *point = head.get();

        for (int i = 0; i <= position; i++)
        {
            if (point == nullptr)
                throw std::length_error("Provided position out of bounds!");

            result = point->data;
            point = point->next.get();
        }

        return result;
    }

    /// @brief prints all elements by using std::cout
    void print_all()
    {
        Node<T> *point = head.get();

        std::cout << "[ ";

        while (point)
        {
            std::cout << point->data;
            point = point->next.get();

            if (point != nullptr)
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }

    /// @brief inserts a new element at a given position
    void insert(T data, int position)
    {
        if (position < 0)
            throw std::length_error("Provided position out of bounds!");

        Node<T> *point = head.get();
        std::unique_ptr<Node<T>> inserted_element = std::make_unique<Node<T>>(data);

        for (int i = 0; i <= position; i++)
        {
            if (point == nullptr)
                throw std::length_error("Provided position out of bounds!");

            if (i == position - 1)
            {
                inserted_element->next = std::move(point->next);
                point->next = std::move(inserted_element);
                return;
            }

            point = point->next.get();
        }
    }

    /// @brief removes an element at a given position
    void erase(int position)
    {
        if (position < 0)
            throw std::length_error("Provided position out of bounds!");

        Node<T> *point = head.get();

        for (int i = 0; i <= position; i++)
        {
            if (point == nullptr)
                throw std::length_error("Provided position out of bounds!");

            if (i == position - 1)
            {
                Node<T> *parent = point;
                point = point->next.get();
                parent->next = std::move(point->next);
                return;
            }

            point = point->next.get();
        }
    }

    /// @brief add a new element to the end of the list
    void push_back(T data)
    {
        Node<T> *point = head.get();
        std::unique_ptr<Node<T>> inserted_element = std::make_unique<Node<T>>(data);

        while (point)
        {
            if (point->next.get() == nullptr)
            {
                point->next = std::move(inserted_element);
                return;
            }

            point = point->next.get();
        }
    }

    /// @brief removes an element from the end of the list
    T pop_back()
    {
        Node<T> *parent_point = head.get();
        Node<T> *point = parent_point->next.get();


        while (point->next.get())
        {
            point = point->next.get();
            parent_point = parent_point->next.get();
        }

        T popped = point->data;
        parent_point->next = nullptr;
        return popped;
    }

    /// @brief returns a location of an element specified in a query; if value exists multiple times, first element will be returned
    int find(T query)
    {
        int position = 0;
        Node<T> *point = head.get();

        while (point != nullptr)
        {
            if (point->data == query)
            {
                return position;
            }
            position++;
            point = point->next.get();
        }

        return -1;
    }
};

template <typename T>
std::istream &operator>>(std::istream &is, List<T> &list)
{
    T value;
    is >> value;

    list.push_front(value);

    return is;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list)
{
    Node<T> *point = list.head.get();

    os << "[ ";

    while (point)
    {
        os << point->data;
        point = point->next.get();

        if (point != nullptr)
            os << ", ";
    }
    os << " ]";

    return os;
}

#endif