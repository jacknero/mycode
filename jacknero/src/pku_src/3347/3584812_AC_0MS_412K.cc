#include <iostream>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

typedef struct square_t
{
    int c, r;
};

typedef struct interval_t
{
    int l, r;
};

bool operator <(const interval_t &a, const interval_t &b)
{
    return a.l < b.l || a.l == b.l && a.r < b.r;
}

square_t s[100];
interval_t interval[100];
int cnt_interval;

int merge()
{
    if (cnt_interval == 0) return 0;
    sort(interval, interval + cnt_interval);
    int l = interval[0].l, r = interval[0].r;
    int len = 0;
    for (int i = 1; i < cnt_interval; i++)
        if (interval[i].l <= r)
            r >?= interval[i].r;
        else
        {
            len += r - l;
            l = interval[i].l;
            r = interval[i].r;
        }
    len += r - l;
    return len;
}

int ans[100];
int cnt_ans;

int main()
{
    int n;
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &s[i].r);
        s[0].c = s[0].r;
        for (int i = 1; i < n; i++)
        {
            int t = 0;
            for (int j = 0; j < i; j++)
                t >?= min(s[j].c + 2 * s[j].r, s[j].c + 2 * s[i].r);
            s[i].c = t;
        }
        cnt_ans = 0;
        for (int i = 0; i < n; i++)
        {
            cnt_interval = 0;
            for (int j = 0; j < n; j++) if (s[j].r > s[i].r)
            {
                interval[cnt_interval].l = s[j].c - s[j].r;
                interval[cnt_interval].r = s[j].c + s[j].r;
                cnt_interval++;
            }
            int t1 = merge();
            cnt_interval = 0;
            for (int j = 0; j < n; j++) if (s[j].r > s[i].r || j == i)
            {
                interval[cnt_interval].l = s[j].c - s[j].r;
                interval[cnt_interval].r = s[j].c + s[j].r;
                cnt_interval++;
            }
            int t2 = merge();
            if (t1 != t2)
                ans[cnt_ans++] = i;
        }
        for (int i = 0; i < cnt_ans; i++)
            printf("%d ", ans[i] + 1);
        printf("\n");
    }
    return 0;
}