#include <iostream>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

int n;
int a[110][310];

int check(int x, int y, int p, int d)
{
    if (((x + y) & 1) && d == 1)
        return 0;
    if ((((x + y) & 1) == 0) && d == -1)
        return 0;
    if (x + d * ((p - 1) / 2) < 0 || x + d * ((p - 1) / 2) >= n)
        return 0;
    int q = 2 * p - 1, sy = y;
    for (int i = x; i != x + p * d; i += d)
    {
        for (int j = sy; j != sy + q; j++)
        {
            if (j < 0 || j > 2 * n - 1)
                return 0;
            if (a[i][j] != 1)
                return 0;
        }
        sy++;
        q -= 2;
    }
    return 1;
}

int main()
{
    int ca = 1;
    while (scanf("%d\n", &n), n != 0)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            char s[310];
            gets(s);
            for (int j = 0; s[j]; j++)
                if (s[j] == '#')
                    a[i][j] = 2;
                else if (s[j] == '-')
                    a[i][j] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < 2 * n - 1; j++)
                for (int k = n; k > 0; k--)
                {
                    if (((i + j) & 1) && check(i, j, k, -1))
                    {
                        ans >?= k;
                        break;
                    }
                    if (((i + j) & 1) == 0 && check(i, j, k, 1))
                    {
                        ans >?= k;
                        break;
                    }                    
                }
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n", ca++, ans * ans);
    }
    return 0;
}