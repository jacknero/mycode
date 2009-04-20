#include <iostream>
using namespace std;
 
int main()
{
        int K,L,end;
        cin >> K; end = K/2+1;
        for(L=2;L<=end;L++) if(K%(L+1)==0) break;
        cout << (L>end ? K-1 : L) << endl;
        return 0;
}

