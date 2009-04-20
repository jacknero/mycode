#include <iostream>
#include <vector>

using namespace std;

int R,C,r,c;
bool Find = false;
bool A[21][21], B[21][21];
vector<int> Sub(21);


bool Check(int J)
{
    int k = 1;
    for(int i = J+1; i < C; i++)
    {
        bool BB = true;
        for(int j = 0; j < r; j++)
        {
            if(A[j][k] != B[Sub[j]][i])
            {
                BB = false;
                break;
            }
        }

        if(BB)
        {
            k++;
            if(k==c) return true;
        }
    }
    return false;
}

void Getsubs(int j, int k, int t)
{
    if(k == r)
    {
        if(c == 1) {Find = true;return ;}
        if(Check(j))
        {
            Find = true;
        }
    }

    for(int i = t; i < R && !Find; i++)
    {
        if(B[i][j] == A[k][0] && !Find)
        {
            Sub[k] = i;
            Getsubs(j, k+1, i+1);
        }
    }
}

void Solve()
{
    for(int i = 0; i <= C-c && !Find; i++)
    {
        Getsubs(i, 0, 0);
        if(Find) cout << "Yes" << endl;
    }
    if(!Find) cout << "No" << endl;
}

int main()
{
    char ch;
    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> ch;
            if(ch == '1') A[i][j] = true;
            else A[i][j] = false;
        }
    }

    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> ch;
            if(ch == '1') B[i][j] = true;
            else B[i][j] = false;
        }
    }

    Solve();
    //system("pause");
    return 0;
}