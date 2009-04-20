#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
        int n,m;
        int a[50002], t,i;
        bool flag;
 
        scanf("%d", &n);
        for(i=0;i<n;i++) scanf("%d", a+i);
        sort(a, a+n);
 
        flag = false;
        scanf("%d", &m);
        for(i=0;i<m;i++) {
                scanf("%d", &t);
                if(binary_search(a,a+n,10000-t)) flag=true;
        }
 
        puts(flag ? "YES" : "NO");
        return 0;
}

