#include <iostream>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int ax, ay, bx, by, cx, cy;
    while (scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy), !(ax == 0 && ay == 0 && bx == 0 && by == 0 && cx == 0 && cy == 0))
    {
        int tax = bx - cx, tay = by - cy;
        int tbx = cx - ax, tby = cy - ay;
        int tcx = ax - bx, tcy = ay - by;
        int b = gcd(abs(tcx), abs(tcy)) + gcd(abs(tax), abs(tay)) + gcd(abs(tbx), abs(tby));
        int a = abs(tax * tby - tay * tbx);
        printf("%d\n", (a + 2 - b) / 2);
    }
    return 0;
}