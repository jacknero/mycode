/*
 * =====================================================================================
 *
 *       Filename:  meta.cpp
 *
 *    Description:  CURSOR>this is the metaprograming test
 *
 *        Version:  1.0
 *        Created:  2009年07月23日 22時13分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  matsui
 *
 * =====================================================================================
 */

#include <iostream>

template <long long N>
struct factorial{
  static const long long value = N * factorial<N-1>::value;
};

template <>
struct factorial<0>{
  static const long long value = 1;
};

int main() {
  int result = factorial<15L>::value;
  std::cout << result << std::endl;
}

