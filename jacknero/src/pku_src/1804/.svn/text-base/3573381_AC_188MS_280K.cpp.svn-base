#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
        int N,T, n, a[1002];
        int cnt,i,j,mi;
 
        cin >> N;
        for(T=1;T<=N;T++) {
                cin >> n;
                for(i=0;i<n;i++) cin >> a[i];
 
                cnt=0;
                for(i=0;i<n;i++) {
                        for(j=0;j<n-1;j++) {
                                if(a[j] > a[j+1]) {
                                        swap(a[j], a[j+1]);
                                        cnt++;
                                }
                        }
                }
 
                printf("Scenario #%d:\n%d\n\n", T,cnt);
        }
 
        return 0;
}

