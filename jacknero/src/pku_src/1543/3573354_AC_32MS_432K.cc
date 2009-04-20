#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
	int n,N1,N2,N3,a,b,c,d;
 
	cin >> n;
 
	for(d=1;d<=n;d++) {
		for(a=2;;a++) {
			N1 = d*d*d - a*a*a;
			if(N1<=0) break;
 
			for(b=a+1;;b++) {
				N2 = N1 - b*b*b;
				if(N2<=0) break;
 
				for(c=b+1;;c++) {
					N3 = N2 - c*c*c;
					if(N3<0) break;
					if(N3==0) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", d,a,b,c);
					}
				}
			}
		}
	}
 
	return 0;
}

