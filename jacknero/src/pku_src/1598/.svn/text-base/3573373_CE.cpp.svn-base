#include <cctype>
using namespace std;
 
int main()
{
        int n,m, mmax;
        int i, cnt[20], T;
        string excuses[20], t;
        set<string> word;
 
        for(T=1;scanf("%d %d", &n,&m)==2;T++) {
                word.clear();
                for(i=0;i<n;i++) { cin >> t; word.insert(t); } getline(cin, t);
                for(i=0;i<m;i++)  { cnt[i]=0; getline(cin, excuses[i]); }
 
                mmax = 0;
                string tmp;
                for(i=0;i<m;i++) {
                        tmp = excuses[i];
                        for(int j=tmp.size()-1;j>=0;j--) {
                                if(isalpha(tmp[j])) tmp[j]=tolower(tmp[j]);
                                else if(!isdigit(tmp[j])) tmp[j]=' ';
                        }
 
                        istringstream sin(tmp);
                        while(sin >> t) {
                                if(word.find(t) != word.end()) cnt[i]++;
                        }
                        mmax = max(mmax, cnt[i]);
                }
 
                cout << "Excuse Set #" << T << endl;
                for(i=0;i<m;i++) if(cnt[i]==mmax) cout << excuses[i] << endl;
                cout << endl;
        }
 
        return 0;
}

