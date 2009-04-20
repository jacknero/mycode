#include <iostream>
#include <map>
using namespace std;
 
map<char,char> m;
 
int foo(string s)
{
        int i,j;
        for(i=0,j=s.size()-1;i<=j && s[i]==s[j];i++,j--);
        return i<=j ? 0 : 1;
}
 
int boo(string s)
{
        int i,j;
        for(i=0,j=s.size()-1;i<=j && m[s[i]]==s[j];i++,j--);
        return i<=j ? 0 : 2;
}
 
int main()
{
        string s;
        m['A']='A'; m['E']='3'; m['H']='H'; m['i']='i'; m['J']='L'; m['L']='J';
        m['M']='M'; m['O']='O'; m['S']='2'; m['T']='T'; m['U']='U'; m['V']='V';
        m['W']='W'; m['X']='X'; m['Y']='Y'; m['Z']='5'; m['1']='1'; m['2']='S';
        m['3']='E'; m['5']='Z'; m['8']='8';
 
        while(cin >> s) {
                cout << s << " -- ";
                switch(foo(s) | boo(s)) {
                        case 0: cout << "is not a palindrome." << endl; break;
                        case 1: cout << "is a palindrome." << endl; break;
                        case 2: cout << "is a mirrored string." << endl; break;
                        case 3: cout << "is a mirrored palindrome." << endl; break;
                }
                cout << endl;
        }
 
        return 0;
}

