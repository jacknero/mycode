#import<algo.h>
long long n,r,x=1,y,p['___'],t[9];
main(){
	for(cin>>n>>r;x++<n;){
		for(y=x;!p[x]&y<=n;)p[y+=x]=1;
		for(y=x;!p[x]&y<=n;y*=x)t[x%10]+=n/y-(n-r)/y-r/y;
	}
	t[2]-=x=t[2]<?t[5];
	t[5]-=x;
	for(r=n=1;n++<9;)
		for(y=t[x=n]&3;y%2?r=r*x%10:y;y/=2)
			x*=x;
	cout<<r<<"\n";
}
