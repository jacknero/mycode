#include<stdio.h>
#include<string.h>
char Morse[26][5]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
int best[10001],n,len;
char s[10001],dic[10001][30],word[10001][101];
void init()
{
int i,j;
memset(word,'\0',sizeof(word));
for(i=0;i<n;i++)
   for(j=0;j<strlen(dic[i]);j++)
    strcat(word[i],Morse[dic[i][j]-'A']);
memset(best,0,sizeof(best));
best[0]=1;
//for(i=0;i<n;i++)
//    printf("%s\n",word[i]);
}
void DP()
{
int i,j,k,flag;
for(i=0;i<=len;i++)
   if(best[i])
    for(j=0;j<n;j++)
    {
     flag=1;
     for(k=0;k<strlen(word[j]);k++)
     {
      if(i+k==len)break;
      if(s[i+k]!=word[j][k]){flag=0;break;}
     }
     if(flag)best[i+strlen(word[j])]+=best[i];
    }
printf("%d\n",best[len]);
}
int main()
{
int cas,i;
scanf("%d",&cas);
while(cas--)
{
   scanf("%s%d",s,&n);
   len=strlen(s);
   for(i=0;i<n;i++)
    scanf("%s",dic[i]);
   init();
   DP();
}
}
