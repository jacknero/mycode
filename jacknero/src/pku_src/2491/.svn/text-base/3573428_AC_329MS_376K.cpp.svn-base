#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
using namespace std;
 
int main()
{
        int C,T,i,N;
        string a,b,start;
 
        cin >> C;
        for(T=1;C--;T++) {
                map<string,string> mm;
                map<string, int> cc;
                set<string> ss;
 
                cin >> N;
                for(i=1;i<N;i++) {
                        cin >> a >> b;
                        cc[a]++; ss.insert(a);
                        cc[b]--; ss.erase(b);
                        mm[a]=b;
                }
 
                printf("Scenario #%d:\n", T);
                start = *ss.begin();
                for(i=1;i<N;i++) {
                        puts(start.c_str());
                        start = mm[start];
                }
                cout << start << "\n" << endl;
        }
 
        return 0;
}

