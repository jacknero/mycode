#include <stdio.h>
#include <string.h>
#define MAXN 100002
#define PRE 0.0001

double a[MAXN], tmp[MAXN], sum[MAXN];
int N, F, mini, maxi;

void read()
{
int i;
scanf("%d%d", &N, &F);
scanf("%lf", &a[1]);
mini=maxi=a[1];
for( i=2; i<=N; i++)
{
   scanf("%lf", &a[i] );
   if( a[i]<mini )
    mini =a[i];
   if( a[i]>maxi )
    maxi =a[i];
}
}

double MaxSum_F( double delta )
{
int i;
double b[MAXN], max;
sum[0]=0;
for( i=1; i<=N; i++)
{
   tmp[i] = a[i]-delta;
   sum[i] = sum[i-1]+tmp[i];
}
b[F]=sum[F];
max = b[F];
for( i=F+1; i<=N; i++)
{
   b[i] = b[i-1]+tmp[i];
   if( b[i]<sum[i]-sum[i-F] )
    b[i] = sum[i]-sum[i-F];
   if( b[i] > max )
    max = b[i];
}
return max;
}

double b_dp( double low, double high )
{
double middle, res;
do
{
   middle = (low+high)/2;
   res = MaxSum_F( middle );
   if( res > 0 )
    low = middle;
   else
    high =middle;
} while( low < (high-PRE) );
return middle;
}

int main()
{
read();
printf("%d\n", (int)( 1000*(PRE+b_dp( mini, maxi))) );
    return 0;
}