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
  
 Vector& operator=(const Vector& other) 
 {
    if (this != &other) 
    {
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

iterator begin()
{
  if(sz == 0)
    return this->end();
    
  return iterator(values);
}

const_iterator begin() const
{
    return const_iterator(values);
}

iterator end()
{
    return iterator(values + sz);
}

const_iterator end() const
{
    return const_iterator(values + sz);
}
 
class Iterator
{
  public:
  using value_type = Vector:: value_type;
  using reference = Vector:: reference;
  using pointer = Vector:: pointer;
  using difference_type = Vector:: difference_type;
  using iterator_category = std:: forward_iterator_tag;
  private:
  //Instance variables
  pointer ptr;
  public: 
  // Member functions
    
  
 Iterator(pointer ptr_in=nullptr): ptr{ptr_in}
 {
  
 }
  
 reference operator*()const // Iteration
 {
   return *ptr;
 }
  
 pointer operator->()const
 {
   return ptr;
 }
  
 bool operator==(const const_iterator& rop)const
 {
   return rop == *this;
 }
  
 bool operator!=(const const_iterator& rop)const
 {
   return !(*this == rop);
 }
  
 Iterator& operator++()
 {
 if(ptr == nullptr)
    return *this;
  ++ptr;
  return *this;
 }
  
 Iterator operator++(int)
 {
  Iterator temp = *this;
  ++(*this);
  return temp;
 }
  
 operator ConstIterator() const
 {
   return ConstIterator(ptr);
 }
};
 
class ConstIterator
{
  public:
  using value_type = Vector:: value_type;
  using reference = Vector:: reference;
  using pointer = Vector:: pointer;
  using difference_type = Vector:: difference_type;
  using iterator_category = std:: forward_iterator_tag;
  private:
  //Instance variables
  pointer ptr;
  public: 
  // Member functions
  
 ConstIterator(): ptr{nullptr}
 {
  
 }
  
 ConstIterator(pointer ptr_in): ptr{ptr_in}
 {
  
 }
  
 reference operator*()const
 {
   return *ptr;
 }
  
 pointer operator->()const
 {
   return ptr;
 }
  
 bool operator==(const const_iterator& other)const
 {
   return ptr == other.ptr;
 }
  
 bool operator!=(const const_iterator& other)const
 {
   return ptr != other.ptr;
 }
  
 const_iterator& operator++()
 {
   ++ptr;
   return *this;
 }
  
 const_iterator operator++(int)
 {
   ConstIterator temp = *this;
   ++(*this);
   return temp;
 }
   
 friend difference_type  operator-(const Vector:: ConstIterator& lop,const Vector:: ConstIterator& rop) 
{
  return  lop.ptr-rop.ptr;
}
};

iterator  insert(const_iterator pos,const_reference val) 
{
auto  diff = pos-begin();
if(diff<0 || static_cast<size_type>(diff)>sz)
throw  std::runtime_error ( "Iterator out of bounds");
size_type  current{static_cast<size_type>(diff)};
if(sz>=max_sz)
reserve(max_sz * 2 ); // Attention special  case,if no minimum  size  is  defined

for(auto i{sz}; i--> current;)
values[i+1] = values[i];
values[current] = val;
++sz;
return iterator{values + current};
}

iterator erase(const_iterator pos) 
{
auto diff = pos-begin();
if(diff<0 || static_cast<size_type>(diff)>= sz)
throw std::runtime_error("Iterator out of bounds");
size_type  current{static_cast<size_type>(diff)};
for(auto  i{current};i<sz-1;++i)
values[i]=values[i+1];
--sz;
return  iterator{values+current};
}


};
#endif
