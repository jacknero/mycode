#include <iostream>
#include <vector>
using namespace std;
 
 
int main()
{
	int n, cnt, a,b,c, aa,bb,cc,m;
	vector<int> v;
 
	v.push_back(1); cnt=1;
	a=b=c=0;
	while(cnt<=1500) {
		aa=v[a]*2; bb=v[b]*3; cc=v[c]*5;
		m = aa < bb ? aa : bb;
		m = cc < m ? cc : m;
		if(m>v[cnt-1]) { cnt++; v.push_back(m); }
		if(m==aa) a++;
		else if(m==bb) b++;
		else c++;
	}
 
	for(;;) {
		cin >> n;
		if(n==0) break;
		cout << v[n-1] << endl;
	}
 
	return 0;
}

