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

typedef struct line_t
{
    double l, r, y;
    int flag;
};

bool operator <(const line_t &a, const line_t &b)
{
    return a.y < b.y;
}

bool d_equal(const double &a, const double &b)
{
    return abs(a - b) < 1e-9;
}

int n;
double x[maxn];
int cnt_x, cnt_line;
line_t line[maxn];

int main()
{
    int ca = 1;
    while (scanf("%d", &n), n != 0)
    {
        cnt_x = 0;
        cnt_line = 0;
        for (int i = 0; i < n; i++)
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            x[cnt_x++] = x1;
            x[cnt_x++] = x2;
            line[cnt_line].flag = 0;
            line[cnt_line].l = x1;
            line[cnt_line].r = x2;
            line[cnt_line++].y = y1;
            line[cnt_line].flag = 1;
            line[cnt_line].l = x1;
            line[cnt_line].r = x2;
            line[cnt_line++].y = y2;
        }
        sort(line, line + cnt_line);
        sort(x, x + cnt_x);
        cnt_x = unique(x, x + cnt_x, d_equal) - x;

        double area = 0.0;
        for (int i = 0; i < cnt_x - 1; i++)
        {
            int cnt = 0;
            double now_y;
            for (int j = 0; j < cnt_line; j++) if (line[j].l <= x[i] && line[j].r >= x[i + 1])
            {
                if (cnt == 0) now_y = line[j].y;
                if (line[j].flag == 0) cnt++;
                else cnt--;
                if (cnt == 0) area += (x[i + 1] - x[i]) * (line[j].y - now_y);
            }
        }
        printf("Test case #%d\n", ca++);
        printf("Total explored area: %.2lf\n\n", area);
    }
    return 0;
}