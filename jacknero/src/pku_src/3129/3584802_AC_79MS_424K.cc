#include <iostream> 
#include <cmath> 
using namespace std; 
#define out(x) (cout<<#x<<": "<<x<<endl) 
const int maxint=0x7FFFFFFF; 
typedef long long int64; 
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL; 
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;} 
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;} 

const int maxn = 600; 
const int maxm = 60; 

typedef struct point_t 
{ 
    double x, y, z; 
}; 

double dot(const point_t &a, const point_t &b) 
{ 
    return a.x * b.x + a.y * b.y + a.z * b.z; 
} 

double len2(const point_t &a) 
{ 
    return a.x * a.x + a.y * a.y + a.z * a.z; 
} 

double angle(const point_t &a, const point_t &b) 
{ 
    return abs(acos(dot(a, b) / sqrt(len2(a) * len2(b)))); 
} 

int n, m; 
point_t p[maxn]; 
point_t t[maxm]; 
double w[maxm]; 
int visible[maxn]; 

int main() 
{ 
    while (scanf("%d", &n), n != 0) 
    { 
        for (int i = 0; i < n; i++) 
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z); 
        scanf("%d", &m); 
        for (int i = 0; i < m; i++) 
            scanf("%lf%lf%lf%lf", &t[i].x, &t[i].y, &t[i].z, &w[i]); 
         
        memset(visible, 0, sizeof(visible)); 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (angle(p[i], t[j]) < w[j]) 
                    visible[i] = 1; 
         
        int cnt = 0; 
        for (int i = 0; i < n; i++) 
            if (visible[i]) cnt++; 
        printf("%d\n", cnt); 
    } 
    return 0; 
} 