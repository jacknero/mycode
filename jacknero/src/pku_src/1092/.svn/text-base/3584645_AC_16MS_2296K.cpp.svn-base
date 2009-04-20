#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const int maxn = 210;
const int prime = 502973;

typedef struct point_t
{
    int x, y, id;
    int cnt_child;
    int child[maxn];
};

typedef struct farmland_t
{
    int cnt;
    int v[maxn];
};

typedef struct hash_t
{
    farmland_t farmland;
    hash_t *next;
};

int n, size;
point_t point[maxn];

hash_t *hash[prime];

int operator ==(const farmland_t &a, const farmland_t &b)
{
    if (a.cnt != b.cnt)
        return 0;
    for (int i = 0; i < a.cnt; i++)
        if (a.v[i] != b.v[i])
            return 0;
    return 1;
}

int hash_insert(const farmland_t &farmland)
{
    unsigned int key = 1;
    for (int i = 0; i < farmland.cnt; i++)
        key *= farmland.v[i];
    key %= prime;

    for (hash_t *t = hash[key]; t; t = t->next)
        if (t->farmland == farmland)
            return 0;
    hash_t *t = new hash_t;
    t->farmland = farmland;
    t->next = hash[key];
    hash[key] = t;
    return 1;
}

int dot_mul(const point_t &a, const point_t &b)
{
    return a.x * b.x + a.y * b.y;
}

int cross_mul(const point_t &a, const point_t &b)
{
    return a.x * b.y - a.y * b.x;
}

point_t operator -(const point_t &a, const point_t &b)
{
    point_t ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    return ret;
}

double len(const point_t &a)
{
    return sqrt(double(a.x * a.x + a.y * a.y));
}

double angle_a_to_b(const point_t &a, const point_t &b)
{
    double ret = acos(dot_mul(a, b) / (len(a) * len(b)));
    int cross = cross_mul(a, b);
    if (cross == 0)
        return 0.0;
    else if (cross > 0)
        return -ret;
    else
        return ret;
}

int find_farmland(int a, int b, farmland_t &farmland)
{
    int stack[maxn * 2];
    int top = 2;
    stack[0] = a;
    stack[1] = b;
    int used[maxn];
    memset(used, 0, sizeof(used));
    used[a] = used[b] = 1;

    while (1)
    {
        double min_angle = 1e10;
        int min_i;
        for (int i = 0; i < point[stack[top - 1]].cnt_child; i++)
        {
            int p = point[stack[top - 1]].child[i];
            if (p == stack[top - 2])
                continue;
            double angle = angle_a_to_b(point[stack[top - 1]] - point[stack[top - 2]], point[p] - point[stack[top - 1]]);
            if (angle < min_angle)
            {
                min_angle = angle;
                min_i = p;
            }
        }
        if (used[min_i] == 2)
        {
            if (min_i != a)
                return 0;
            if (top & 1)
                return 0;
            if (top / 2 != size)
                return 0;
            for (int i = 0; i < top / 2; i++)
                if (stack[i] != stack[i + top / 2])
                    return 0;
            int area = 0;
            for (int i = 0; i < top / 2; i++)
                area += cross_mul(point[stack[i]], point[stack[i + 1]]);
            if (area <= 0)
                return 0;

            {
                farmland.cnt = top / 2;
                int min = maxint;
                int mini;
                for (int i = 0; i < top / 2; i++)
                    if (stack[i] < min)
                    {
                        min = stack[i];
                        mini = i;
                    }
                for (int i = 0; i < top / 2; i++)
                    farmland.v[i] = stack[mini + i];
                return 1;
            }
        }
        else
        {
            used[min_i]++;
            stack[top++] = min_i;
        }
    }
}

int count_farmland()
{
    memset(hash, 0, sizeof(hash));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < point[i].cnt_child; j++)
        {
            farmland_t farmland;
            int flag = find_farmland(i, point[i].child[j], farmland);
            if (flag)
                if (hash_insert(farmland))
                    cnt++;
        }
    return cnt;
}

int main()
{
    int ca;
    for (scanf("%d", &ca); ca--;)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d", &point[i].id, &point[i].x, &point[i].y, &point[i].cnt_child);
            for (int j = 0; j < point[i].cnt_child; j++)
                scanf("%d", &point[i].child[j]);
        }
        scanf("%d", &size);
        printf("%d\n", count_farmland());
    }
    return 0;
}