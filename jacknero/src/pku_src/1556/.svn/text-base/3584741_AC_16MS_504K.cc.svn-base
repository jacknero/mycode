#include <iostream>
#include <cmath>
#include <vector>
#include <map>

#define maxn 1010
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const double eps = 1e-9;

typedef double weight;

class graph_c
{
public:
    void init(int _n);
    void dijkstra(int S);
    void add_edge(int u, int v, weight w);
    weight dist[maxn];
private:
    int n;
    vector <int> r[maxn];
    vector <weight> e[maxn];
    int pa[maxn];
    multimap <weight, int> h;
};

void graph_c::init(int _n)
{
    n = _n;
    for (int i = 0; i < n; i++)
    {
        r[i].clear();
        e[i].clear();
    }
}

void graph_c::add_edge(int u, int v, weight w)
{
    r[u].push_back(v);
    e[u].push_back(w);
}

void graph_c::dijkstra(int S)
{
    weight d, tmp;
    int v;
    multimap<weight, int>::iterator it;
    h.clear();
    for (int i = 0; i < n; i++) dist[i] = -1;
    dist[S] = 0;
    pa[S] = -1;
    h.insert(multimap<weight, int>::value_type(0, S));
    while (!h.empty())
    {
        it = h.begin();
        v = it->second;
        d = it->first;
        h.erase(it);
        for (int i = 0; i < r[v].size(); i++)
        {
            tmp = d + e[v][i];
            int j = r[v][i];
            if (dist[j] < 0 || tmp < dist[j])
            {
                dist[j] = tmp;
                pa[j] = v;
                h.insert(multimap<weight, int>::value_type(tmp, j));
            }
        }
    }
}

typedef struct point_t
{
    double x, y;
};

typedef struct line_seg_t
{
    point_t s, e;
};

double dist(const point_t &a, const point_t &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int dblcmp(double d)
{
    if (abs(d) < eps) return 0;
    return d > 0 ? 1 : -1;
}

double det(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}

double cross(const point_t &a, const point_t &b, const point_t &c)
{
    return det(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}

bool seg_intersect(const line_seg_t &a, const line_seg_t &b)
{
    return (dblcmp(cross(a.s, b.s, b.e)) ^ dblcmp(cross(a.e, b.s, b.e))) == -2
        && (dblcmp(cross(b.s, a.s, a.e)) ^ dblcmp(cross(b.e, a.s, a.e))) == -2;
}

line_seg_t wall[100];
int cnt_wall;
point_t p[100];
int cnt_p;

graph_c g;

int main()
{
    int n;
    while (scanf("%d", &n), n != -1)
    {
        cnt_wall = 0;
        cnt_p = 2;
        p[0].x = 0.0;
        p[0].y = 5.0;
        p[1].x = 10.0;
        p[1].y = 5.0;
        for (int i = 0; i < n; i++)
        {
            double t1, t2, t3, t4, t5;
            scanf("%lf%lf%lf%lf%lf", &t1, &t2, &t3, &t4, &t5);
            point_t pp;
            pp.x = t1;
            pp.y = t2;
            p[cnt_p++] = pp;
            pp.y = t3;
            p[cnt_p++] = pp;
            pp.y = t4;
            p[cnt_p++] = pp;
            pp.y = t5;
            p[cnt_p++] = pp;

            line_seg_t t;
            t.s.x = t1;
            t.s.y = 0.0;
            t.e.x = t1;
            t.e.y = t2;
            wall[cnt_wall++] = t;

            t.s.x = t1;
            t.s.y = t3;
            t.e.x = t1;
            t.e.y = t4;
            wall[cnt_wall++] = t;

            t.s.x = t1;
            t.s.y = t5;
            t.e.x = t1;
            t.e.y = 10.0;
            wall[cnt_wall++] = t;
        }
        g.init(cnt_p);
        for (int i = 0; i < cnt_p; i++)
            for (int j = i + 1; j < cnt_p; j++)
            {
                line_seg_t ls;
                ls.s = p[i];
                ls.e = p[j];
                int flag = 1;
                for (int k = 0; k < cnt_wall && flag; k++)
                    if (seg_intersect(ls, wall[k])) flag = 0;
                if (flag)
                {
                    g.add_edge(i, j, dist(p[i], p[j]));
                    g.add_edge(j, i, dist(p[i], p[j]));
                }
            }
        g.dijkstra(0);
        printf("%.2lf\n", g.dist[1]);
    }
    return 0;
}