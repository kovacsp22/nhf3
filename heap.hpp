/**
 *
 * @file heap.hpp
 * @author tekda
 * Max-kupac adatszerkezet iterátorokkal
 * Prioritásos sor csomagolóosztály, kupaccal
 *
 */

#ifndef HEAP_HPP
#define HEAP_HPP

#include "heap_exceptions.hpp"
#include <iostream>
#include <vector>

template <class I> bool validate_heap(I first, I last);

template <class T> class heap {
  /**
   *   Konténer vektor
   */
  std::vector<T> values;

  /**
   * Kupacban elemet feljebbmozgató eljárás
   *
   * @param index az elem indexe, amit feljebb kell mozgatni
   */
  void lift_up(std::size_t index) {
    if (index >= values.size()) {
      throw invalid_index();
    }

    std::size_t parent = get_parent(index);

    while (index != 0 && values[parent] < values[index]) {
      std::swap(values[parent], values[index]);
      index = parent;
      parent = get_parent(index);
    }
  }

  /**
   * Kupacban elemet lejjebbmozgató eljárás
   *
   * @param index az elem indexe, amit lejjebb kell mozgatni
   */
  void lift_down(std::size_t index) {
    if (index >= values.size()) {
      throw invalid_index();
    }

    size_t left_child = get_left_child(index),
           right_child = get_right_child(index);

    while (
        (right_child < values.size() && values[index] < values[right_child]) ||
        (left_child < values.size() && values[index] < values[left_child])) {
      if (right_child < values.size() &&
          values[left_child] < values[right_child]) {
        std::swap(values[right_child], values[index]);
        index = right_child;
      } else {
        std::swap(values[left_child], values[index]);
        index = left_child;
      }
      left_child = get_left_child(index);
      right_child = get_right_child(index);
    }
  }

  [[nodiscard]] std::size_t get_parent(std::size_t index) const {
    return (index - 1) / 2;
  }

  [[nodiscard]] std::size_t get_left_child(std::size_t index) const {
    return 2 * index + 1;
  }

  [[nodiscard]] std::size_t get_right_child(std::size_t index) const {
    return 2 * index + 2;
  }

public:
  heap() = default;
  explicit heap(const std::vector<T> &v_) : values(v_) {
    for (int i = static_cast<int>(values.size() / 2) - 1; i >= 0; --i)
      lift_down(i);
  }

  /**
   *
   * Üres-e a kupac
   *
   * @return igaz, hogyha a kupac üres
   *
   */
  [[nodiscard]] bool empty() const { return values.empty(); }

  /**
   *
   * A kupac mérete
   *
   * @return a kupac mérete.
   *
   */
  [[nodiscard]] size_t size() const { return values.size(); }

  /**
   *
   * Kupacba elemet betevő eljárás
   *
   * @param item a beszúrandó elem
   *
   */
  void push(T item) {
    values.push_back(item);
    lift_up(values.size() - 1);
  }

  /**
   *
   * Kupac maximális elemét lekérdező művelet
   *
   * @return kupac tetején lévő elem
   *
   */
  const T &top() const {
    if (empty()) {
      throw empty_heap();
    }
    return values[0];
  }

  /**
   *
   * Kupacból kivesszük a legfelső elemet
   *
   */
  void pop() {
    if (!empty()) {
      std::swap(values[0], values[values.size() - 1]);
      values.pop_back();

      if (!empty()) {
        lift_down(0);
      }
    } else {
      throw empty_heap();
    }
  }

  /**
   *
   * Ellenőrző függvény
   *
   */
  void validate(bool print = false) const {
    if (print) {
      std::cout << "Heap: [ ";
      for (unsigned int i = 0; i < values.size(); ++i)
        std::cout << values[i] << " ";
      std::cout << "]" << std::endl;
    }
    std::cout << "A vektor"
              << (validate_heap(values.begin(), values.end()) ? " " : " NEM ")
              << "teljesiti a kupac-tulajdonsagot!" << std::endl;
  }

  [[nodiscard]] bool check() const {
    return validate_heap(values.begin(), values.end());
  }
};

template <class I> bool validate_heap(I first, I last) {
  if (last > first) {
    for (int i = 0; i < (last - first) / 2; ++i) {
      if ((first + 2 * i + 1) < last && *(first + i) < *(first + 2 * i + 1))
        return false;
      if ((first + 2 * i + 2) < last && *(first + i) < *(first + 2 * i + 2))
        return false;
    }
    return true;
  } else {
    throw invalid_iterator();
  }
}

#endif // HEAP_HPP
