#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
	bool prime[1000001]={false,};
	int i,j, n;
 
	for(i=3;i<=1000000;i++) {
		if(prime[i]==false) for(j=i<<1;j<=1000000;j+=i) prime[j]=true;
	}
 
	for(;;) {
		cin >> n;
		if(n==0) break;
 
		for(i=3;i<=n/2;i++) {
			if(prime[i]==false && prime[n-i]==false) {
				printf("%d = %d + %d\n", n,i,n-i);
				break;
			}
		}
 
		if(i>n/2) puts("Goldbach's conjecture is wrong.");
	}
 
	return 0;
}

