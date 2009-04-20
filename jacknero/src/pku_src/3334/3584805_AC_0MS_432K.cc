#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cctype>
#include <cstring>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
const long long maxlonglong=0x7FFFFFFFFFFFFFFFLL;
const double inf = 1e200;
const double eps = 1e-9;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const int maxn = 2000;

typedef struct
{
    double x, y;
} point_t;

point_t ga[maxn], gb[maxn];
int cnt_ga, cnt_gb;
int bottom_a, bottom_b;
int v_water;

point_t p[maxn];
int cnt_p;

double cross(point_t a, point_t b)
{
    return a.x * b.y - a.y * b.x;
}

double count_area()
{
    double ret = 0.0;
    for (int i = 0; i < cnt_p; i++)
    {
        ret += cross(p[i], p[(i + 1) % cnt_p]) / 2.0;
    }
    return ret;
}

bool ok(double h)
{
    double area = 0.0;
    cnt_p = 0;
    for (int i = 0; i < bottom_a; i++)
    {
        if (cnt_p > 0)
        {
            p[cnt_p] = ga[i];
            cnt_p++;
        }
        if (ga[i].y >= h && ga[i + 1].y < h)
        {
            double t = (ga[i].y - h) / (h - ga[i + 1].y);
            double x = (ga[i].x + t * ga[i + 1].x) / (t + 1);
            p[0].x = x;
            p[0].y = h;
            cnt_p++;
        }
    }
    for (int i = bottom_a; i < cnt_ga; i++)
    {
        if (cnt_p > 0)
        {
            p[cnt_p] = ga[i];
            cnt_p++;
        }
        if (ga[i].y < h && ga[i + 1].y >= h)
        {
            double t = (ga[i].y - h) / (h - ga[i + 1].y);
            double x = (ga[i].x + t * ga[i + 1].x) / (t + 1);
            p[cnt_p].x = x;
            p[cnt_p].y = h;
            cnt_p++;
            break;
        }
    }
    area += count_area();
    cnt_p = 0;
    for (int i = 0; i < bottom_b; i++)
    {
        if (cnt_p > 0)
        {
            p[cnt_p] = gb[i];
            cnt_p++;
        }        
        if (gb[i].y >= h && gb[i + 1].y < h)
        {
            double t = (gb[i].y - h) / (h - gb[i + 1].y);
            double x = (gb[i].x + t * gb[i + 1].x) / (t + 1);
            p[0].x = x;
            p[0].y = h;
            cnt_p++;
        }
    }
    for (int i = bottom_b; i < cnt_gb; i++)
    {
        if (cnt_p > 0)
        {
            p[cnt_p] = gb[i];
            cnt_p++;
        }
        if (gb[i].y < h && gb[i + 1].y >= h)
        {
            double t = (gb[i].y - h) / (h - gb[i + 1].y);
            double x = (gb[i].x + t * gb[i + 1].x) / (t + 1);
            p[cnt_p].x = x;
            p[cnt_p].y = h;
            cnt_p++;
            break;
        }
    }
    area += count_area();
    if (area >= v_water) return false;
    else return true;
}


double work()
{
    double up, down;
    up = min(min(ga[0].y, ga[cnt_ga - 1].y), min(gb[0].y, gb[cnt_gb - 1].y));
    double t1 = inf, t2 = inf;
    for (int i = 0; i < cnt_ga; i++) if (ga[i].y < t1)
    {
        t1 = ga[i].y;
        bottom_a = i;
    }
    for (int i = 0; i < cnt_gb; i++) if (gb[i].y < t2)
    {
        t2 = gb[i].y;
        bottom_b = i;
    }
    down = min(t1, t2);
    
    while (fabs(up - down) > eps)
    {
        double mid = (up + down) / 2.0;
        if (ok(mid))
            down = mid;
        else up = mid;
    }
    return up;
}

int main()
{
    int ca;
    for (scanf("%d", &ca); ca--;)
    {
        scanf("%d", &v_water);
        scanf("%d", &cnt_ga);
        for (int i = 0; i < cnt_ga; i++) scanf("%lf%lf", &ga[i].x, &ga[i].y);
        scanf("%d", &cnt_gb);
        for (int i = 0; i < cnt_gb; i++) scanf("%lf%lf", &gb[i].x, &gb[i].y);
        double ans = work();
        printf("%.3lf\n", ans);
    }
    return 0;
}