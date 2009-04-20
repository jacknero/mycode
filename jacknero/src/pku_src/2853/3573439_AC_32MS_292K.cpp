#include <iostream>
using namespace std;
 
int main()
{
	int T,n,t, cnt;
	__int64 i, sum;
 
	cin >> T;
	while(T--) {
		cin >> t >> n;
 
		cnt=0;
		for(i=2;;i++) {
			sum = i*(i+1)/2;
			if(sum > n) break;
			if((n-sum)%i == 0) cnt++;
		}
 
		cout << t << " " << cnt << endl;
	}
 
	return 0;
}

