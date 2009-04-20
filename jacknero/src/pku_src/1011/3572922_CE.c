#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nss;
int ss[70];
int used[70];
int totss;
int maxss;
int len;

int cmp(const void * a, const void * b)
{
 return (*(int *)b) - (*(int *)a);
}

int search(int times, int rest, int pos)
{
 int flag = 0;
 if(rest == len) flag = 1; //第一种剪枝
 int i;
 if(times == totss/len) return 1;
 for(i = pos; i<nss; i++)
  if(!used[i])
  {
   if(rest == ss[i])
   {
    used[i] = 1;
    if(search(times+1, len, 0)) return 1;
    used[i] = 0;
     return 0;                      //第二种剪枝                                                                    
   }
   else if(ss[i]<rest)
   {
    used[i] = 1;
    if(search(times, rest-ss[i], i+1)) return 1;
    used[i] = 0;
    if(flag) return 0;
    while(ss[i] == ss[i+1]) i++;
   }
   else if(flag) return 0;
  }
 return 0;
}

int main()
{
// freopen("t.in", "r", stdin);
 int i;
 while(scanf("%d", &nss), nss>0)
 {
  memset(ss, 0, sizeof(ss));
  totss = maxss = 0;
  for(i=0; i<nss; i++)
  {
   scanf("%d", &ss[i]);
   totss += ss[i];
   if(ss[i]>maxss) maxss = ss[i];
  }
  qsort(ss, 70, sizeof(ss[0]), cmp);
  for(i=maxss; i<=totss; i++)
  {
   if(i==totss) 
   {printf("%d\n", totss); break;}
   if(totss%i==0)
   {     
    memset(used, 0, sizeof(used));
    len = i;

   if(search(0, len, 0)) {printf("%d\n", i); break;}
   }
  }
 }
 return 0;
}