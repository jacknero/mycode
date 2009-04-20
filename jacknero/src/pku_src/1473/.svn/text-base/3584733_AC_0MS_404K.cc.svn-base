#include <iostream>
#include <cmath>
using namespace std;

#define out(x) (cout << #x << ": " << x << endl)
typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }

const double dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const double dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double inv_sqrt2 = 1.0 / sqrt(2.0);
const double p[] = {1, inv_sqrt2, 1, inv_sqrt2, 1, inv_sqrt2, 1, inv_sqrt2};
const char name[8][5] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

int main()
{
    double x = 0.0, y = 0.0;
    int ca = 1;
    while (1)
    {
        char s[100];
        scanf("%[0-9NEWSD]", s);
        if (strcmp(s, "END") == 0)
            break;
        char ch;
        scanf("%c", &ch);
        double len = 0;
        int i;
        for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
            len = len * 10 + (s[i] - '0');
        for (int j = 0; j < 8; j++)
            if (strcmp(s + i, name[j]) == 0)
            {
                x += len * dx[j] * p[j];
                y += len * dy[j] * p[j];
            }
        if (ch == '.')
        {
            printf("Map #%d\n", ca++);
            printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
            printf("The distance to the treasure is %.3lf.\n\n", sqrt(x * x + y * y));
            x = y = 0.0;
            scanf("\n");
        }        
    }
    return 0;
}