/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  CURSOR>multiple
 *
 *        Version:  1.0
 *        Created:  2009ǯ09��16�� 11��00ʬ29��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S���dwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
using namespace std;


int main(int argc, const char *argv[])
{
  int min ;
  int max ;
  stringstream ss;
  ss << argv[1];
  ss >> min;

  ss.clear();
  ss.str("");

  ss << argv[2];
  ss >> max;
  //cout << min << max;

  for(int i = min; i <= max ; i++){
    if(i % 5 == 0){
      cout << i << endl;
    }
  }



  return 0;
}
