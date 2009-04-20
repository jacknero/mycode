#include <iostream>
#include <string>
#include <set>
using namespace std;
 
bool foo(string s)
{
        set<string> ss;
        for(int i=s.size()-2;i>=0;i--) {
                ss.clear();
                for(int j=s.size()-i-2;j>=0;j--) {
                        if(ss.insert(s.substr(j,1)+s[j+i+1]).second==false) return false;
                }
        }
 
        return true;
}
 
int main()
{
        string s;
 
        for(;;) {
                cin >> s;
                if(s[0]=='*') break;
 
                cout << s << " is " << (foo(s) ? "" : "NOT ")
                        << "surprising." << endl;
        }
 
        return 0;
}

