#include <iostream>
#include <cmath>
using namespace std;
#define out(x) (cout << #x << ": " << x << endl)
const int maxint = 0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const int maxn = 20;

typedef struct point_t
{
    int x, y;
};

int operator <(const point_t &a, const point_t &b)
{
    return a.y < b.y || a.y == b.y && a.x < b.x;
}

point_t operator -(const point_t &a, const point_t &b)
{
    point_t ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    return ret;
}

double dist(const point_t &a, const point_t &b)
{
    return sqrt(double((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

int cross(const point_t &a, const point_t &b)
{
    return a.x * b.y - a.y * b.x;
}

int turn_left(const point_t &a, const point_t &b, const point_t &c)
{
    return cross(b - a, c - b) > 0;
}

typedef struct polygon_t
{
    int n;
    point_t p[maxn];
};

class point_set_c
{
public:
    void init(int _n, point_t _p[]);
    double convex_hull();
private:
    int n;
    point_t p[maxn];
};

void point_set_c::init(int _n, point_t _p[maxn])
{
    n = _n;
    for (int i = 0; i < n; i++)
        p[i] = _p[i];
}

double point_set_c::convex_hull()
{
    int stack[maxn];
    int top = 1;
    stack[0] = 0;

    sort(p, p + n);

    for (int i = 1; i < n;)
    {
        if (top == 1 || turn_left(p[stack[top - 2]], p[stack[top - 1]], p[i]))
            stack[top++] = i++;
        else top--;
    }
    int t_top = top;
    for (int i = n - 2; i >= 0;)
    {
        if (top == t_top || turn_left(p[stack[top - 2]], p[stack[top - 1]], p[i]))
            stack[top++] = i--;
        else top--;
    }
    double ret = 0.0;
    for (int i = 0; i < top - 1; i++)
        ret += dist(p[stack[i]], p[stack[i + 1]]);
    return ret;
}

int n;
point_t tree[maxn];
int v[maxn], l[maxn];

int ans_value, ans_num;
double ans_len;
int ans[maxn];

int used[maxn];

int dfs(int start)
{
    if (start > n)
    {
        int tot_value = 0, tot_len = 0, tot_num = 0;
        point_set_c ps;
        point_t tmp[maxn];
        int tt = 0;

        for (int i = 0; i < n; i++)
            if (used[i])
            {
                tot_value += v[i];
                tot_len += l[i];
                tot_num++;
            }
            else
                tmp[tt++] = tree[i];

        ps.init(tt, tmp);

        double t = ps.convex_hull();

        if (tot_len >= t)
        {
            
            if (tot_value < ans_value || tot_value == ans_value && tot_num < ans_num)
            {
                ans_value = tot_value;
                ans_len = t;
                ans_num = 0;
                for (int i = 0; i < n; i++) if (used[i]) ans[ans_num++] = i;
            }
        }
    }
    for (int i = start; i <= n; i++)
        if (!used[i])
        {
            used[i] = 1;
            dfs(i + 1);
            used[i] = 0;
        }
}

int main()
{
    int ca = 1;
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d%d%d", &tree[i].x, &tree[i].y, &v[i], &l[i]);
        memset(used, 0, sizeof(used));
        ans_value = maxint;
        dfs(0);
        printf("Forest %d\n", ca++);
        printf("Cut these trees:");
        for (int i = 0; i < ans_num; i++) printf(" %d", ans[i] + 1);
        printf("\n");

        double extra_wood = 0.0;
        for (int i = 0; i < ans_num; i++) extra_wood += l[ans[i]];
        extra_wood -= ans_len;
        printf("Extra wood: %.2lf\n", extra_wood);
        printf("\n");
    }
    return 0;
}