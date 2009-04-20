#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

int g, s;

void max_pipes(double w, double h)
{
    if (h < 1 || w < 1)
        return;
    //grid
    int grid = int(w) * int(h);
    //skew
    int skew = 0;
    double now_h = 1.0;
    int flag = 0;
    for (now_h = 1.0 ;now_h < h; now_h += sqrt(3.0) / 2.0)
    {
        if (w >= int(w) + 0.5)
        {
            skew += int(w);
            continue;
        }
        if (flag == 0)
        {
            flag = 1;
            skew += int(w);
        }
        else
        {
            flag = 0;
            skew += int(w) - 1;
        }
    }
    g >?= grid;
    s >?= skew;
}

int main()
{
    double w, h;
    while (scanf("%lf%lf", &w, &h) != EOF)
    {
        g = 0;
        s = 0;
        max_pipes(w, h);
        max_pipes(h, w);
        if (g >= s)
            printf("%d grid\n", g);
        else
            printf("%d skew\n", s);
    }
    return 0;
}