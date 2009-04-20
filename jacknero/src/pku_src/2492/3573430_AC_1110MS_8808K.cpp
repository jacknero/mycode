#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
 
int main()
{
        int N,T,i,n,m,a,b;
        bool flag;
 
        scanf("%d", &N);
        for(T=1;T<=N;T++) {
                int bugs[2001]={0,};
                scanf("%d %d", &n,&m);
 
                vector<int> G[2001];
                memset(bugs, 0, sizeof(int)*(n+1));
                for(i=0;i<m;i++) {
                        scanf("%d %d", &a,&b);
                        G[a].push_back(b); G[b].push_back(a);
                }
 
                deque<int> q;
                int t;
                flag = true;
 
                for(i=1;i<=n;i++) {
                        if(!G[i].empty() && bugs[i]==0) {
                                q.clear();
                                q.push_back(i);
                                bugs[i]=1;
                                while(!q.empty()) {
                                        t = q.front(); q.pop_front();
                                        for(i=G[t].size()-1;i>=0;i--) {
                                                if(bugs[G[t][i]]==0) {
                                                        bugs[G[t][i]] = bugs[t]+1;
                                                        q.push_back(G[t][i]);
                                                } else {
                                                        if((bugs[G[t][i]]&1) == (bugs[t]&1)) {
                                                                flag=false; break;
                                                        }
                                                }
                                        }
                                        if(flag==false) break;
                                }
                                if(flag==false) break;
                        }
                }
 
                printf("Scenario #%d:\n%suspicious bugs found!\n", T,
                        flag ? "No s" : "S");
                if(T<N) puts("");
        }
 
        return 0;
}

