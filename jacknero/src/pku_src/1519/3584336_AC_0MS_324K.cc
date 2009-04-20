#include "stdio.h"
#include "string.h"

/*用字符串,去弥补整型过大问题,考虑整型过大时程序*/
int main ()
{   
    long int i,k,n,sum;
    char a[10000];
    for(;scanf("%s",a)!=EOF;)
    {   
        if(a[0]=='0') return 1;
        sum=0;
        n=strlen(a);
        for(i=0;i<n;i++)
            sum+=a[i]-48;
        k=sum;
        if(k>9) 
            for(sum=0;;)
            {   
                for(;k!=0;)
                {
                    sum+=k%10;
                    k=k/10;
                }
                if(sum<10) break;
                else {k=sum;sum=0;}
            }
        
        printf("%d\n",sum);
    }
    return 1;
} 
