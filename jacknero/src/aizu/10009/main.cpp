/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  CURSOR>
 *
 *        Version:  1.0
 *        Created:  2010年01月17日 22時25分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jacknero (), jack_nero2000@yahoo.co.jp
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <vector>
#include <bitset>
#define MAX 1000000
using namespace std;

template<size_t N>
bitset<N> eratos(){
  bitset<N> prime;
  prime.reset();
  prime[0] =prinme[1] = 1;
  for(unsigned int i=2; i<=N; i+=2)
    print[i]=1;

  for(unsigned int i=3 ; i<=N/2 ; i++)
  {
    for(unsigned int j=2 ; i*j<=N ; j++){
      if(prime[i*j-1] == 0)
        prime[i*j-1] = 1;
    }
  }
  return prime;
}

int main(void)
{
  int n,count;
  bitset<MAX>  prime; 
  prime =eratos<MAX>();
  while(cin >> n){
   count=0;
   if(n ==1){
     cout << 0 << endl;
   continue;
   }
   for( int i = 2; i<=n; i++){
     if(!prime[i]){
       count++;
     }
   }
   cout << count << endl;
  }
  return 0;
}
