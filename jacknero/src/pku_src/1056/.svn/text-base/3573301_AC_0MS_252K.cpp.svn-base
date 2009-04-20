#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
bool comp(string s1, string s2)
{
	return s1.size() < s2.size();
}
 
int main()
{
	string s[11];
	int i,j,n, T;
	bool flag;
 
	for(T=1;;T++) {
		if(!(cin >> s[0])) break;
		for(n=1;;n++) {
			cin >> s[n];
			if(s[n][0]=='9') break;
		}
		sort(s, s+n, comp);
 
		flag=true;
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				if(s[i]==s[j].substr(0,s[i].size())) { flag=false; break; }
			}
			if(flag==false) break;
		}
 
		printf("Set %d is %simmediately decodable\n", T, flag ? "" : "not ");
	}
 
	return 0;
}

