#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
        int n,i,j;
        int res;
 
        for(;;) {
                cin >> n;
                if(n==0) break;
 
                res=1;
                while(n>1) {
                        for(i=2;;i++) {
                                for(j=0;n%i==0;j++) n/=i;
                                if(j>0) {
                                        res *= (i-1)*pow((double)i,j-1.);
                                        break;
                                }
                        }
                }
 
                cout << res << endl;
        }
 
        return 0;
}

