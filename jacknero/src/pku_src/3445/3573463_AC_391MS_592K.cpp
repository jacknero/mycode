#include <string>
#include <vector>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <cstring>
using namespace std;
 
void foo(int n)
{
	int i;
	if(n==0) printf("{}");
	else if(n==1) printf("{{}}");
	else {
		putchar('{');
		for(i=0;i<n;i++) {
			foo(i);
			if(i<n-1) printf(",");
		}
		putchar('}');
	}
}
int main()
{
	int a[16]={-1,},i;
	int sum;
 
	sum=0;
	for(i=2;i<=15;i++) {
		a[i] = sum+i-1;
		sum+=a[i];
	}
 
	int T;
	string s1,s2;
	int c1,c2,n1,n2;
 
	cin >> T;
	while(T--) {
		cin >> s1 >> s2;
		c1 = count(s1.begin(), s1.end(), ',');
		c2 = count(s2.begin(), s2.end(), ',');
 
		if(s1.size()==2) c1=-1;
		if(s2.size()==2) c2=-1;
 
		for(i=0;i<=15;i++) {
			if(a[i]==c1) n1=i;
			if(a[i]==c2) n2=i;
		}
 
		sum=n1+n2;
		foo(sum);
		puts("");
	}
 
	return 0;
}

