/*
 * =====================================================================================
 *
 *       Filename:  test.cxx
 *
 *    Description:  CURSOR>BOOST_TETS
 *
 *        Version:  1.0
 *        Created:  2009年08月26日 16時41分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */


#include <iostream>
#include <boost/format.hpp>
using namespace std;

int main()
{
  // %1%真真真真真�%2%真真真真真真真
  cout <<
    boost::format("%1% %2%") % "hello" % 100
    << endl;

  // printf真真真OK�
  // %05d:0真�5真真 %x:16真� %f:真真真 %%:%真真
  cout <<
    boost::format("%05d %x %f %%") % 200 % 255 % 3.33
    << endl;

  // 真真%2%�%1%真真真真�
  cout <<
    boost::format("%2% %1%") % "hello" % 100
    << endl;

  // %N$...真真真真真真真真�
  // %04x:0真�4真16真� %s:真�
  cout <<
    boost::format("%2$04x %1$s") % "hello" % 254
    << endl;
  
  return 0;
}
