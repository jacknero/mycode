#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const double eps = 1e-10;
const double pi = acos(-1.0);
const int maxn = 110;

typedef struct point_t
{
    double x, y;
};

typedef struct interval_t
{
    double l, r;
};

double get_angle(double x, double y)
{
    if (abs(x) < eps)
    {
        if (y > 0) return pi / 2.0;
        else return 3.0 * pi / 2.0;
    }
    else
    {
        double t = atan(y / x);
        if (x < 0)
            t += pi;
        if (t < 0) t += 2.0 * pi;
        return t;
    }
}

interval_t get_range(point_t a, point_t b)
{
    if (a.x * b.y - a.y * b.x < eps)
    {
        swap(a, b);
    }
    double t1 = get_angle(a.x, a.y);
    double t2 = get_angle(b.x, b.y);
    if (t2 < t1 - eps) t2 += 2.0 * pi;
    interval_t ret;
    ret.l = t1;
    ret.r = t2;
    return ret;
}

bool operator <(const interval_t &a, const interval_t &b)
{
    return a.l < b.l || a.l == b.l && a.r < b.r;
}

bool between(const double &a, const double &x, const double &b)
{
    return x > a - eps && x < b + eps;
}

point_t p[maxn];
interval_t interval[maxn];

int main()
{
    double k, h;
    int n;
    scanf("%lf%lf%d", &k, &h, &n);
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        for (int i = 0; i < n; i++)
            interval[i] = get_range(p[i], p[(i + 1) % n]);
        
        double l = interval[0].l, r = interval[0].r;
        for (int i = 1; i < n; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (between(l, interval[i].l + j * 2 * pi, r) || between(l, interval[i].r + j * 2 * pi, r))
                {
                    l = min(l, interval[i].l + j * 2 * pi);
                    r = max(interval[i].r + j * 2 * pi, r);
                    break;
                }
            }
        }
        printf("%.2lf\n", min(r - l, 2.0 * pi) * k * h);
    }
    return 0;
}