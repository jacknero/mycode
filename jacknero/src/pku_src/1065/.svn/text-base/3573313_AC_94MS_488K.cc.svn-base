#include <iostream>
#include <algorithm>
using namespace std;
 
struct S {
	int w,l;
};
 
bool comp(S a, S b)
{
	if(a.l == b.l) return a.w < b.w;
	return a.l < b.l;
}
 
int main()
{
	int T, n, cnt;
	int i,j,k;
	S s[5002];
 
	cin >> T;
	while(T--) {
		bool v[5002]={false, };
		cin >> n;
 
		for(i=0;i<n;i++) {
			cin >> s[i].l >> s[i].w;
		}
 
		sort(s,s+n,comp);
		cnt=0;
		for(i=0;i<n;i++) {
			if(v[i]==false) {
				v[i]=true;
				k=i;
				cnt++;
				for(j=i+1;j<n;j++) {
					if(v[j]==false && s[k].l<=s[j].l && s[k].w<=s[j].w) {
						v[j]=true;
						k=j;
					}
				}
			}
		}
 
		cout << cnt << endl;
	}
 
	return 0;
}
