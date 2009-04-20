#include <iostream>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const int dx[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
const int dy[10] = {0, -1, -1, -1, 0, 0, 0, 1, 1, 1};

char s[1000010];

int main()
{
    int ca;
    for (scanf("%d", &ca); ca--;)
    {
        scanf("%s", s);
        long long x = 0, y = 0, px = 0, py = 0, area = 0;
        for (int i = 0; s[i] != '5'; i++)
        {
            x += dx[s[i] - '0'];
            y += dy[s[i] - '0'];
            area += x * py - y * px;
            px = x;
            py = y;
        }
        if (area < 0) area = -area;
        if (area % 2) printf("%I64d.5\n", area / 2);
        else printf("%I64d\n", area / 2);
    }
    return 0;
}