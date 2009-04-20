#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const double pi = 3.14159265358979323846264338327950288;

double sqr(double x)
{
    return x * x;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

double dequal(double a, double b)
{
    return abs(a - b) < 1e-2;
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6)
    {
        double l1 = hypot(x2 - x3, y2 - y3);
        double l2 = hypot(x1 - x3, y1 - y3);
        double l3 = hypot(x1 - x2, y1 - y2);
        double ll1 = max(max(l1, l2), l3);
        double ll3 = min(min(l1, l2), l3);
        double ll2 = l1 + l2 + l3 - ll1 - ll3;
        l1 = ll1;
        l2 = ll2;
        l3 = ll3;
        if (dequal(l1, l2 + l3))
        {
            printf("Not a Triangle\n");
            continue;
        }
        if (dequal(l1, l3))
            printf("Equilateral ");
        else if (dequal(l1, l2) || dequal(l2, l3))
            printf("Isosceles ");
        else
            printf("Scalene ");

        double a1, a2, a3;
        a1 = acos((sqr(l2) + sqr(l3) - sqr(l1)) / (2 * l2 * l3));
        a2 = acos((sqr(l3) + sqr(l1) - sqr(l2)) / (2 * l3 * l1));
        a3 = acos((sqr(l1) + sqr(l2) - sqr(l3)) / (2 * l1 * l2));
        double am = max(max(a1, a2), a3) * 180 / pi;
        if (am > 88 && am < 92)
            printf("Right\n");
        else if (am > 90)
            printf("Obtuse\n");
        else
            printf("Acute\n");
    }
    printf("End of Output\n");
    return 0;
}