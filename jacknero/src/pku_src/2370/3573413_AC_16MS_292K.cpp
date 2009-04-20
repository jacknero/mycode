#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
        int K,ret,i;
        int ar[110];
 
        cin >> K;
        for(i=0;i<K;i++) cin >> ar[i];
        sort(ar, ar+K);
 
        ret=0;
        for(i=(K-1)/2;i>=0;i--) ret += ar[i]/2 + ((ar[i]&1) ? 1 :0);
        cout << ret << endl;
        return 0;
}

