#pragma once
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

template <typename T, typename Predicate>
std::vector<T> Select(std::vector<T>* arr, Predicate predicate) {
  std::vector<T> result;
  for (const auto& element : *arr) {
    if (predicate(element)) {
      result.push_back(element);
    }
  }
  *arr = result;
  return result;
}