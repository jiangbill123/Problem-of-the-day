#pragma once

#include <cstddef>
#include <vector>
using namespace std;


class Stack {
public:
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
  vector<int> v;
};