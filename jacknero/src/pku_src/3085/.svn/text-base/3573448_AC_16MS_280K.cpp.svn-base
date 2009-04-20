#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
        int N,T,C,i;
        int ta,tb,tc,td, q,d,n,p;
        int total, nq,nd,nn,np;
 
        cin >> N;
        for(T=1;T<=N;T++) {
                cin >> C;
 
                ta=C; total=1000;
                for(q=0;q*25<=ta;q++) {
                        tb=ta-q*25;
                        for(d=0;d*10<=tb;d++) {
                                tc=tb-d*10;
                                for(n=0;n*5<=tc;n++) {
                                        td=tc-n*5;
                                        p = td;
                                        if(q+d+n+p < total) {
                                                total = q+d+n+p;
                                                nq=q; nd=d; nn=n; np=p;
                                        }
                                }
                        }
                }
 
                printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
                        T, nq, nd, nn, np);
        }
 
        return 0;
}

