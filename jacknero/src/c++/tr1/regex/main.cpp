/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  CURSOR>this is the regex program. It's use Tr1 library
 *
 *        Version:  1.0
 *        Created:  2009年12月21日 11時50分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jacknero (), jack_nero2000@yahoo.co.jp
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<regex>

int main(int argc, char *argv[])
{
  std::regex rx("abc");
  std::cout
    << "search(\"abcabc\", \"abc\") == "
    << std::boolalpha << regex_search(std::string("abcabc"), rx)
    << std::endl;
  return 0;
}
