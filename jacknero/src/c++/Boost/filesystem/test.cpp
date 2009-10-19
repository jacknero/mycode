/*
 * =====================================================================================
 *
 *
 *       Filename:  test.cpp
 *
 *    Description:  CURSOR>
 *
 *        Version:  1.0
 *        Created:  2009年08月26日 17時51分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
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
