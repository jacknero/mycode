#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
int main()
{
        int n,x, a[21],T,nn;
        int pos, cnt, i;
 
        for(T=1;scanf("%d %d", &n,&x)==2;T++) {
                char p[55]={0,};
                nn=n;
 
                for(i=0;i<20;i++) scanf("%d", a+i);
                for(i=0;i<20;i++) {
                        cnt=0;
                        for(pos=1;pos<=n;pos++) {
                                if(p[pos]==0) {
                                        cnt++;
                                        if(cnt%a[i]==0) { p[pos]=1; nn--; }
                                        if(nn==x) break;
                                }
                        }
                        if(nn==x) break;
                }
 
                printf("Selection #%d\n", T);
                for(i=1;i<=n;i++) if(!p[i]) printf("%d ", i);
                puts("\n");
        }
 
        return 0;
}

