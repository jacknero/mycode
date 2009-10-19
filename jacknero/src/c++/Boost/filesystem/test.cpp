/*
 * =====================================================================================
 *
 *
 *       Filename:  test.cpp
 *
 *    Description:  CURSOR>
 *
 *        Version:  1.0
 *        Created:  2009ǯ08��26�� 17��51ʬ42��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S���dwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

int main()
{
  path test("test");
  if(!exists(test)){
    create_directory(test);
  }
  return 0;
}
