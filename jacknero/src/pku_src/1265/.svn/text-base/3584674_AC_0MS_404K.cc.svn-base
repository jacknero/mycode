#include <iostream>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int x[110], y[110], dx[110], dy[110], f[110];
    int s, k, kase, n, e, i, j;
    scanf("%d", &kase);
    for (k = 1; k <= kase; k++)
    {
        scanf("%d", &n);
        memset(f, 0, sizeof(f));
        x[0] = 0; y[0] = 0; s = 0; e = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &dx[i], &dy[i]);
            x[i] = x[i - 1] + dx[i];
            y[i] = y[i - 1] + dy[i];
            e += gcd(abs(dx[i]), abs(dy[i]));
            s += x[i - 1] * y[i] - x[i] * y[i - 1];
        }
        j = s + 2 - e;
        printf("Scenario #%d:\n", k);
        printf("%d %d %.1lf\n\n", j / 2, e ,(double) s / 2);
    }
    return 0;
}