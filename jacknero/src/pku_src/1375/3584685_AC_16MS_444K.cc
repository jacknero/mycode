#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const double eps = 1e-9;

typedef struct point_t
{
    int x, y;
};

typedef struct interval_t
{
    double l, r;
};

bool operator <(const interval_t &a, const interval_t &b)
{
    return a.l < b.l || a.l == b.l && a.r < b.r;
}

double dist(point_t b, point_t c)
{
    return sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
}

interval_t get_inter(point_t b, point_t c, int r)
{
    double alpha, beta, d = dist(b, c);
    beta = asin((c.x - b.x) / d);
    alpha = asin(r / d);
    double p1 = tan(beta - alpha) * b.y + b.x;
    double p2 = tan(beta + alpha) * b.y + b.x;
    interval_t ret;
    ret.l = p1;
    ret.r = p2;
    return ret;
}

point_t c[600];
int r[600];
point_t b;
int n;

interval_t inter[600];

int main()
{
    while (scanf("%d", &n), n != 0)
    {
        scanf("%d%d", &b.x, &b.y);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &c[i].x, &c[i].y, &r[i]);
        for (int i = 0; i < n; i++)
            inter[i] = get_inter(b, c[i], r[i]);
        
        sort(inter, inter + n);
        double l = inter[0].l, r = inter[0].r;
        for (int i = 1; i < n; i++)
        {
            if (inter[i].l < r + eps)
                r >?= inter[i].r;
            else
            {
                printf("%.2lf %.2lf\n", l, r);
                l = inter[i].l;
                r = inter[i].r;
            }
        }
        printf("%.2lf %.2lf\n", l, r);
        printf("\n");
    }
    return 0;
}