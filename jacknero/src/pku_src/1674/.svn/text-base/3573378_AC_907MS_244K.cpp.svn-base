#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
        int t,n,a[10000];
        int i,j,cnt,mm;
 
        scanf("%d", &t);
        while(t--) {
                scanf("%d", &n);
                for(i=0;i<n;i++) scanf("%d", a+i);
 
                cnt=0;
                for(i=0;i<n;i++) {
                        mm=i;
                        for(j=i+1;j<n;j++) if(a[mm] > a[j]) mm=j;
                        if(mm!=i) { swap(a[mm], a[i]); cnt++; }
                }
 
                printf("%d\n", cnt);
        }
 
        return 0;
}

