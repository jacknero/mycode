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

typedef struct star_t
{
    int x, y, b;
};

int operator <(const star_t &a, const star_t &b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

int n;
star_t map[maxn];

int cnt_col;
int col_size[50];
char col_name[50][50];
star_t col[50][50];

star_t sol[50];
int bright;

int count(star_t ap[], star_t bp[], int size_a, int size_b)
{
    int ret = 0;
    if (size_b == 1)
    {
        for (int i = 0; i < size_a; i++)
            if (ap[i].b > bright)
            {
                bright = ap[i].b;
                sol[0] = ap[i];
            }
        return size_a;
    }

    int p = bp[1].x - bp[0].x;
    int q = bp[1].y - bp[0].y;

    for (int i = 0; i < size_a; i++)
        for (int j = 0; j < size_a; j++) if (i != j)
        {
            int flag = 1;
            int sum_bright = ap[i].b + ap[j].b;
            star_t tmp_sol[50];
            int len = 2;
            tmp_sol[0] = ap[i];
            tmp_sol[1] = ap[j];

            for (int k = 2; k < size_b; k++)
            {
                double c = bp[k].x - bp[0].x;
                double d = bp[k].y - bp[0].y;
                double a = double(c * p + d * q) / double(p * p + q * q);
                double b = double(d * p - c * q) / double(p * p + q * q);
                double x = a * (ap[j].x - ap[i].x) - b * (ap[j].y - ap[i].y) + ap[i].x;
                double y = a * (ap[j].y - ap[i].y) + b * (ap[j].x - ap[i].x) + ap[i].y;
                int ix = rint(x);
                int iy = rint(y);

                if (abs(x - ix) > 1e-5 || abs(y - iy) > 1e-5)
                {
                    flag = 0;
                    break;
                }
                int t;
                for (t = 0; t < size_a; t++)
                {
                    if (ix == ap[t].x && iy == ap[t].y)
                    {
                        tmp_sol[len++] = ap[t];
                        sum_bright += ap[t].b;
                        break;
                    }
                }
                if (t == size_a)
                    flag = 0;
            }
            if (flag != 0)
            {
                ret++;
                if (sum_bright > bright)
                {
                    bright = sum_bright;
                    memcpy(sol, tmp_sol, sizeof(sol));
                }
            }
        }
    return ret;
}

int solve()
{
    for (int i = 0; i < cnt_col; i++)
    {
        bright = 0;
        int p = count(map, col[i], n, col_size[i]);
        printf("\n%s occurs %d time(s) in the map.\n", col_name[i], p / count(col[i], col[i], col_size[i], col_size[i]));
        if (p > 0)
        {
            printf("Brightest occurrence:");
            sort(sol, sol + col_size[i]);
            for (int j = 0; j < col_size[i]; j++)
                printf(" (%d,%d)", sol[j].x, sol[j].y);
            printf("\n");
        }
    }
    printf("-----\n");
}

int main()
{
    int ca = 1;
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &map[i].x, &map[i].y, &map[i].b);
        scanf("%d", &cnt_col);
        for (int i = 0; i < cnt_col; i++)
        {
            scanf("%d%s", &col_size[i], &col_name[i]);
            for (int j = 0; j < col_size[i]; j++)
                scanf("%d%d", &col[i][j].x, &col[i][j].y);
        }
        printf("Map #%d\n", ca++);
        solve();
    }
    return 0;
}