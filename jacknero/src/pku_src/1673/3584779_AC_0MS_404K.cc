#include <iostream>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

double cross(double a, double b, double c, double d)
{
    return a * d - b * c;
}

int main()
{
    double x1, x2, x3, y1, y2, y3;
    double A1, B1, C1, A2, B2, C2;
    int ca;
    for (scanf("%d", &ca); ca--;)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
        A1 = x2 - x3;
        B1 = y2 - y3;
        C1 = x1 * x2 - x1 * x3 + y1 * y2 - y1 * y3;
        A2 = x1 - x3;
        B2 = y1 - y3;
        C2 = x1 * x2 - x2 * x3 + y1 * y2 - y2 * y3;
        printf("%.4lf %.4lf\n", cross(C1, B1, C2, B2) / cross(A1, B1, A2, B2), cross(A1, C1, A2, C2) / cross(A1, B1, A2, B2));
    }
    return 0;
}