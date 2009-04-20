#include <stdio.h>
 #include <string.h>
 #define maxn 1001
 
 int main()
 {
 int tt,n;
 int num,i,j,k,t,total;
 char c[maxn];
 int d[maxn];
 int b[maxn];
 int a[101][maxn];
 int jg[maxn];
 bool p;
 int sign,sign1;
 
 
 //freopen("in.txt","r",stdin);
 
 while (scanf("%d%d",&n,&k)==2)
 {
 tt=0;
 bool q=false;
 total=0;
 memset(d,0,sizeof(d));
 memset(b,0,sizeof(b));
 for (i=1;i<=k;i++)
 {
 scanf("%d",&num);
 
 a[i][0]=0;
 for (j=1;j<=num*2;j++)
 {
 a[i][0]++;
 scanf("%d",&a[i][a[i][0]]);
 }
 scanf("\n");
 scanf("%c",&c[i]);
 if (c[i]=='=')
 {
 for (j=1;j<=num*2;j++)
 b[a[i][j]]=1;
 }
 else 
 {
 total++;
 d[total]=i;
 }
 }
 if (total==0) 
 {
 for (i=1;i<=n;i++)
 if (b[i]!=1) 
 {
 tt++;
 jg[tt]=i;
 }
 }
 else
 {
 for (i=1;i<=n;i++)
 if (b[i]!=1) 
 {
 p=true;
 sign=1;
 for (t=1;t<=a[d[1]][0];t++)
 if (i==a[d[1]][t]) break;
 if (i!=a[d[1]][a[d[1]][0]]&&t-1==a[d[1]][0]) 
 {
 p=false;
 continue;
 }
 if (t<=a[d[1]][0]/2&&c[d[1]]=='<')
 sign=-1;
 else
 if (t>a[d[1]][0]/2&&c[d[1]]=='>')
 sign=-1;
 if (p==false) continue; 
 
 for (j=2;j<=total;j++)
 {
 p=true;
 sign1=1;
 for (t=1;t<=a[d[j]][0];t++)
 
 if (i==a[d[j]][t]) break;
 if (i!=a[d[j]][a[d[j]][0]]&&t-1==a[d[j]][0]) 
 {
 p=false;
 break;
 }
 if (t<=a[d[j]][0]/2&&c[d[j]]=='<')
 sign1=-1;
 else
 if (t>a[d[j]][0]/2&&c[d[j]]=='>')
 sign1=-1;
 if (p==false) break;
 if (sign1!=sign) 
 {
 p=false;
 break;
 }
 }
 if (p==true)
 {
 tt++;
 jg[tt]=i;
 continue;
 }
 }
 }
 if (tt==1) printf("%d\n",jg[tt]);
 else printf("0\n");
 
 }
 return 0;
 }  
