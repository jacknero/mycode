/*
 * =====================================================================================
 *
 *       Filename:  test.cxx
 *
 *    Description:  CURSOR>BOOST_TETS
 *
 *        Version:  1.0
 *        Created:  2009ǯ08��26�� 16��41ʬ47��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S���dwestfalen, Iserlohn
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio;

int main()
{
  ip::tcp::iostream s( "www.boost.org", "http" );
  s << "GET / HTTP/1.0\r\n";
  s << "Host: www.boost.org\r\n";
  s << "\r\n";
  s << flush;
  string line;
  while( getline(s, line) )
    cout << line << endl;
}
