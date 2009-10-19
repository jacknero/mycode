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
#include <boost/format.hpp>
using namespace std;

int main()
{
  // %1%�����������%2%��������������
  cout <<
    boost::format("%1% %2%") % "hello" % 100
    << endl;

  // printf������OK�
  // %05d:0���5���� %x:16��� %f:������ %%:%����
  cout <<
    boost::format("%05d %x %f %%") % 200 % 255 % 3.33
    << endl;

  // ����%2%�%1%���������
  cout <<
    boost::format("%2% %1%") % "hello" % 100
    << endl;

  // %N$...�����������������
  // %04x:0���4��16��� %s:���
  cout <<
    boost::format("%2$04x %1$s") % "hello" % 254
    << endl;
  
  return 0;
}
