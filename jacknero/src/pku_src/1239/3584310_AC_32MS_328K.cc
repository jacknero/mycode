#include <stdio.h>
#include <string.h>
#define N_MAX 81
char seqStr[N_MAX];
char d[N_MAX][N_MAX];
char res[N_MAX],resTemp[N_MAX];
int num;
bool Great(int start1,int len1,int start2,int len2)
{
 while(len1 > 0 && seqStr[start1] == '0')
 {
  len1--;
  start1++;
 }
 while(len2 > 0 && seqStr[start2] == '0')
 {
  len2--;
  start2++;
 }
 if(len1 > len2)
  return true;
 else if(len1 == len2)
 {
  while(len1 > 0)
  {
   if(seqStr[start1] > seqStr[start2])
    return true;
   else if(seqStr[start1] < seqStr[start2])
    return false;
   else
   {
    start1++;
    start2++;
    len1--;
   }
  }
  return false;
 }
 else
  return false;
}
void GetResult(int idx,int len,int numTemp)
{
 int i,j;
 if(idx == len)
 {
  if(num == 0)
  {
   resTemp[numTemp] = len;
   num = numTemp + 1;
   memcpy(res,resTemp,num);
  }
  else
  {
   bool best = false;
   resTemp[numTemp] = len;
   for(i = numTemp,j = num - 1 ; i >= 0 && j >= 0 ; i--,j--)
   {
    if(resTemp[i] > res[j])
     best = true;
    if(resTemp[i] == res[j])
     continue;
    break;
   }
   if(best == true)
   {
    num = numTemp + 1;
    memcpy(res,resTemp,num);
   }
  }
 }
 else
 {
  resTemp[numTemp] = len;
  for(i = 1 ; i <= d[idx][len] ; i++)
  {
   if(d[idx-len][i] == 0)
    continue;
   GetResult(idx-len,i,numTemp+1);
  }
 }
}
void DP()
{
 int i,j,t,prev;
 bool bGreat;
 int len = strlen(seqStr + 1) + 1;
 d[1][1] = 1;
 for(i = 2 ; i < len ; i++)
 {
  d[i][i] = 1;
  for(j = 1 ; j < i ; j++)
  {
   prev = i - j;
   t = j;
   while(t < prev && seqStr[prev - t] == '0')
    t++;
   for( ; t > 0 ; t--)
   {
    if(d[prev][t] == 0)
     continue;
    
    if(Great(i - j + 1,j,prev - t + 1,t))
    {
     bGreat = true;
     break;
    }
   }
   if(bGreat == true)
    d[i][j] = t;
   else
    d[i][j] = 0;
  }
 }
 prev = len - 1;
 for(i = 1 ; i < len ; i++)
 {
  if(d[prev][i] > 0)
   break;
 }
 j = i;
 while(j < len && seqStr[prev - j] == '0')
  j++;
 num = 0;
 for( ; i <= j ; i++)
  GetResult(prev,i,0);
 prev = 1;
 for(i = num - 1 ; i > 0 ; i--)
 {
  j = prev + res[i];
  for( ; prev < j ; prev++)
   printf("%c",seqStr[prev]);
  printf(",");
 }
 j = prev + res[i];
 for( ; prev < j ; prev++)
  printf("%c",seqStr[prev]);
 printf("\n");
}
int main() 
{
 //freopen("test.txt","r",stdin);
 while(scanf("%s",seqStr + 1) != EOF)
 {
  if(strlen(seqStr + 1) == 1 && seqStr[1] == '0')
   break;
  DP();
 }
    return 0;
}