#include <iostream>
using namespace std;

long n[6];
long sum;
const long MAX_N = 60000;

int dividable()
{
    int f[MAX_N];
    for (int i = 0; i <= sum; i++)
        f[i] = 0;
    f[0] = 1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            int base = j * (i + 1);
            if (base > sum) break;
            for (int k = sum - (i+1); k >= base - i - 1; k--)
                if (f[k])
                    f[k + i + 1] = 1;
            if (f[sum]) return 1;
        }
    }
    return f[sum];
}

int main()
{
    long cases = 0;
    while (true)
    {
        sum = 0;
        for (long i = 0; i < 6; i++)
        {
            cin >> n[i];
        }
        if (n[5] > 5) n[5] = 4 + n[5] % 2;
        if (n[4] > 6) n[4] = 6 - n[4] % 2;
        if (n[3] > 5) n[3] = 4 + n[3] % 2;
        if (n[2] > 5) n[2] = 4 + n[2] % 2;
        if (n[1] > 4) n[1] = 4 - n[1] % 2;
        for (long i = 0; i < 6; i++)
        {
            sum += n[i] * (i + 1);
        }
        if (sum == 0)
            break;
        cases++;
        cout << "Collection #" << cases << ":\n";
        if (sum % 2 != 0)
        {
            cout << "Can't be divided.\n\n";
            continue;
        }
        sum /= 2;
        if (dividable())
            cout << "Can be divided.\n";
        else
            cout << "Can't be divided.\n";
        cout << endl;
    }
    return 0;
}