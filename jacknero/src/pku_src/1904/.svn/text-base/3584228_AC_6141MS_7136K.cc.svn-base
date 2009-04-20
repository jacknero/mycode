#

#include <vector>
#include <algorithm>
using namespace std;

const int N = 2010;
int nv;
vector<int> head[N], head2[N], S;
int go[N], back[N]; 
int scc[N];
bool chk[N];
bool love[N][N];

void DFS(int x) {
    int i;
    chk[x] = 1;
    for(i = 0; i < head[x].size(); ++i) {
        int j = back[head[x][i]];
        if(!chk[j]) 
            DFS(j);    
    }
    S.push_back(x); //入栈
}

 void DFS2(int x, int id) {
    int y = go[x], i;
    chk[y] = 1;
    scc[x] = id; //标记连通分支
    for(i = 0; i < head2[y].size(); ++i) {
        int j = go[head2[y][i]]; //找到对应的公主
        if(!chk[j])
            DFS2(head2[y][i], id);
    }
}

 int main() {
    scanf("%d", &nv);
    int i, t, u, j;
    for(i = 0; i < nv; ++i) {
        scanf("%d", &t);
        while(t--) {
            scanf("%d", &u);
            love[i][u-1] = 1;
            head[i].push_back(u-1); //有向边
            head2[u-1].push_back(i); //逆转的有向边
        }
    }
    for(i = 0; i < nv; ++i) {
        scanf("%d", &t);
        go[i] = t-1;
       back[t-1] = i;
   }

    memset(chk, 0, sizeof(chk));
    for(i = 0; i < nv; ++i) if(!chk[i]) {
        DFS(i); //对王子作DFS 确定i到达的点
    }

    memset(chk, 0, sizeof(chk));
    int sccId = 0;
    for(i = S.size()-1; i >= 0; --i) {
        int j = S[i];
        if(!chk[go[j]]) {
            DFS2(j, sccId); 
 //再对公主做DFS 确定连通分支(对王子和对公主其实是一样的 写法有点不同而已:)
            sccId++;
        }
    }

    for(i = 0; i < nv; ++i) {
        vector<int> ans;
        for(j = 0; j < nv; ++j) if(love[i][j]) {
            if(scc[i] == scc[back[j]])
                ans.push_back(j);
        }
        sort(ans.begin(), ans.end());
        printf("%d", ans.size());
       for(j = 0; j < ans.size(); ++j)
            printf(" %d", ans[j]+1);
        printf("\n");
   }

    return 0;
}

