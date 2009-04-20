#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
        int n,i,j,tx,ty;
        int f;
 
        for(;;) {
                int m[105][105]={{0,},};
                cin >> n;
                if(n==0) break;
 
                for(i=0;i<n;i++) {
                        for(j=0;j<n;j++) {
                                cin >> m[i][j];
                                if(m[i][j]) { m[n][j]++; m[i][n]++; }
                        }
                }
 
                tx=-1; ty=-1; f=0;
                for(i=0;i<n;i++) {
                        if(m[i][n]&1) {
                                if(ty>=0) f=1;
                                else { ty=i+1; f=2; }
                        }
                        if(m[n][i]&1) {
                                if(tx>=0) f=1;
                                else { tx=i+1; f=2; }
                        }
                }
 
                if(f==0) puts("OK");
                else if(f==1 || tx<0 || ty<0) puts("Corrupt");
                else printf("Change bit (%d,%d)\n", ty,tx);
        }
 
        return 0;
}

