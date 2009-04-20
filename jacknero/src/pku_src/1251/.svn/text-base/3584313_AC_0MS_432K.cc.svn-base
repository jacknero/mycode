#include <stdio.h>
#include <iostream.h>

#define MaxWeight 9999

void Prim(int r[][28],int n)
{
int *lowCost =new int [n+1];
int i,j,k;

int minCost;
for(i=2;i<=n;i++)
   lowCost[i]=r[1][i];
int cost=0;

lowCost[1]=-1;

for(i=2;i<=n;i++)
{
   minCost=MaxWeight;
   for(j=2;j<=n;j++)
   {
    if(lowCost[j]<minCost && lowCost[j] >0)
    {
     minCost=lowCost[j];
     k=j;
    }
   }

   cost += minCost;
   lowCost[k]=-1;

   for(j=2;j<=n;j++)
   {
    if(r[k][j]<lowCost[j])
     lowCost[j]=r[k][j];
   }
}
printf("%d\n",cost);

}
int   main()
{
int villagesnum;
int Tree[28][28];
int i,j,m,n;

char ch[28][1];
int cost=0;
while(cin>>villagesnum)
{
    i=1;
   if(villagesnum==0)
    break;
       for(m=1;m<=villagesnum;m++)
         for(n=1;n<=villagesnum;n++)
       if(m==n)
        Tree[m][n]=0;
       else
       Tree[m][n]=MaxWeight;

   int N;
   while( i<=villagesnum-1 )
   {
    cin>>ch[i][1];
    cin>>N;
    if(N==0)
    {
     i++;
     continue;
    }

    int k;
       j=1;
    while(j<=N)
    {
     char c;
     int weight;
        cin>>c;
     cin>>weight;
                 k= c-'A'+1;
     Tree[k][i] = Tree[i][k]=weight;
     j++;
    }
       i++;
   }

     Prim(Tree,villagesnum);

}
return 0;
}
