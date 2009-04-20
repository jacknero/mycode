#include <iostream>
using namespace std;
 
int main()
{
        int i,j, a[31]={1,0,3,0,0,0,};
 
        for(i=4;i<=30;i++) {
                a[i]=a[i-2]*3;
                for(j=i-4;j>=0;j-=2) a[i]+=a[j]*2;
        }
        for(;;) {
                cin >> i;
                if(i<0) break;
                cout << a[i] << endl;
        }
 
        return 0;
}

