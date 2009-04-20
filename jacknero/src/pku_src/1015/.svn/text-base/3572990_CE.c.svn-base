#include <stdio.h> 
  #include <stdlib.h> 
  
  #define POOL_MAX 500 
  #define VALUE_MAX 21 
  #define JURY_MAX 30 
  
  
  int prosecution[POOL_MAX],defense[POOL_MAX]; 
 int m,n; 
 int caseno = 1; 
 
 int last[JURY_MAX][2*VALUE_MAX*JURY_MAX+1]; //二?数?，一个是几个数，一个是?几个数可以得到的?合?果。last存?前一个的取?
 int sum[JURY_MAX][2*VALUE_MAX*JURY_MAX+1]; //?存得到的Dj-pj的Dj+pj；
 
 int compare(const void *a, const void *b) 
 { 
   return *((const int *) a) - *((const int *) b); 
 } 
 
 void solve_case() 
 { 
   int i,j,k,l,l2; 
   int sol[JURY_MAX]; 
 
   for(i=0;i<m;i++)  //初始化
     for(j=0;j<2*VALUE_MAX*m+1;j++)  
       last[i][j] = sum[i][j] = -1; 
 
   for(i=0;i<n;i++) //初始取一个?合的?果
     if(prosecution[i] + defense[i] > sum[0][VALUE_MAX*m+prosecution[i]-defense[i]]) 
       { 
             last[0][VALUE_MAX*m+prosecution[i]-defense[i]] = i; 
             sum[0][VALUE_MAX*m+prosecution[i]-defense[i]] =  prosecution[i] + defense[i];
 
       } 
   for(j=0;j<m-1;j++) 
     for(k=0;k<2*VALUE_MAX*m;k++) 
       if(last[j][k] >= 0) 
     for(i=0;i<n;i++) 
       if(sum[j+1][k+prosecution[i]-defense[i]] < sum[j][k] + prosecution[i] + defense[i]) 
         { 
               for(l=j,l2=k;l>=0;l--) //保??个人只能取一次。
                 { 
                   if(last[l][l2] == i) break; 
                   l2 -= prosecution[last[l][l2]]-defense[last[l][l2]]; 
                 } 
               if(l < 0) 
                 { 
                   /**//* add person to jury */ 
                   last[j+1][k+prosecution[i]-defense[i]] = i; 
                   sum[j+1][k+prosecution[i]-defense[i]] = sum[j][k] + prosecution[i] + defense[i];
                    
                 } 
         } 
 
   for(i=0;i<=VALUE_MAX*m;i++) //?找最小的情况
     if(sum[m-1][VALUE_MAX*m+i] >= 0 || sum[m-1][VALUE_MAX*m-i] >= 0) 
       { 
         if(sum[m-1][VALUE_MAX*m+i] > sum[m-1][VALUE_MAX*m-i]) 
           i = VALUE_MAX*m+i; 
         else 
          i = VALUE_MAX*m-i; 
         break; 
       } 
    
   printf("Jury #%d\n",caseno++); 
   printf("Best jury has value %d for prosecution and value %d for defence:\n", 
      (sum[m-1][i]+(i-VALUE_MAX*m))/2,(sum[m-1][i]-(i-VALUE_MAX*m))/2); 
   for(j=m-1;j>=0;j--) //依次?推。
     { 
       sol[j] = last[j][i]+1; 
       i -= prosecution[last[j][i]]-defense[last[j][i]]; 
     } 
   qsort(sol,m,sizeof(int),compare); //注意排序
   for(i=0;i<m;i++) printf(" %d",sol[i]); 
   printf("\n\n"); 
 } 
 
 void skip_line() { while(getc(stdin) >= ' '); } 
 
 int read_case() 
 { 
   int i; 
 
   scanf("%d %d",&n,&m);  
   if(n == 0) return 0; 
   skip_line(); 
   for(i=0;i<n;i++) 
     { 
       scanf("%d %d",prosecution+i,defense+i); 
       skip_line(); 
     } 
   return 1; 
 } 
 
 int main() 
 { 

  while(read_case()) solve_case(); 

  return 0; 
} 
