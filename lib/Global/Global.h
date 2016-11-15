#pragma once

#include "mbed.h"

// Global Functions

template <typename T, int N>
int size(T (&a) [N]) {
  return N - 1;
}

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
