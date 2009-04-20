#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
 
#define w(a,b) W[mm[a]][mm[b]]
 
int W[5][5] = {
        { 5, -1, -2, -1, -3 },
        {-1,  5, -3, -2, -4 },
        {-2, -3,  5, -2, -2 },
        {-1, -2, -2,  5, -1 },
        {-3, -4, -2, -1, -9999 }};
 
int main()
{
        int T;
        int l1,l2, i,j;
        string s1,s2;
        map<char,int> mm;
        int table[110][110];
 
        mm['A']=0; mm['C']=1; mm['G']=2; mm['T']=3; mm['-']=4;
        table[0][0]=0;
 
        cin >> T;
        while(T--) {
                cin >> l1 >> s1 >> l2 >> s2;
                s1 = " " + s1; s2 = " " + s2;
 
                for(i=1;i<=l1;i++) table[i][0] = table[i-1][0]+w(s1[i-1],'-');
                for(i=1;i<=l2;i++) table[0][i] = table[0][i-1]+w(s2[i-1],'-');
 
                for(i=1;i<=l1;i++) {
                        for(j=1;j<=l2;j++) {
                                table[i][j] = max(table[i][j-1]+w(s2[j],'-'),
                                        max(table[i-1][j]+w(s1[i],'-'),
                                        table[i-1][j-1]+w(s1[i],s2[j])));
                        }
                }
 
                cout << table[l1][l2] << endl;
        }
        return 0;
}

