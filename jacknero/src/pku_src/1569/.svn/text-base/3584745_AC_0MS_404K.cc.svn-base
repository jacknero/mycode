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
    char name;
    int x, y;
};

point_t p[20];

point_t operator -(const point_t &a, const point_t &b)
{
    point_t ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    return ret;
}

int cross(const point_t &a, const point_t &b)
{
    return a.x * b.y - a.y * b.x;
}

int area(int a, int b, int c)
{
    return cross(p[b] - p[a], p[c] - p[a]);
}

int inside(int t, int a, int b, int c)
{
    int ab = area(t, a, b), bc = area(t, b, c), ca = area(t, c, a);
    if (ab >= 0 && bc >= 0 && ca >= 0 || ab <= 0 && bc <= 0 && ca <= 0)
        return 1;
    else return 0;
}

int main()
{
    int n, ans;
    int ans_a, ans_b, ans_c;
    while (scanf("%d\n", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%c%d%d\n", &p[i].name, &p[i].x, &p[i].y);
        ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                {
                    int flag = 1;
                    for (int t = 0; t < n && flag; t++)
                        if (t != i && t != j && t != k)
                            if (inside(t, i, j, k))
                                flag = 0;
                    if (flag)
                    {
                        int t = abs(area(i, j, k));
                        if (t > ans)
                        {
                            ans = t;
                            ans_a = i;
                            ans_b = j;
                            ans_c = k;
                        }
                    }
                }
        printf("%c%c%c\n", p[ans_a].name, p[ans_b].name, p[ans_c].name);
    }
    return 0;
}