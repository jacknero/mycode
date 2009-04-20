#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
 
int main()
{
        int n,i,j, mmax,c,r;
        string s;
 
        while(cin >> n) {
                vector<string> v;
 
                mmax=0;
                for(i=0;i<n;i++) {
                        cin >> s;
                        v.push_back(s);
                        mmax=max(mmax, (int)s.size());
                }
                sort(v.begin(), v.end());
 
 
                puts("----------"
                         "----------"
                         "----------"
                         "----------"
                         "----------"
                         "----------");
                c = 62/(mmax+2);
                r = n/c; if(r*c!=n) r++;
                for(i=0;i<r;i++) {
                        for(j=0;j<c-1;j++) {
                                if(i+j*r < n) printf("%*s", -mmax-2, v[i + j*r].c_str());
                        }
                        if(i+j*r < n) printf("%*s", -mmax-2, v[i + j*r].c_str());
                        puts("");
                }
        }
 
        return 0;
}

