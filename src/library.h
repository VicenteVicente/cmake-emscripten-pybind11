#pragma once

#include <iostream>
#include <string>

class Library {
public:
  static void hello_world(const std::string &name) {
    std::cout << "Hello, " + name + "!" << std::endl;
  }

  static double add(double a, double b) { return a + b; }

  static void memory(uint32_t size) {
    std::cout << "Allocating " << size << " bytes" << std::endl;
    std::string s(size, 'a');
    std::cout << "Done" << std::endl;
  }
};