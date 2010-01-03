/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  CURSOR>This is the c++00x auto test
 *
 *        Version:  1.0
 *        Created:  2009年12月21日 00時11分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jacknero (), jack_nero2000@yahoo.co.jp
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

void print(const std::vector<int>& v) {
  std::cout << "[print]" << std::endl;

  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }

  std::cout << std::endl;
}

void rprint(const std::vector<int>& v) {
  std::cout << "[rprint]" << std::endl;

  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << std::endl;
  }

  std::cout << std::endl;
}

int main() {
  std::vector<int> v = {1, 5, 10};

  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;

  print(v);
  rprint(v);

  return 0;
}
