#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
 
int p[1000001][2]={{0,},};
bool vv[1000001]={false,};
bool ss[1000001]={false,};
 
int main()
{
        int i,j;
 
        for(i=1;i<=1000;i++) ss[i*i]=true;
        for(i=2;i<=1000000;i++) {
                p[i][0]=p[i-1][0];
                p[i][1]=p[i-1][1];
 
                if(vv[i]==false) {
                        p[i][0]++;
                        if(i==2 || i%4==1) {
                                for(j=1;j*j<i;j++)
                                        if(ss[i-j*j]) { p[i][1]++; break; }
                        }
 
                        for(j=i<<1;j<=1000000;j+=i) vv[j]=true;
                }
        }
 
        int l,u;
 
        for(;;) {
                cin >> l >> u;
                if(l==-1 && u==-1) break;
                printf("%d %d ", l,u);
                if(l<0) l=1; if(u<0) u=1;
                printf("%d %d\n", p[u][0]-p[l-1][0], p[u][1]-p[l-1][1]);
        }
 
        return 0;
}

