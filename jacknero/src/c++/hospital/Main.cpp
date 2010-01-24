/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  CURSOR>Hospital number
 *
 *        Version:  1.0
 *        Created:  2010ǯ01��23�� 23��11ʬ03��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jacknero (), jack_nero2000@yahoo.co.jp
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>  
using namespace std;  

int getValue(int x){  
  if ( x == 4 ) return 5;  
  return (x < 4) ? x : x+2;  
}  

void convert( int n ){  
  if ( n == 0 ) return;  
  convert( n/8 );  
  cout << getValue(n%8);  
}  

main(){  
  int n;  
  while( cin >> n && n ) { convert(n); cout << endl; }  
}  
