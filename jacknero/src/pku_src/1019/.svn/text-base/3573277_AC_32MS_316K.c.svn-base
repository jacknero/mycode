#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
int n,m,j,i,sum,k;
char s[10];
scanf("%d",&n);

while(n--)
{
   scanf("%d",&m);
   sum=1,k=1;
   while(m>sum)
   {
    m=m-sum;
    k++;
    _ltoa(k,s,10);
    sum+=strlen(s);
   }
  
  
   j=1;
   sum=1;
   _ltoa(j,s,10);
   while(m>sum)
   {
    m=m-sum;
    j++;
    _ltoa(j,s,10);
    sum=strlen(s);
  
   
   }

   m--;

        printf("%d\n",s[m]-'0');
  
  
}
return 0;

}