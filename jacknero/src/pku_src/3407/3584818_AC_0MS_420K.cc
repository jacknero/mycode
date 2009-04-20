#include <iostream>
#include <cmath>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long int64;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const double pi = acos(-1.0);

int main()
{
    double theta, phi, theta_m, phi_m;
    double theta1, phi1, theta2, phi2;
    char s1[10], s2[10];
    while (scanf("%lf%lf%s%lf%lf%s", &theta, &theta_m, s1, &phi, &phi_m, s2) != EOF)
    {
        theta += theta_m / 60;
        phi += phi_m / 60;
        if (strcmp(s1, "N") == 0)
            theta1 = 90 - theta;
        else
            theta1 = 90 + theta;
        if (strcmp(s2, "E") == 0)
            phi1 = phi;
        else
            phi1 = 360 - phi;
        scanf("%lf%lf%s%lf%lf%s", &theta, &theta_m, s1, &phi, &phi_m, s2);
        theta += theta_m / 60;
        phi += phi_m / 60;
        
        if (strcmp(s1, "N") == 0)
            theta2 = 90 - theta;
        else
            theta2 = 90 + theta;
        if (strcmp(s2, "E") == 0)
            phi2 = phi;
        else
            phi2 = 360 - phi;

        theta1 = theta1 * pi / 180;
        theta2 = theta2 * pi / 180;
        phi1 = phi1 * pi / 180;
        phi2 = phi2 * pi / 180;

        double p = 6370.0;
        double x1, y1, z1, x2, y2, z2;
        x1 = p * sin(theta1) * cos(phi1);
        y1 = p * sin(theta1) * sin(phi1);
        z1 = p * cos(theta1);

        x2 = p * sin(theta2) * cos(phi2);
        y2 = p * sin(theta2) * sin(phi2);
        z2 = p * cos(theta2);
        
        double alpha = acos((x1 * x2 + y1 * y2 + z1 * z2) / ((sqrt(x1 * x1 + y1 * y1 + z1 * z1)) * (sqrt(x2 * x2 + y2 * y2 + z2 * z2))));
        printf("%.3lf\n", alpha * p);
    }
    return 0;
}