#include <iostream>
using namespace std;
 
int main()
{
	int T;
	int a,b,c,t;
 
	cin >> T;
	while(T--) {
		cin >> a >> b;
		t=0; while(a>0) { t=t*10+a%10; a/=10; } a=t;
		t=0; while(b>0) { t=t*10+b%10; b/=10; } b=t;
		c=a+b;
		t=0; while(c>0) { t=t*10+c%10; c/=10; }
		cout << t << endl;
	}
 
	return 0;
}

