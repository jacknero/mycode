#include <set>
#include <vector>
#include <utility>
#include <cstdio>
using namespace std;
 
int main()
{
        int C,K,P;
        multiset<pair<int,int> > ss;
        multiset<pair<int,int> >::iterator pos;
        pair<int,int> pp;
 
        for(;;) {
                scanf("%d", &C);
                if(C==0) break;
 
                if(C==1) {
                        scanf("%d %d", &K, &P);
                        ss.insert(make_pair(P,K));
                } else if(C==2) {
                        if(ss.empty()) { puts("0"); continue; }
                        pos = ss.end(); --pos;
                        printf("%d\n", pos->second);
                        ss.erase(pos);
                } else {
                        if(ss.empty()) { puts("0"); continue; }
                        pos = ss.begin();
                        printf("%d\n", pos->second);
                        ss.erase(pos);
                }
        }
 
        return 0;
}

