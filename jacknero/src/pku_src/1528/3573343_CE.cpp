#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
 
int main()
{
	int n,sum,i;
 
	puts("PERFECTION OUTPUT");
	for(;;) {
		cin >> n;
		if(n==0) break;
 
		printf("%5d  ", n);
		sum=0;
		i=(int)sqrt(n);
		if(i*i==n) sum-=i;
		for(i;i>1;i--) if(n%i==0) sum += i + n/i;
		sum++;
		if(sum==n) puts("PERFECT");
		else if(sum<n) puts("DEFICIENT");
		else puts("ABUNDANT");
	}
	puts("END OF OUTPUT");
 
	return 0;
}

