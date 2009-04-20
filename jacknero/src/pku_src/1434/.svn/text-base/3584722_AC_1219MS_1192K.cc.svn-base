#include <iostream>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const int maxn = 50010;
const double eps = 1e-3;

typedef struct tank_t
{
    int b, h, w, d;
};

int n;
tank_t tank[maxn];
double water;

int ok(double mid)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (tank[i].b < mid && mid < tank[i].b + tank[i].h)
            sum += tank[i].w * tank[i].d * (mid - tank[i].b);
        if (tank[i].b + tank[i].h <= mid)
            sum += tank[i].w * tank[i].d * tank[i].h;
    }
    return sum < water;
}

double solve()
{
    double up = 0.0, down = 1e10;
    
    for (int i = 0; i < n; i++)
    {
        up >?= tank[i].b + tank[i].h;
        down <?= tank[i].b;
    }
    if (ok(up))
        return -1;

    double mid;

    while (up - down > eps)
    {
        mid = (up + down) / 2.0;
        if (ok(mid))
            down = mid;
        else
            up = mid;
    }
    if (ok(down))
        return down;
    else
        return up;
}

int main()
{
    int ca;
    for (scanf("%d", &ca); ca--;)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d%d", &tank[i].b, &tank[i].h, &tank[i].w, &tank[i].d);
        scanf("%lf", &water);
        double ans = solve();
        if (ans < 0)
            printf("OVERFLOW\n");
        else
            printf("%.2lf\n", ans);
    }
    return 0;
}