/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Noah Braunfeld
 */

#include "stack-stage1.h"

#include <iostream>

string stack::top() {
  if (is_empty()) return string();
  return _data[_capacity - _num_elems];
}

void stack::pop() {
  if (is_empty()) return;

  _data[_capacity - _num_elems--] = string();
}

void stack::push(const string& elem) {
  if (_num_elems == _capacity) _reallocate();
  _data[_capacity - _num_elems++ - 1] = elem;
}

size_t stack::size() { return _num_elems; }

bool stack::is_empty() { return _num_elems == 0; }

void stack::_reallocate() {
  string* new_data = new string[2 * _capacity];
  for (size_t i = 0; i < _num_elems; ++i) {
    new_data[2 * _capacity - i - 1] =
        _data[_capacity - i - 1];
  }

//   for (size_t i = 0; i < 2 * _capacity; ++i) {
//     cout << new_data[i] << ", ";
//   }
//   cout << endl;
//   for (size_t i = 0; i < _capacity; ++i) {
//     cout << _data[i] << ", ";
//   }
//   cout << endl;

  _capacity *= 2;
  delete[] _data;
  _data = new_data;
}