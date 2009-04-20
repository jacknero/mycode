/*
 * =====================================================================================
 *
 *       Filename:  Copy1.cpp
 *
 *    Description:  copy constructor
 *
 *        Version:  1.0
 *        Created:  2008年08月01日 12時52分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include "IntArray.h"
using namespace std;

void Viss(const int num)
{
  cout << "Viss :No " << num << endl;
}

void Disp(CIntArray array)
{
  Viss(2);

  int i;

  for(i = 0; i < array.NumOf(); i++)
    cout <<  array.Get(i) << ' ';
  cout << endl;

  Viss(3);
}

int main()
{
  CIntArray arrayAtoZ('Z'- 'A' + 1);
  int i;

  for(i = 0; i < arrayAtoZ.NumOf(); i++)
    arrayAtoZ.Set(i, 'A' + i);

  Viss(1);
  Disp(arrayAtoZ);
  Viss(4);

  return 0;
}
