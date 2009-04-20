#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const double r = 3950;
const double R = 432000;
const double D = 92900000;
const double pi = acos(-1.0);
const double L = sqrt(D * D + R * R - r * r);
const double theta1 = atan(R / D);
const double theta2 = atan(L / r);
const double beta1 = theta1 + theta2;

double beta_t(double t)
{
    return beta1 - 2 * pi * t / 24.0 / 3600.0;
}

int main()
{
    double t;
    while (scanf("%lf", &t) != EOF)
    {
        double beta = beta_t(t);
        double d = (D * cos(beta) - r) / sin(beta);
        double angle;
        if (d <= -R)
            angle = - pi * 0.5;
        else if(d > -R  && d < R)
            angle = asin(d / R);
        else
            angle = pi * 0.5;
        printf("%lf\n", 0.5 + angle / pi + d * cos(angle) / pi / R);
    }
    return 0;
}