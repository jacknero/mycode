#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
        string s;
        int n,sz,i,j;
 
        while(cin >> n >> s) {
                vector<string> msg;
                sz = s.size();
                msg.push_back(s);
 
                for(i=1;i<n;i++) {
                        cin >> s;
                        msg.push_back(s);
                }
 
                for(i=sz-1;i>=0;i--) {
                        for(j=n-1;j>=0;j--) {
                                if(msg[j][i]=='_') cout << ' ';
                                else if(msg[j][i]=='\\') cout << '\n';
                                else cout << msg[j][i];
                        }
                }
 
                cout << "\n" << endl;
        }
 
        return 0;
}

