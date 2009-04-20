#include <iostream>
using namespace std;
 
int main()
{
        int ar[6], a,b,c,i;
 
        for(;;) {
                a=0x7fffffff; b=0; c=0;
                for(i=0;i<6;i++) {
                        cin >> ar[i];
                        a=min(a,ar[i]);
                        b=max(b,ar[i]);
                        c+=ar[i];
                }
                for(i=0;i<6 && ar[i]==0;i++); if(i==6) break;
                cout << (c-a-b)/4. << endl;
        }
 
        return 0;
}

