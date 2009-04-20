#include <iostream>
#include <cmath>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const double INF = 1e200;
const double EP = 1e-10;

struct point_t
{
    double x, y;
    point_t(double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
};

struct lineseg_t
{
    point_t s, e;
    lineseg_t (point_t a, point_t b)
    {
        s = a;
        e = b;
    }
    lineseg_t()
    {}
};

struct line_t
{
    double a, b, c;
};

bool operator <(point_t p1, point_t p2)
{
    return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}


bool operator ==(point_t p1, point_t p2)
{
    return abs(p1.x - p2.x) < EP && abs(p1.y - p2.y) < EP;
}

double multiply(point_t sp, point_t ep, point_t op)
{
    return (sp.x - op.x) * (ep.y - op.y) - (ep.x - op.x) * (sp.y - op.y);
}

bool online(lineseg_t l, point_t p)
{
    return abs(multiply(l.e, p, l.s)) < EP && (p.x - l.s.x) * (p.x - l.e.x) < EP && (p.y - l.s.y) * (p.y - l.e.y) < EP;
}

bool lineintersect(line_t l1, line_t l2, point_t &p)
{
    double d = l1.a * l2.b - l2.a * l1.b;
    if (abs(d) < EP) return false;
    p.x = (l2.c * l1.b - l1.c * l2.b) / d;
    p.y = (l2.a * l1.c - l1.a * l2.c) / d;
    return true;
}

line_t makeline(point_t p1, point_t p2)
{
    line_t t1;
    int sign = 1;
    t1.a = p2.y - p1.y;
    if (t1.a < 0)
    {
        sign = -1;
        t1.a = sign * t1.a;
    }
    t1.b = sign * (p1.x - p2.x);
    t1.c = sign * (p1.y * p2.x - p1.x * p2.y);
    return t1;
}

bool intersection(lineseg_t l1, lineseg_t l2, point_t &p)
{
    line_t ll1, ll2;
    ll1 = makeline(l1.s, l1.e);
    ll2 = makeline(l2.s, l2.e);
    if (lineintersect(ll1, ll2, p))
        return online(l1, p) && online(l2, p);
    else return false;
}

const int maxn = 100000;
point_t p[maxn];
int n;

point_t inter[maxn];
int cnt_inter;

int main()
{
    int ca = 1;
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        
        cnt_inter = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                lineseg_t l1(p[i], p[(i + 1) % n]), l2(p[j], p[(j + 1) % n]);
                point_t p;
                if (intersection(l1, l2, p))
                    inter[cnt_inter++] = p;
            }
        sort(inter, inter + cnt_inter);
        cnt_inter = unique(inter, inter + cnt_inter) - inter;
        
        int e = 0;
        for (int i = 0; i < cnt_inter; i++)
        {
            for (int j = 0; j < n; j++)
            {
                lineseg_t t(p[j], p[(j + 1) % n]);
                if (online(t, inter[i]) && !(t.s == inter[i]))
                    e++;
            }
        }
        printf("Case %d: There are %d pieces.\n", ca++, e + 2 - cnt_inter);
    }
    return 0;
}