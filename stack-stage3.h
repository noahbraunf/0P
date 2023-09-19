/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Noah Braunfeld
 */

#ifndef _STACK_T_H
#define _STACK_T_H

// To start stage 2, you probably want to copy all of your code from
// stack-stage1.h and stack-stage1.cpp in place of this comment.
#include <cstddef>  // for size_t
#include <cstring>

template <typename T>
class stack {
 public:
  T& top();  // non-inline, implemented in stack-stage1.cpp

  // inline definitions, doing nothing at the moment
  void push(const T& elem);
  void pop();
  std::size_t size();
  bool is_empty();

  stack(stack<T>& other) {
    _data = new T[other._capacity];
    for(std::size_t i = 0; i < other._capacity; ++i) {
      _data[i] = other._data[i];
    }
    _capacity = other._capacity;
    _num_elems = other.size();
  };

  stack<T>& operator=(stack<T>& other) {
    if (this == &other) return *this;
    _capacity = other._capacity;
    _num_elems = other.size();
    delete[] _data;
    _data = new T[other._capacity];
    for(std::size_t i = 0; i < other._capacity; ++i) {
      _data[i] = other._data[i];
    }
    return *this;
  };

  stack() {
    _num_elems = 0;
    _capacity = 1;
    _data = new T[_capacity];
  };

  ~stack() { delete[] _data; };

 private:
  void _reallocate();

  std::size_t _capacity;
  std::size_t _num_elems;
  T* _data;
};

template <typename T>
T& stack<T>::top() {
  return _data[_capacity - _num_elems];
}

template <typename T>
void stack<T>::push(const T& elem) {
  if (_num_elems == _capacity) _reallocate();
  _data[_capacity - _num_elems++ - 1] = elem;
}

template <typename T>
void stack<T>::pop() {
  _data[_capacity - _num_elems--] = T();
}

template <typename T>
std::size_t stack<T>::size() {
  return _num_elems;
}

template <typename T>
bool stack<T>::is_empty() {
  return _num_elems == 0;
}

template <typename T>
void stack<T>::_reallocate() {
  T* new_data = new T[2 * _capacity];

  for (std::size_t i = 0; i < _num_elems; ++i) {
    new_data[2 * _capacity - i - 1] = _data[_capacity - i - 1];
  }

  _capacity *= 2;
  delete[] _data;
  _data = new_data;
}

#endif