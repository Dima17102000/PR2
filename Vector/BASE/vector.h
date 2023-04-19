#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>


class Vector
{
 public:
 class ConstIterator;
 class Iterator;
 using value_type = double;
 using size_type = std::size_t;
 using difference_type = std::ptrdiff_t;
 using reference = value_type&;
 using const_reference = const value_type&;
 using pointer = value_type*;
 using const_pointer = const value_type*;
 using iterator = Vector:: Iterator;
 using const_iterator = Vector:: ConstIterator;
 private: 
 //Instance variables
  size_type sz;
  size_type max_sz;
  static constexpr size_type min_capacity = 5;
  pointer values;
 public:
 // Member Functions
  Vector(): sz{0}, max_sz{min_capacity},values{new value_type[max_sz]}
  {
  }
  
  Vector(size_type n): sz{n}, max_sz{n > min_capacity? n : min_capacity}, values{new value_type[max_sz]}
  {
  
  }
  
  Vector(std::initializer_list<value_type> lst): sz{lst.size()}, max_sz{sz > min_capacity? sz : min_capacity}, values{new value_type[max_sz]}
  {
   std:: copy(lst.begin(), lst.end(), values);
  } 
  Vector(const Vector& other): sz{other.sz},max_sz{other.max_sz}, values{new value_type[max_sz]}
  {
   std::copy(other.values, other.values + other.sz, values);
  }
  
  ~Vector()
  {
   delete[]values;
  }
  
  Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] values;
            values = new double[other.max_sz];
            sz = other.sz;
            max_sz = other.max_sz;
            std::copy(other.values, other.values + sz, values);
        }
        return *this;
    }
  size_type size()const
  {
   return sz;
  }
  
  bool empty()const
  {
   return sz == 0;
  }
  
  void clear()
  {
   sz = 0;
  }
  void reserve(size_type n)
  {
    if(n > max_sz)
    {
     pointer new_values = new value_type[n];
     std::copy(values, values + sz, new_values);
     delete[]values;
     values = new_values;
     max_sz = n;
    }
  }
  
  void shrink_to_fit()
  {
   if(sz < max_sz)
    {
    max_sz = sz;
    pointer new_values = new value_type[sz];
    std::copy(values,values + sz, new_values);
    delete[]values;
    values = new_values;
    }
  }
  void push_back(value_type x)
  {
   if(sz == max_sz)
   {
    reserve(max_sz * 2);
   }
   values[sz++] = x;
  }
  void pop_back()
  {
   if(empty())
   {
    throw std::runtime_error("index out of bounds");
   }
   sz--;
  }
  value_type& operator[](size_type index)
  {
   if(index >= sz)
   {
    throw std::runtime_error("index out of bounds");
   }
   return values[index];
  }
  const value_type& operator[](size_type index)const
  {
   if(index >= sz)
   {
    throw std::runtime_error("index out of bounds");
   }
   return values[index];
  }
  
  size_type capacity()const
  {
   return max_sz;
  }
  
  friend std::ostream& operator<<(std:: ostream& os, const Vector& vec)
  {
   os << "[";
   for(size_type i{0}; i < vec.sz; i++)
   {
    os << vec.values[i];
    if(i != vec.sz - 1)
    {
     os << ", ";
    }
   }
   os << "]";
   return os;
  }
};
#endif
