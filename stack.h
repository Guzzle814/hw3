#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T> //I make it public because usually it is eaiser to implement
{
public:
    Stack() = default;
    ~Stack() = default;
    bool empty() const
    {
      return std::vector<T>::empty();
    }

    size_t size() const
    {
      return std::vector<T>::size();
    }

    void push(const T& item)
    {
      std::vector<T>::push_back(item);
    }

    void pop()  // throws std::underflow_error if empty
    {
      if(std::vector<T>::empty())throw std::underflow_error("Empty Stack");
      std::vector<T>::pop_back();
    }

    const T& top() const // throws std::underflow_error if empty
    {
      if(std::vector<T>::empty())throw std::underflow_error("Empty Stack");
      return std::vector<T>::back();
    }
    // Add other members only if necessary
};


#endif