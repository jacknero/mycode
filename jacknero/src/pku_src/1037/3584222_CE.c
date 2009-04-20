#include <stdio.h>
 #include <string.h>
 
 const int N = 21;
 __int64 dp[2][N][N][N];
 int n;
 __int64 idx;
 bool chk[N];
 
void pre() {
    int i, j, m;

    memset(dp, 0, sizeof(dp));

    dp[0][1][0][0] = 1;
    dp[1][1][0][0] = 1;

   for(i = 2; i <= 20; ++i) {
     for(j = 0; j < i; ++j) {
           int k = i - j - 1;
           for(m = 1; m <= j; ++m) 
              dp[0][i][j][k] += dp[1][i-1][j-m][k+m-1];
            for(m = 1; m <= k; ++m)
                dp[1][i][j][k] += dp[0][i-1][j+m-1][k-m];
        }
    }
}

void DFS(int now, int last, int style, __int64 idx) {
    if(now <= 0) return;
    int i, j;
   for(i = 0; i < n; ++i) if(!chk[i]) {
       if(style == 0 && i < last) continue;
        if(style == 1 && i > last) return;

        chk[i] = true;
       int big = 0, small = 0;
        for(j = 0; j < n; ++j) if(!chk[j]) {
           if(j < i) small++;
            if(j > i) big++;
        }

        if(style == 0 || style == -1) {
            if(idx > dp[1][now][big][small]) idx -= dp[1][now][big][small];
            else {
                printf("%d ", i+1);
               DFS(now-1, i, 1, idx);    return;
            }
        }

        if(style == 1 || style == -1) {
            if(idx > dp[0][now][big][small]) idx -= dp[0][now][big][small];
            else {
                printf("%d ", i+1);
                DFS(now-1, i, 0, idx);    return;
           }
        }
        chk[i] = false;
   }
}

 int main() {
    int ntc;
    pre();
    scanf("%d ", &ntc);
    while(ntc--) {
        scanf("%d %I64d", &n, &idx);
        memset(chk, false, sizeof(chk));
        DFS(n, -1, -1, idx);
        putchar('\n');
    }
    return 0;
}