#include <cstdio>
#include <algorithm>
using namespace std;
 
__int64 a[250003];
 
int main()
{
	int N;
	scanf("%d", &N);
 
	for(int i=1;i<=N;i++) scanf("%I64d", a+i);
	sort(a+1, a+N+1);
	if(N&1) {
		printf("%.1f\n", (double)a[(N+1)/2]);
	} else {
		__int64 tmp = (a[N/2]+a[N/2+1])*10 / 2;
		printf("%.1f\n", tmp/10.);
	}
 
	return 0;
}

