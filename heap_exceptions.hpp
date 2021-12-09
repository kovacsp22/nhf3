/**
 *
 * @file heap_exceptions.hpp
 * @author tekda
 * Kupac manipuláló eljárások által használt kivételek leírása
 *
 */

#ifndef HEAP_EXCEPTIONS_HPP
#define HEAP_EXCEPTIONS_HPP

#include <exception>

class heap_exception : public std::exception {};

class invalid_iterator : public heap_exception {
public:
  [[nodiscard]] const char *what() const noexcept override {
    return "Az iterator invalid.";
  }
};
class invalid_index : public heap_exception {
public:
  [[nodiscard]] const char *what() const noexcept override {
    return "Az index invalid.";
  }
};
class empty_heap : public heap_exception {
public:
  [[nodiscard]] const char *what() const noexcept override {
    return "A kupac ures.";
  }
};

#endif // HEAP_EXCEPTIONS_HPP
