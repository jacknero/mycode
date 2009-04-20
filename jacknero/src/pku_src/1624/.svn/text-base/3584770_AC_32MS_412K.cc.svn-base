#include <iostream>
#include <cmath>
using namespace std;
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
const double eps = 1E-9;
const double pi = acos(-1.0);
const double inf = 1E200;
#define out(x) (cout<<#x<<": "<<x<<endl)
template <class T> void show(T a, int n) {for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl;}
template <class T> void show(T a, int r, int l) {for (int i = 0; i < r; ++i) show(a[i],l); cout << endl;}

/**//********************
    基本几何结构
        点
        线段
        直线
        多边形
        圆
********************/

// 点, 同时也可以看成向量
struct point_t
{
    double x, y;
    point_t(double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
};

// 线段
struct lineseg_t
{
    point_t s, e;
    lineseg_t()
    {
    }
    lineseg_t(point_t a, point_t b)
    {
        s = a;
        e = b;
    }
};

// 直线
// 解析方程 ax + by + c = 0 为统一表示，约定 a >= 0
struct line_t
{
    double a, b, c;
    line_t(double d1 = 1, double d2 = -1, double d3 = 0)
    {
        a = d1;
        b = d2;
        c = d3;
    }
};

// 这里定义多边形的最大点数
const int max_polygon_size = 1000;

// 多边形, 规定逆时针为正方向
struct polygon_t
{
    int n;
    point_t p[max_polygon_size];
};

// 圆
struct circle_t
{
    point_t center;
    double r;
};

/**//********************
    常用小函数与算符
        浮点数比较
        平方
        点到原点距离
        两点距离
        两点重合
********************/

// 浮点数与0比较. x == 0 返回 0, x > 0 返回 1, x < 0 返回 -1
int dcmp(double x)
{
    if (-eps < x && x < eps)
        return 0;
    else if (x > 0)
        return 1;
    else
        return -1;
}

// 判断两个点是否重合
bool operator ==(const point_t &a, const point_t &b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

bool operator !=(const point_t &a, const point_t &b)
{
    return !(a == b);
}

// 向量加法
point_t operator +(const point_t &a, const point_t &b)
{
    point_t ret(a.x + b.x, a.y + b.y);
    return ret;
}

// 向量减法
point_t operator -(const point_t &a, const point_t &b)
{
    point_t ret(a.x - b.x, a.y - b.y);
    return ret;
}

// 平方
inline double sqr(double x)
{
    return x * x;
}

// 点到原点距离
double dist(const point_t &p)
{
    return sqrt(sqr(p.x) + sqr(p.y));
}

// 两点距离
double dist(const point_t &a, const point_t &b)
{
    return sqrt(dist(a - b));
} 

/**//********************\ 
* * 
* 点的基本运算 * 
* * 
\********************/ 


/**//****************************************************************************** 
r=multiply(sp,ep,op),得到(sp-op)*(ep-op)的叉积 
r>0:ep在矢量opsp的逆时针方向； 
r=0：opspep三点共线； 
r<0:ep在矢量opsp的顺时针方向 
*******************************************************************************/ 

double cross_mul(const point_t &a, const point_t &b)
{
    return a.x * b.y - a.y * b.x;
}

double dot_mul(const point_t &a, const point_t &b)
{
    return a.x * b.x + a.y * b.y;
}

double cross_mul(const point_t &a, const point_t &b, const point_t &c)
{
    return cross_mul(a - c, b - c);
}

/**//******************************************************************************* 
r=dotmultiply(p1,p2,op),得到矢量(p1-op)和(p2-op)的点积，如果两个矢量都非零矢量 
r<0:两矢量夹角为锐角；r=0：两矢量夹角为直角；r>0:两矢量夹角为钝角 
*******************************************************************************/ 
double dot_mul(const point_t &a, const point_t &b, const point_t &c)
{
    return dot_mul(a - c, b - c);
}

// 判断点p是否在线段l上
// 条件：p在线段l所在的直线上 && 点p在以线段l为对角线的矩形内
bool online(const lineseg_t l, const point_t p)
{
    return dcmp(cross_mul(l.e, p, l.s)) == 0 && (p.x - l.s.x) * (p.x - l.e.x) <= 0 && (p.y - l.s.y) * (p.y - l.e.y) <= 0;
}

// 返回点p以点o为圆心逆时针旋转alpha(单位：弧度)后所在的位置
point_t rotate(const point_t &o, double alpha, point_t p) 
{
    point_t ret;
    p.x -= o.x;
    p.y -= o.y;
    ret.x = p.x * cos(alpha) - p.y * sin(alpha) + o.x;
    ret.y = p.y * cos(alpha) + p.x * sin(alpha) + o.y;
    return ret;
}

// 返回向量a按逆时针方向,旋转到向量b的角度
// 角度小于pi，返回正值
// 角度大于pi，返回负值
double angle(const point_t &a, const point_t &b)
{
    double ret = acos(dot_mul(a, b) / (dist(a) * dist(b)));
    if (cross_mul(a, b) < 0)
        return ret;
    else
        return -ret;
}

// 返回顶角在o点,起始边为os,终止边为oe的夹角(单位:弧度),规定逆时针为正方向
// 角度小于pi，返回正值
// 角度大于pi，返回负值
// 可以用于求线段之间的夹角
double angle(const point_t &o, const point_t &s, const point_t &e)
{
    return angle(s - o, e - o);
}

// 线段及直线的基本运算

/**//* 判断点与线段的关系,用途很广泛
本函数是根据下面的公式写的,P是点C到线段AB所在直线的垂足

    AC dot AB
r = ---------
    ||AB||^2
    (Cx-Ax)(Bx-Ax) + (Cy-Ay)(By-Ay)
  = -------------------------------
                  L^2

r has the following meaning:

r=0    P = A
r=1    P = B
r<0    P is on the backward extension of AB
r>1    P is on the forward extension of AB
0<r<1  P is interior to AB

*/

double relation(const point_t &p, const lineseg_t &l)
{
    return dot_mul(p, l.e, l.s) / (dist(l.s, l.e) * dist(l.s, l.e));
}

// 求点p到线段l所在直线的垂足
point_t foot(const point_t &p, const lineseg_t &l)
{
    double r = relation(p, l);
    point_t ret;
    ret.x = l.s.x + r * (l.e.x - l.s.x);
    ret.y = l.s.y + r * (l.e.y - l.s.y);
    return ret;
}

// 求点p到线段l的最短距离,并返回线段上距该点最近的点ret
// 注意: ret是线段l上到点p最近的点,不一定是垂足
double dist(const point_t p, const lineseg_t &l, point_t &ret)
{
    double r = relation(p,l);
    if (r < 0)
        ret = l.s;
    else if (r > 1)
        ret = l.e;
    else
        ret = foot(p,l);
    return dist(p, ret);
}

// 求点p到线段l所在直线的距离,请注意本函数与上个函数的区别
double dist(const point_t p, const lineseg_t l)
{
    return abs(cross_mul(p, l.e, l.s)) / dist(l.s, l.e);
}

// 计算点到折线集的最近距离,并返回最近点
double dist(int cnt_v, point_t point_set[], const point_t &p, point_t &ret_p)
{
    double ret = inf;
    for (int i = 0; i < cnt_v - 1; i++)
    {
        lineseg_t l(point_set[i], point_set[i + 1]);
        point_t tmp_p;
        double tmp = dist(p, l, tmp_p);
        if (tmp < ret)
        {
            ret = tmp;
            ret_p = tmp_p;
        }
    }
    return ret;
}

// 判断圆是否在多边形内
bool inside(const circle_t c, int cnt_v, point_t poly[])
{
    point_t q;
    double d = dist(cnt_v, poly, c.center, q);
    return d < c.r || fabs(d - c.r) < eps;
}

// 如果线段a和b相交(包括相交在端点处)时返回true
bool intersect_e(const lineseg_t &a, const lineseg_t &b)
{
    return
        //排斥实验
        max(a.s.x, a.e.x) >= min(b.s.x, b.e.x) &&
        max(b.s.x, b.e.x) >= min(a.s.x, a.e.x) &&
        max(a.s.y, a.e.y) >= min(b.s.y, b.e.y) &&
        max(b.s.y, b.e.y) >= min(a.s.y, a.e.y) &&
        //跨立实验
        cross_mul(b.s, a.e, a.s) * cross_mul(a.e, b.e, a.s) >= 0 &&
        cross_mul(a.s, b.e, b.s) * cross_mul(b.e, a.e, b.s) >= 0;
}

// 线段a和b相交 && 交点不是双方的端点时返回true
bool intersect_ne(const lineseg_t &a, const lineseg_t &b)
{
    return
        intersect_e(a, b) &&
        !online(a, b.s) &&
        !online(a, b.e) &&
        !online(b, a.e) &&
        !online(b, a.s);
}

// 线段l所在直线与线段a相交(包括相交在端点处)时返回true
// 方法:判断线段a是否跨立线段l
bool intersect_l(const lineseg_t &a, const lineseg_t &l)
{
    return cross_mul(a.s, l.e, l.s) * cross_mul(l.e, a.e, l.s) >= 0;
}

// 根据已知两点坐标,求过这两点的直线解析方程: ax + by + c = 0 (a >= 0)
// 若两点不重合,返回true,否则返回false
bool make_line(const point_t &a, const point_t &b, line_t &ret)
{
    int sign = 1;
    ret.a = b.y - a.y;
    if (dcmp(ret.a) == 0 && dcmp(b.x - a.x) == 0)
        return false;
    if (dcmp(ret.a) == 0)
    {
        ret.a = 0;
        ret.b = 1;
        ret.c = -a.y;
        return true;
    }
    if (ret.a < 0)
    {
        sign = -1;
        ret.a = -ret.a;
    }
    ret.b = sign * (a.x - b.x);
    ret.c = sign * (a.y * b.x - a.x * b.y);
    return true;
}

// 根据直线解析方程返回直线的斜率k,水平线返回0,竖直线返回inf
double slope(const line_t &l)
{
    if (dcmp(l.a) == 0)
        return 0;
    if (dcmp(l.b) == 0)
        return inf;
    return -(l.a / l.b);
}

// 返回直线的倾斜角alpha (0 - pi)
double alpha(const line_t &l)
{
    if (dcmp(l.a) == 0)
        return 0;
    if (dcmp(l.b) == 0)
        return pi / 2;
    double k = slope(l);
    return k > 0 ? atan(k) : pi + atan(k);
}

// 求点p关于直线l的对称点 
point_t symmetry(const line_t &l, const point_t &p)
{
    point_t ret;
    double sla = sqr(l.a), slb = sqr(l.b);
    ret.x = ((slb - sla) * p.x - 2 * l.a * l.b * p.y - 2 * l.a * l.c) / (sla + slb);
    ret.y = ((sla - slb) * p.y - 2 * l.a * l.b * p.x - 2 * l.b * l.c) / (sla + slb);
    return ret;
}

// 如果两条直线 l1(a1x + b1y + c1 = 0), l2(a2x + b2y + c2 = 0)相交, 返回true, 且返回交点p
bool intersect(const line_t &l1, const line_t &l2, point_t &p)
{
    double d = l1.a * l2.b - l2.a * l1.b;
    if (dcmp(d) == 0)
        return false;
    p.x = (l2.c * l1.b - l1.c * l2.b) / d;
    p.y = (l2.a * l1.c - l1.a * l2.c) / d;
    return true;
}

// 如果线段l1和l2相交，返回true且交点由(inter)返回，否则返回false 
bool intersect(const lineseg_t &l1, const lineseg_t &l2, point_t &ret) 
{
    line_t t1, t2;
    if (!make_line(l1.s, l1.e, t1))
        return false;
    if (!make_line(l2.s, l2.e, t2))
        return false;
    if (intersect(t1, t2, ret))
        return online(l1, ret) && online(l2, ret);
    else
        return false;
}
//点到直线距离
double dist(const point_t &a, const line_t &b)
{
    return abs(b.a * a.x + b.b * a.y + b.c) / sqrt(sqr(b.a) + sqr(b.b));
}

const int size[] =
{
    3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};

const int poly[18][4] =
{
    {0, 1, 7},
    {1, 2, 3},
    {3, 4, 5},
    {5, 6, 7},
    {1, 2, 4, 5},
    {0, 2, 3, 7},
    {0, 2, 3},
    {0, 2, 4},
    {0, 2, 5},
    {2, 4, 5},
    {2, 4, 6},
    {2, 7, 0},
    {4, 6, 7},
    {4, 6, 0},
    {4, 1, 2},
    {6, 0, 1},
    {6, 0, 2},
    {6, 3, 4},
};

point_t p[8];

int main()
{
    int t1, t2, t3, t4, t5, t6, t7, t8;
    int ca = 1;
    while (scanf("%d%d%d%d%d%d%d%d", &t1, &t2, &t3, &t4, &t5, &t6, &t7, &t8),
        t1 != 0 || t2 != 0 || t3 != 0 || t4 != 0 || t5 != 0 || t6 != 0 || t7 != 0 || t8 != 0)
    {
        p[0].x = t1;
        p[0].y = t2;
        p[2].x = t3;
        p[2].y = t4;
        p[4].x = t5;
        p[4].y = t6;
        p[6].x = t7;
        p[6].y = t8;
        p[1].x = (p[0].x + p[2].x) / 2;
        p[1].y = (p[0].y + p[2].y) / 2;
        p[3].x = (p[2].x + p[4].x) / 2;
        p[3].y = (p[2].y + p[4].y) / 2;
        p[5].x = (p[4].x + p[6].x) / 2;
        p[5].y = (p[4].y + p[6].y) / 2;
        p[7].x = (p[6].x + p[0].x) / 2;
        p[7].y = (p[6].y + p[0].y) / 2;
        double area = cross_mul(p[0], p[2]) + cross_mul(p[2], p[4]) + cross_mul(p[4], p[6]) + cross_mul(p[6], p[0]);
        double ans = 1e200, ans_a, ans_b;
        for (int i = 0; i < 18; i++)
        {
            double tmp = 0;
            for (int j = 0; j < size[i]; j++)
                tmp += cross_mul(p[poly[i][j]], p[poly[i][(j + 1) % size[i]]]);
            if (fabs(area - tmp - tmp) < ans)
            {
                ans = fabs(area - tmp - tmp);
                ans_a = tmp;
                ans_b = area - tmp;
            }
        }
        if (ans_a > ans_b)
            swap(ans_a, ans_b);
        printf("Cake %d: %.3lf %.3lf\n", ca++, ans_a / 2, ans_b / 2);
    }

    return 0;
}