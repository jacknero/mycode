/*
 * =====================================================================================
 *
 *       Filename:  main_ans.cpp
 *
 *    Description:  CURSOR>
 *
 *        Version:  1.0
 *        Created:  2010年01月17日 23時25分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jacknero (), jack_nero2000@yahoo.co.jp
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

using namespace std;


void eratos( bool primes[] )
{
    int i,j;

      for( i=0; i<1000000; i++ )
            primes[i] = true;
        

        primes[0] = primes[1] = false;

          for( i=4; i<1000000; i+=2 )
                primes[i] = false;

            for( i=3; i<1000000; i+=2 ){
                  if( !primes[i] ) continue;
                      for( j=i+i; j<1000000; j+=i )
                              primes[j] = false;
                        }

              return;
}

int calc( int n, bool primes[] ){
    int cnt;

      cnt = 0;
        for( int i=1; i<=n; i++ )
              if( primes[i] ) cnt++;

          return cnt;
}

int main(void)
{
    int n;

      bool primes[1000000];
        eratos(primes);

          while( cin >> n )
                cout << calc( n, primes ) << endl;

            return 0;
}
