/*
 * stack-stage1.h
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

#ifndef _STACK_H
#define _STACK_H

#include <cstddef>  // for size_t
#include <string>   // for stage 1

using namespace std;

// const size_t _MAX_SIZE = 4;

class stack {
 public:
  string top();  // non-inline, implemented in stack-stage1.cpp

  // inline definitions, doing nothing at the moment
  void push(const string& elem);
  void pop();
  size_t size();
  bool is_empty();

  stack() {
    _num_elems = 0;
    _capacity = 1;
    _data = new string[_capacity];
  };

  ~stack() { delete[] _data; };

 private:
  void _reallocate();

  size_t _capacity;
  size_t _num_elems;
  string* _data;
};

#endif
