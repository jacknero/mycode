/*
 * =====================================================================================
 *
 *       Filename:  Math1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008年05月15日 14時22分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream.h>
#include <math.h>

int main()
{
  double a, b;

  cout <<"直角をはさむ２辺の長さを入力してください>";
  cin >> a >> b;

  cout << "斜辺の長さは"
    << sqrt(a * a + b * b) << "です。" << endl;

  return 0;
}

