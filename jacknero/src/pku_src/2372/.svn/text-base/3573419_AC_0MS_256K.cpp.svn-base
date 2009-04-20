#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
#define valid_symbol(ch) \
(isdigit(ch) || ch=='=' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || \
ch==')' || ch=='(' || ch=='\n')
 
int main()
{
        string text="", tmp;
        bool flag=true;
        int pos, tpos, sz, b;
 
        while(getline(cin, tmp)) text+=tmp+'\n';
 
        // remove coments
        for(;;) {
                pos = text.find("(*");
                if(pos == string::npos) break;
                tpos = text.find("*)", pos+2);
                if(tpos == string::npos) { flag=false; break; }
                else { text.erase(pos, tpos+2-pos); }
        }
 
        sz = text.size();
        b=0;
        for(pos=0;pos<sz;pos++) {
                if(text[pos]=='(') {
                        b++; pos++;
 
                        for(;pos<sz;pos++) {
                                if(valid_symbol(text[pos])) {
                                        if(text[pos]=='(') b++;
                                        else if(text[pos]==')') {
                                                b--;
                                                if(b==0) break;
                                        }
                                } else {
                                        flag=false; break;
                                }
                        }
                        if(flag==false || pos>=sz) { flag=false; break; }
                } else if(text[pos]==')') {
                        flag=false; break;
                }
        }
 
        cout << (flag ? "YES" : "NO") << endl;
        return 0;
}

