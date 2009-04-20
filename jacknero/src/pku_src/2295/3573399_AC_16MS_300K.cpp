#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int T,i, a,b,n,sign;
	string s,l,r;
	bool flag;
 
	cin >> T;
	while(T--) {
		cin >> s;
		i=s.find('=');
		l = s.substr(0,i);
		r = s.substr(i+1);
 
		a=b=0;
		n=0; sign=1; flag=false;
		for(i=0;i<l.size();i++) {
			if(l[i]=='x') { if(flag==false) n=1; a+=n*sign; n=0; flag=false;}
			else if(l[i]=='-') { b-=n*sign; sign=-1; n=0; flag=false;}
			else if(l[i]=='+') { b-=n*sign; sign=1; n=0; flag=false;}
			else {
				n=n*10+l[i]-'0';
				flag=true;
			}
		}
		if(n) b-=n*sign;
 
		n=0; sign=1; flag=false;
		for(i=0;i<r.size();i++) {
			if(r[i]=='x') { if(flag==false) n=1; a-=n*sign; n=0; flag=false;}
			else if(r[i]=='-') { b+=n*sign; sign=-1; n=0; flag=false;}
			else if(r[i]=='+') { b+=n*sign; sign=1; n=0; flag=false;}
			else {
				n=n*10+r[i]-'0';
				flag=true;
			}
		}
 
		if(n) b+=n*sign;
 
		if(a==0 && b==0) cout << "IDENTITY" << endl;
		else if(a==0 && b!=0) cout << "IMPOSSIBLE" << endl;
		else if(a!=0 && b==0) cout << "0" << endl;
		else {
			if((a<0 && b<0) || (a>0 && b>0)) cout << b/a << endl;
			else if(b%a==0) cout << b/a << endl;
			else cout << b/a-1 << endl;
		}
 
	}
 
	return 0;
}

