/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  CURSOR>test Meta programing Array
 *
 *        Version:  1.0
 *        Created:  2009ǯ09��04�� 22��40ʬ20��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S���dwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;
static long long array[20];

template < long long  N>
struct factorial {
  static const long long value =  N * factorial<N - 1>::value;
};

template <>
struct factorial<0> {
  static const long long value = 1;
};

int main(void ){
  long long result;
    result = factorial<20>::value;
  cout << result << endl;
  return 0;

}
