#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const int maxn = 1000;

typedef struct point_t
{
    int x, y;
};

bool d_equal(const double &a, const double &b)
{
    return abs(a - b) < 1e-9;
}

point_t p[maxn];
int n;

double slope[maxn];
int m;

int main()
{
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            m = 0;
            for (int j = 0; j < n; j++) if (i != j)
                slope[m++] = double(p[j].y - p[i].y) / (p[j].x - p[i].x);
            sort(slope, slope + m);
            int cnt = 1;
            for (int j = 1; j < m; j++)
            {
                if (d_equal(slope[j], slope[j - 1]))
                    cnt++;
                else
                    cnt = 1;
                ans >?= cnt;
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}