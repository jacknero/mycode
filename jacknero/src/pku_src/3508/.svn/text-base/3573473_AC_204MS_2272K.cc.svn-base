#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 
int main()
{
        int T,i,j,p,a,b;
        char n[1000005],r[1000005],ch;
 
        for(T=1;;T++) {
                scanf("%s", n+1);
                if(n[1]=='0') break;
                n[0]='0'; p = strlen(n);
 
                a=b=0;
                for(i=1;i<p;i+=2) a+=n[i]-'0';
                for(i=2;i<p;i+=2) b+=n[i]-'0';
                if(abs(a-b)%11==0) printf("%d. IMPOSSIBLE\n", T);
                else {
                        if(a>b) n[0]='0'+a-b;
                        else n[0]='0'+11-b+a;
                        printf("%d. ", T);
                        ch=n[p-1]; r[p-1]=ch;
                        for(i=p-2;i>0;i--) {
                                if(n[i] >= ch) ch=n[i]-ch+'0';
                                else {
                                        ch = n[i]+10-ch+'0';
                                        for(j=i-1;n[j]=='0';j--) n[j]='9';
                                        n[j]--;
                                }
                                r[i]=ch;
                        }
                        r[p]=0;
                        puts(r+1);
                }
        }
 
        return 0;
}

