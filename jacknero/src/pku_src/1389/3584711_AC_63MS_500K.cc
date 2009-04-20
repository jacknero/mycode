#include <iostream>
#include <cmath>
using namespace std;
#define out(x) (cout << #x << ": " << x << endl)
const int maxint = 0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) {for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) {for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }
const int maxn = 4010;

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
    while (1)
    {
        cnt_x = 0;
        cnt_line = 0;
        while (1)
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            if (x1 == -1.0) break;
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
        if (cnt_x == 0) break;
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
        printf("%.0lf\n", area);
    }
    return 0;
}