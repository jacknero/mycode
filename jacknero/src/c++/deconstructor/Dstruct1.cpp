/*
 * =====================================================================================
 *
 *       Filename:  Dstruct1.cpp
 *
 *    Description:  dstruct
 *
 *        Version:  1.0
 *        Created:  2008年07月31日 18時44分47秒
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

//CIntArray a(10);

int main(){
  {
    CIntArray b(20);
    Viss(1);

    CIntArray c(30);
    Viss(2);

    {
      CIntArray d(40);
      Viss(3);
    }
    Viss(4);

    return 0;
  }
}
