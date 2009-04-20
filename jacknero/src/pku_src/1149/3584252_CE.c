#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<stdlib.h>
 
const int SIZE = 1010;
const int max = 10000000;
struct Point{
        int c,f;
}net[SIZE][SIZE];
int pre[SIZE],s,t,n;
int queue[SIZE],head,tail;
 
bool bfs()
{
        int i;
        head = tail = 0;
        memset(pre,0,sizeof(pre));
        queue[tail++] = s;
        pre[s] = s;
        while(tail != head){
               int temp = queue[head++];
               for(i = 1; i <= n+2; i++)
                       if(pre[i] == 0 && (net[temp][i].c>net[temp][i].f && 
net[temp][i].f>=0 || net[i][temp].c>=net[i][temp].f && net[i][temp].f>0)){
                               if(net[temp][i].f < net[temp][i].c)
                                      pre[i] = temp;
                               if(net[i][temp].f > 0)
                                      pre[i] = -temp;
                               if(i == t){
                                      return true;
                               }
                               else
                                       queue[tail++] = i;
                       }
        }
        return false;
}
int maxflow()
{
        int flow = 0,i;
        while(bfs()){
               int dx = 0x7FFFFFFF;
               int temp;
               for(i = t; i != s; i = abs(pre[i])){
                       if(pre[i] >= 0)
                               temp = net[pre[i]][i].c-net[pre[i]][i].f;
                       else
                               temp = net[i][-pre[i]].f;
                       if(dx > temp)
                               dx = temp;
               }
               for(i = t; i != s; i= abs(pre[i])){
                       if(pre[i] >= 0)
                               net[pre[i]][i].f += dx;
            else
                               net[i][-pre[i]].f -= dx;
               }
               flow += dx;
        }
        return flow;
}
 
int num[1010],f[1010];
int main()
{
        int m,i,j,temp;
        scanf("%d %d",&m,&n);
        for(i = 1; i <= m; i++){
               scanf("%d",&num[i]);
               f[i] = 0;
        }
        int x;
        for(j = 2; j <= n+1; j++){
               scanf("%d",&temp);
               for(int k = 0; k < temp; k++){
                       scanf("%d",&x);
                       if(f[x] == 0){
                               net[1][j].c += num[x];
                               f[x] = j;
                       }
                       else
                               net[f[x]][j].c = max;
               }
               scanf("%d",&temp);
               net[j][n+2].c = temp;
        }
        s = 1; t = n+2;
        int out = maxflow();
        printf("%d\n",out);
        return 0;
}
