/*
 * =====================================================================================
 *
 *       Filename:  test2.cpp
 *
 *    Description:  CURSOR>itest
 *
 *        Version:  1.0
 *        Created:  2009年09月04日 22時53分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */


#include <iostream>

using namespace std;


int main(void ){
  long long result =1;
  for(long long j = 0; j < 1000000; j++){
    result = 1;
    for(int i = 1; i <= 20; i++){
      result *= i;
    }
  }
    cout << result << endl;

  return 0;

}
