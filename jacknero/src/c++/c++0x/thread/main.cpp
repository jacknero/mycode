/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  CURSOR>This is the c++08 tr1
 *
 *        Version:  1.0
 *        Created:  2009ǯ12��21�� 00��15ʬ02��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jacknero (), jack_nero2000@yahoo.co.jp
 *        Company:  
 *
 * =====================================================================================
 */

#include <threads>

struct do_work {
  void operator()() {}
};

int main()
{
  do_work dw;
  std::thread t(dw);

  t.join();
}
