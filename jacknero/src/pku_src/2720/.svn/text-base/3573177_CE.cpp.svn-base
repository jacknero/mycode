#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
__int64 p(int a,int b,int m){
    __int64 u,t=b?p(a,b/2,m)%m:0;
    u=t*t%m;
    return b?b%2?(u*a)%m:u:1;
}

int f(int b,int i,int m){
    return i?p(b,f(b,i-1,m),m):1;
}

main(){
    int a=1,i,j,t,m,ans[101][10];

    for(;a<=100;++a){
        for(i=1;i<10;){
            t=i-1?a%10?f(a,i,1e7):0:a;
            ans[a][i++]=t;
        }
    }

    for(;cin>>a>>i>>j,a;){
        m=pow(10,j);
        cout<<setw(j)<<setfill('0')<<ans[a][i>9?9:i]%m<<endl;
    }
}
