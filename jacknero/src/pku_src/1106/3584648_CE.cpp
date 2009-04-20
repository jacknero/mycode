#include <iostream>
#include <cmath>

const int MAXN = 151;
int tx, ty, n, i, j, k, max, x[MAXN], y[MAXN];
float r, d;

float dist(int i)
{
    return sqrt((x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty));
}

bool insc(int i, int j)
{
    if ((tx - x[i]) * (ty - y[j]) - (tx - x[j]) * (ty - y[i]) >= 0) return true;
    else return false;
}

int main()
{
    while (scanf("%d%d%f", &tx, &ty, &r), r > 0)
    {
        scanf("%d", &n);
        j = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &x[0], &y[0]);
            d = dist(0);
            if (d <= r) {
                j++;
                x[j] = x[0];
                y[j] = y[0];
            }
        }
        n = j;
        max = 0;
        for (i = 1; i <= n; i++)
        {
            k = 0;
            for (j = 1; j <= n; j++) if (insc(i, j)) k++;
            max >?= k;
        }
        printf("%d\n", max);
    }
    return 0;
}