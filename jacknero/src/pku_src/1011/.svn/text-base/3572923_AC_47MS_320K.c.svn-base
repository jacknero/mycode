#include<stdio.h>
int s[51], ss[51];

int solve(int k, int n, int num) {

    int i, t;
    if(num == 0) return 1;
    if(k == 0) return solve(n, n, num - 1);
    for(i = 50; i > 0; i--) {

        if(s[i] > 0 && k >= i) {

            s[i]--;
            t = solve(k - i, n, num);
            if(t) return 1;
            s[i]++;
            if(k == n) return 0;
        }
    }
    return 0;
}
int main() {

    int n, i, sum, t, max;
    while(1) {

        scanf("%d", &n);
        if(!n) break;
        max = 0;
        sum = 0;
        memset(ss, 0, sizeof(int) * 51);
        for(i = 0; i < n; i++) {

            scanf("%d", &t);
            ss[t]++;
            sum += t;
            if(max < t) max = t;
        }
        for(i = max; i < sum; i++) {

            if(sum % i) continue;
            for(t = 1; t < 51; t++) s[t] = ss[t];
            if(solve(i, i, sum / i)) break;
        }
        printf("%d\n", i);
    }
    return 0;
}