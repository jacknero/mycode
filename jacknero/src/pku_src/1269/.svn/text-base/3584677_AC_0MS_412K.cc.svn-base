#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

typedef struct line
{
    double a, b, c;
};

typedef struct line_t
{
    int x1, y1, x2, y2;
};

typedef struct vec_t
{
    int x, y;
};

typedef struct point
{
    double x, y;
};

int cross_mul(const vec_t &a, const vec_t &b)
{
    return a.x * b.y - a.y * b.x;
}

vec_t vec(const line_t &l)
{
    vec_t ret;
    ret.x = l.x1 - l.x2;
    ret.y = l.y1 - l.y2;
    return ret;
}

line make_line(line_t l)
{ 
    line tl;
    int sign = 1;
    tl.a = l.y2 - l.y1;
    if (tl.a < 0) 
    {
        sign = -1;
        tl.a = sign * tl.a;
    }
    tl.b = sign * (l.x1 - l.x2);
    tl.c = sign * (l.y1 * l.x2 - l.x1 * l.y2);
    return tl;
}

void line_intersect(line l1, line l2, point &p)
{ 
    double d = l1.a * l2.b - l2.a * l1.b;
    p.x = (l2.c * l1.b - l1.c * l2.b) / d;
    p.y = (l2.a * l1.c - l1.a * l2.c) / d;
}

int main()
{
    int ca;
    printf("INTERSECTING LINES OUTPUT\n");
    for (scanf("%d", &ca); ca--;) 
    {
        line_t l1, l2, l3, l4;
        scanf("%d%d%d%d%d%d%d%d", &l1.x1, &l1.y1, &l1.x2, &l1.y2, &l2.x1, &l2.y1, &l2.x2, &l2.y2);

        l3.x1 = l1.x1;
        l3.y1 = l1.y1;
        l3.x2 = l2.x1;
        l3.y2 = l2.y1;
        l4.x1 = l1.x1;
        l4.y1 = l1.y1;
        l4.x2 = l2.x2;
        l4.y2 = l2.y2;
        
        if (cross_mul(vec(l1), vec(l3)) == 0 && cross_mul(vec(l1), vec(l4)) == 0)
            printf("LINE\n");
        else if (cross_mul(vec(l1), vec(l2)) == 0)
            printf("NONE\n");
        else
        {
            point inter;
            line_intersect(make_line(l1), make_line(l2), inter);
            printf("POINT %.2lf %.2lf\n", inter.x, inter.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}