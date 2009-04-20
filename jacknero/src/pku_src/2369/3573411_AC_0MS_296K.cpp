#include <iostream>
#include <algorithm>
using namespace std;
 
int gcd(int a, int b)
{
        if(a<b) swap(a,b);
        while(b) { a%=b; swap(a,b); }
        return a;
}
 
int lcm(int a, int b)
{
        return (int)((a*(long long)b)/gcd(a,b));
}
 
int main()
{
        int N,res,i,cnt,t;
        int a[1002];
 
        cin >> N;
        for(i=1;i<=N;i++) cin >> a[i];
 
        res = 1;
        for(i=1;i<=N;i++) {
                for(cnt=1,t=a[i];t!=i;cnt++,t=a[t]);
                res = lcm(res,cnt);
        }
 
        cout << res << endl;
        return 0;
}

