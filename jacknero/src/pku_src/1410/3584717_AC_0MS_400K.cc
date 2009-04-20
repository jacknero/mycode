#include <iostream>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

struct point_t
{
    int x, y;
    point_t(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
};

struct lineseg_t
{
    point_t s, e;
    lineseg_t(point_t a, point_t b)
    {
        s = a;
        e = b;
    }
};

point_t operator -(const point_t &a, const point_t &b)
{
    point_t ret(a.x - b.x, a.y - b.y);
    return ret;
}

int64 cross_mul(const point_t &a, const point_t &b)
{
    return int64(a.x) * b.y - int64(a.y) * b.x;
}

int64 cross_mul(const point_t &a, const point_t &b, const point_t &c)
{
    return cross_mul(a - c, b - c);
}

bool intersect_e(const lineseg_t &a, const lineseg_t &b)
{
    return
        //排斥实验
        max(a.s.x, a.e.x) >= min(b.s.x, b.e.x) &&
        max(b.s.x, b.e.x) >= min(a.s.x, a.e.x) &&
        max(a.s.y, a.e.y) >= min(b.s.y, b.e.y) &&
        max(b.s.y, b.e.y) >= min(a.s.y, a.e.y) &&
        //跨立实验
        cross_mul(b.s, a.e, a.s) * cross_mul(a.e, b.e, a.s) >= 0 &&
        cross_mul(a.s, b.e, b.s) * cross_mul(b.e, a.e, b.s) >= 0;
}

int main()
{
    int ca;
    for (scanf("%d", &ca); ca--;)
    {
        int x1, y1, x2, y2, rx1, ry1, rx2, ry2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d%d%d%d", &rx1, &ry1, &rx2, &ry2);
        if (rx1 > rx2)
            swap(rx1, rx2);
        if (ry1 > ry2)
            swap(ry1, ry2);
        if (rx1 <= x1 && x1 <= rx2 && ry1 <= y1 && y1 <= ry2
        || rx1 <= x2 && x2 <= rx2 && ry1 <= y2 && y2 <= ry2)
        {
            printf("T\n");
            continue;
        }
        point_t p1(x1, y1), p2(x2, y2), rp1(rx1, ry1), rp2(rx1, ry2), rp3(rx2, ry2), rp4(rx2, ry1);
        lineseg_t ls(p1, p2), rl1(rp1, rp2), rl2(rp2, rp3), rl3(rp3, rp4), rl4(rp4, rp1);
        if (intersect_e(ls, rl1) || intersect_e(ls, rl2) || intersect_e(ls, rl3) || intersect_e (ls, rl4))
        {
            printf("T\n");
            continue;
        }
        printf("F\n");
    }
    return 0;
}