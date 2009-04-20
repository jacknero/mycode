#include <iostream>
#include <cmath>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const int maxn = 110;
const double eps = 1e-3;
const double pi = acos(-1.0);

typedef struct point_t
{
    double x, y;
};

int n1, n2;
point_t p1[maxn], p2[maxn], p[maxn];

int dcmp(double x)
{
    if (-eps < x && x  < eps)
        return 0;
    if (x > 0)
        return 1;
    return -1;
}

double dist2(const point_t &a, const point_t &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double cross(const point_t &a, const point_t &b)
{
    return a.x * b.y - a.y * b.x;
}

double cross(const point_t &a1, const point_t &a2, const point_t &b1, const point_t &b2)
{
    point_t a, b;
    a.x = a2.x - a1.x;
    a.y = a2.y - a1.y;
    b.x = b2.x - b1.x;
    b.y = b2.y - b1.y;
    return cross(a, b);
}

double angle(const point_t &a, const point_t &b)
{
    double ret = acos((a.x * b.x + a.y * b.y) / (sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y)));
    double flag = a.x * b.y - a.y * b.x;
    if (flag > 0)
        return ret;
    else
        return -ret;
}

double angle(const point_t &a1, const point_t &a2, const point_t &b1, const point_t &b2)
{
    point_t a, b;
    a.x = a2.x - a1.x;
    a.y = a2.y - a1.y;
    b.x = b2.x - b1.x;
    b.y = b2.y - b1.y;
    return angle(a, b);
}

int main()
{
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
        scanf("%lf%lf", &p1[i].x, &p1[i].y);

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
        scanf("%lf%lf", &p2[n2 - i - 1].x, &p2[n2 - i - 1].y);

    int flag = 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            int k = 0;
            while (1)
            {
                if (dcmp(dist2(p1[(i + k) % n1], p1[(i + k + 1) % n1]) - dist2(p2[(j + k) % n2], p2[(j + k + 1) % n2])) != 0)
                    break;
                if (k > 0)
                    if (dcmp(angle(p1[(i + k - 1) % n1], p1[(i + k) % n1], p1[(i + k) % n1], p1[(i + k + 1) % n1])
                           - angle(p2[(j + k - 1) % n2], p2[(j + k) % n2], p2[(j + k) % n2], p2[(j + k + 1) % n2])) != 0)
                        break;
                k++;
            }
            if (k == 0)
                continue;
            if (angle(p1[(n1 + i - 1) % n1], p1[i], p1[i], p1[(i + 1) % n1])
              + angle(p2[(n2 + j - 1) % n2], p2[j], p2[j], p2[(j + 1) % n2]) > pi + eps)
                continue;

            if (angle(p1[(n1 + i - 1) % n1], p1[i], p1[i], p1[(i + 1) % n1])
              + angle(p2[(n2 + j - 1) % n2], p2[j], p2[j], p2[(j + 1) % n2]) < -eps)
                continue;            
            
            if (angle(p1[(i + k - 1) % n1], p1[(i + k) % n1], p1[(i + k) % n1], p1[(i + k + 1) % n1])
              + angle(p2[(j + k - 1) % n2], p2[(j + k) % n2], p2[(j + k) % n2], p2[(j + k + 1) % n2]) > pi + eps)
                continue;

            if (angle(p1[(i + k - 1) % n1], p1[(i + k) % n1], p1[(i + k) % n1], p1[(i + k + 1) % n1])
              + angle(p2[(j + k - 1) % n2], p2[(j + k) % n2], p2[(j + k) % n2], p2[(j + k + 1) % n2]) < -eps)
                continue;
            
            
            int now1 = (i + k) % n1, now2 = (now1 + 1) % n1, now3 = (now2 + 1) % n1;
            int flag = 1;
            while (now2 != i)
            {
                if (cross(p1[now1], p1[now2], p1[now2], p1[now3]) < 0)
                {
                    flag = 0;
                    break;
                }
                now1 = now2;
                now2 = now3;
                now3 = (now3 + 1) % n1;
            }
            if (flag == 0)
                continue;

            now1 = (j + k) % n2, now2 = (now1 + 1) % n2, now3 = (now2 + 1) % n2;
            flag = 1;
            while (now2 != j)
            {
                if (cross(p2[now1], p2[now2], p2[now2], p2[now3]) > 0)
                {
                    flag = 0;
                    break;
                }
                now1 = now2;
                now2 = now3;
                now3 = (now3 + 1) % n2;
            }
            if (flag == 0)
                continue;
            
            printf("1\n");
            return 0;
        }
    printf("0\n");
    return 0;
}