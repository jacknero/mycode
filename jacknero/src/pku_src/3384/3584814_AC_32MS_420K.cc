#include <iostream>
#include <cmath>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const double eps = 1e-10;
const int maxn = 200;

struct point
{
    double x, y;
};

struct cp
{
    int n;
    point p[maxn];
};

double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point intersectL(double a1, double b1, double c1, double a2, double b2, double c2)
{
    point ret;
    ret.y = (a1 * c2 - c1 * a2) / (b1 * a2 - a1 * b2);
    if (fabs(a2) < eps)
        ret.x = -(b1 * ret.y + c1) / a1;
    else
        ret.x = -(b2 * ret.y + c2) / a2;
    return ret;
}

bool isEqual(point inpA, point inpB)
{
    return (fabs(inpA.x - inpB.x) < eps && fabs(inpA.y - inpB.y) < eps);
}

double Cross(point inpA, point inpB, point inpC)
{
    return (inpB.x - inpA.x) * (inpC.y - inpA.y) - (inpC.x - inpA.x) * (inpB.y - inpA.y);
}

void get_line(point inpA, point inpB, double &a1, double &b1, double &c1)
{
    a1 = inpB.y - inpA.y;
    b1 = inpA.x - inpB.x;
    c1 = inpA.y * (inpB.x - inpA.x) - inpA.x * (inpB.y - inpA.y);
}

cp cut(point inpA, point inpB, cp incp)
{
    cp ret;
    point cross;
    int i, j;
    double t1, t2;
    double a1, b1, c1, a2, b2, c2;
    
    ret.n = 0;
    for (i = 0; i < incp.n; i++)
    {
        j = i + 1;
        t1 = Cross(inpA, inpB, incp.p[i]);
        t2 = Cross(inpA, inpB, incp.p[j]);
        if (t1 < eps && t2 < eps)
        {
            ret.p[ret.n++] = incp.p[i];
            ret.p[ret.n++] = incp.p[j];
        }
        else if (t1 > eps && t2 > eps)
            continue;
        else
        {
            get_line(inpA, inpB, a1, b1, c1);
            get_line(incp.p[i], incp.p[j], a2, b2, c2);
            cross = intersectL(a1, b1, c1, a2, b2, c2);
            if (t1 < eps)
            {
                ret.p[ret.n++] = incp.p[i];
                ret.p[ret.n++] = cross;
            }
            else
            {
                ret.p[ret.n++] = cross;
                ret.p[ret.n++] = incp.p[j];
            }
        }
    }
    if (ret.n == 0)
        return ret;
    for (i = 1, j = 1; i < ret.n; i++)
        if (!isEqual(ret.p[i - 1], ret.p[i]))
            ret.p[j++] = ret.p[i];
    ret.n = j;
    if (ret.n != 1 && isEqual(ret.p[ret.n - 1], ret.p[0]))
        ret.n--;
    ret.p[ret.n] = ret.p[0];
    return ret;
}

int main()
{
    int n, r;
    cp input, ret;
    scanf("%d%d", &n, &r);
    input.n = n;
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &input.p[i].x, &input.p[i].y);
    input.p[n] = input.p[0];
    ret = input;
    for (int i = 0; i < n; i++)
    {
        point ta, tb, tt;
        tt.x = input.p[i + 1].y - input.p[i].y;
        tt.y = input.p[i].x - input.p[i + 1].x;
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        
        ta.x = input.p[i].x + tt.x;
        ta.y = input.p[i].y + tt.y;
        tb.x = input.p[i + 1].x + tt.x;
        tb.y = input.p[i + 1].y + tt.y;
        
        ret = cut(ta, tb, ret);
    }
    double ans = -1;
    double ans_x1, ans_y1, ans_x2, ans_y2;
    for (int i = 0; i < ret.n; i++)
        for (int j = 0; j < ret.n; j++)
        {
            double t = dist(ret.p[i], ret.p[j]);
            if (t > ans)
            {
                ans = t;
                ans_x1 = ret.p[i].x;
                ans_y1 = ret.p[i].y;
                ans_x2 = ret.p[j].x;
                ans_y2 = ret.p[j].y;
            }
        }
    printf("%.4lf %.4lf %.4lf %.4lf\n", ans_x1, ans_y1, ans_x2, ans_y2);
    return 0;
}