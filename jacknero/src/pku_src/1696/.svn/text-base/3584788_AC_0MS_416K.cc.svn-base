#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

typedef struct point_t
{
    int num;
    int x, y;
};

point_t operator -(const point_t &a, const point_t &b)
{
    point_t ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    return ret;
}

int64 det(const point_t &a, const point_t &b)
{
    return int64(a.x) * b.y - int64(a.y) * b.x;
}

int64 dot(const point_t &a, const point_t &b)
{
    return int64(a.x) * b.x + int64(a.y) * b.y;
}

double dist(const point_t &a)
{
    return sqrt(double(a.x * a.x + a.y * a.y));
}

double angle(const point_t &a, const point_t &b)
{
    
    double ret = acos(double(dot(a, b)) / (dist(a) * dist(b)));
    return det(a, b) > 0 ? ret : -ret;
}

const int maxn = 100;
point_t p[maxn];
int used[maxn];

int main()
{
    int ca;
    int n;
    for (scanf("%d", &ca); ca--;)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &p[i].num, &p[i].x, &p[i].y);

        int miny = 0x7FFFFFFF, mini;
        for (int i = 0; i < n; i++)
            if (p[i].y < miny)
            {
                miny = p[i].y;
                mini = i;
            }
        memset(used, 0, sizeof(used));
        used[mini] = 1;
        int now = mini;
        point_t now_vector;
        now_vector.x = 0;
        now_vector.y = p[mini].y;
        printf("%d", n);
        for (int i = 1; i < n; i++)
        {
            printf(" %d", p[now].num);
            double min_alpha = 1e200;
            int minj;            
            for (int j = 0; j < n; j++) if (!used[j])
            {
                double t = angle(now_vector, p[j] - p[now]);
                if (t < min_alpha)
                {
                    min_alpha = t;
                    minj = j;
                }
            }
            now_vector = p[minj] - p[now];
            now = minj;
            used[minj] = 1;
        }
        printf(" %d\n", p[now].num);
    }
    return 0;
}