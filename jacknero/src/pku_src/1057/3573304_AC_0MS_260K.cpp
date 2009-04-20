#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
void dir(vector<string> &l, int depth)
{
        string s;
        vector<string> ll;
 
        for(;;) {
                cin >> s;
                if(s[0]==']' || s[0]=='*') break;
                else if(s[0]=='f') l.push_back(s);
                else if(s[0] == 'd') {
                        for(int j=0;j<depth;j++) printf("|     ");
                        printf("|     %s\n", s.c_str());
                        dir(ll, depth+1);
                }
        }
 
        sort(l.begin(), l.end());
        for(int i=0;i<l.size();i++) {
                for(int j=0;j<depth;j++) printf("|     ");
                puts(l[i].c_str());
        }
 
        l.clear();
}
 
int main()
{
        int T,i;
        string s;
 
        for(T=1;;T++) {
                vector<string> l;
 
                cin >> s;
                if(s[0]=='#') break;
 
                printf("DATA SET %d:\n", T);
                puts("ROOT");
                if(s[0]=='f') {
                        l.push_back(s);
                        dir(l,0);
                } else {
                        printf("|     %s\n", s.c_str());
                        dir(l,1);
                }
 
                putchar('\n');
        }
 
        return 0;
}

