#include <iostream>
#include <algorithm>
using namespace std;
 
int k;
int a[15], v[15]={0,};
 
void foo(int p, int c)
{
        if(c==6) {
                for(int i=0;i<k;i++) if(v[i]) cout << a[i] << " ";
                cout << endl;
        } else if(k-p-1 >= 6-c) {
                v[p+1]=1; foo(p+1, c+1);
                v[p+1]=0; foo(p+1, c);
        }
}
 
bool solve()
{
        for(int i=0;i<k;i++) { cin >> a[i]; v[i]=0; }
        sort(a,a+k);
 
        v[0]=1; foo(0,1);
        v[0]=0; foo(0,0);
}
 
int main()
{
        cin >> k;
        solve();
        for(;;) {
                cin >> k;
                if(k==0) break;
                cout << endl;
                solve();
        }
 
        return 0;
}

