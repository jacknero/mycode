#include <iostream>
using namespace std;
 
int main()
{
	bool n[10001]={false,};
	int i, t,tt;
 
	for(i=1;i<=10000;i++) {
		if(n[i]==false) {
			cout << i << endl;
 
			t = tt = i;
			while(t<=10000) {
				n[t]=true;
				while(tt>0) { t+=tt%10; tt/=10; }
				tt=t;
			}
		}
	}
 
	return 0;
}

