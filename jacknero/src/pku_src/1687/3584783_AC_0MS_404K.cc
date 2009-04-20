#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const int maxn = 100;
const double eps = 1e-9;
const double pi = acos(-1.0);

typedef struct point_t
{
    int x, y;
};

typedef struct polygon_t
{
    int n;
    point_t p[maxn];
};

int64 det(const point_t &a, const point_t &b)
{
    return int64(a.x) * b.y - int64(a.y) * b.x;
}

point_t p[maxn];
int n;

int main()
{
    int ca;
    for (scanf("%d", &ca); ca--;)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);

        int m;
        scanf("%d", &m);
        int64 max_area = 0;
        int ans;
        for (int i = 0; i < m; i++)
        {
            polygon_t poly;
            scanf("%d", &poly.n);
            for (int j = 0; j < poly.n; j++)
            {
                int t;
                scanf("%d", &t);
                poly.p[j] = p[t - 1];
            }
            int64 area = 0;
            for (int j = 0; j < poly.n; j++)
                area += det(poly.p[j], poly.p[(j + 1) % poly.n]);
            if (abs(area) > max_area)
            {
                max_area = abs(area);
                ans = i + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}