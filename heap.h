#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()):m_(m),comp(c){};


  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item)//did not see the bottom function outside the class, so i implement some insde.
  {
    theHeap.push_back(item);
    int i = theHeap.size()-1;
    while(i>0)//can set to while(true) i guess? since after push back it can not be empty
    {
      int parent = (i - 1) / m_;
      if(comp(theHeap[i], theHeap[parent]))
      {
        T temp = theHeap[i];
        theHeap[i] = theHeap[parent];
        theHeap[parent] = temp;
        i = parent;
      }
      else
      {
        break;
      }
    }
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const
  {
    return theHeap.empty();// i name it theHeap because the vector basically represents the heap
  }

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const
  {
    return theHeap.size();
  }

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  PComparator comp;
  std::vector<T> theHeap;
};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("EmptyHeap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return theHeap[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("EmptyHeap");
  }
    T temp = theHeap[0];
    theHeap[0] = theHeap[theHeap.size()-1];
    theHeap[theHeap.size()-1] = temp;

    theHeap.resize(theHeap.size() - 1);


    int cur = 0;
    int prior;
    while(true)
    {
      prior = cur;
      bool changed = false;
      for(int j = 0; j < m_; j++)
      {
        int child = m_*cur + j + 1;
        if(child >= static_cast<int>(theHeap.size())) break;
        if(comp(theHeap[child],theHeap[prior]))
        {
          prior = child;
          changed = true;
        }
      }
      if(!changed) break;

      T temp = theHeap[cur];
      theHeap[cur] = theHeap[prior];
      theHeap[prior] = temp;

      cur = prior;
    }
}



#endif

