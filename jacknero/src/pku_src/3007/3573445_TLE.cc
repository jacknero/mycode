#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
 
int main()
{
        int N,i;
        string s,a,b;
 
        cin >> N;
        while(N--) {
                set<string> ss;
 
                cin >> s;
                for(i=s.size()-1;i>0;i--) {
                        a = s.substr(0,i);
                        b = s.substr(i);
                        ss.insert(a+b);
                        ss.insert(b+a);
                        reverse(a.begin(), a.end());
                        ss.insert(a+b);
                        ss.insert(b+a);
                        reverse(a.begin(), a.end());
                        reverse(b.begin(), b.end());
                        ss.insert(a+b);
                        ss.insert(b+a);
                        reverse(a.begin(), a.end());
                        ss.insert(a+b);
                        ss.insert(b+a);
                }
 
                cout << ss.size() << endl;
        }
 
        return 0;
}

