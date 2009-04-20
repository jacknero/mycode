#include <map>
#include <iostream>
#include <string>
using namespace std;
const int N  = 5010;
int x[N], y[N];
bool odd[N];
int p[2 * N];
bool prt[2 * N];
int Root(int x, bool & e)
{
int r = x, t = x;
bool res = prt[x];
while(p[r] != r)
{
r = p[r];
res = res ^ prt[r];
}
e = res;
return r;
}
void Union(int a, int b, bool e)
{
p[a] = b;
prt[a] = e;
}
bool chk(int idx)
{
int a = x[idx], b = y[idx];
bool e = odd[idx], ea, eb;
int ra = Root(a, ea), rb = Root(b, eb);
if(ra == rb)
{
if( (ea ^ eb) != e) return false;
}
else
{
Union(ra, rb, (ea ^ eb ^ e) );
}
return true;
}
int main()
{
//    freopen("t.in", "r", stdin);
map<int, int> m;
int l, i, ncmd, a, b, idx;
string s;
cin >> l >> ncmd;
for(i = 0, idx = 0; i < ncmd; ++i)
{
cin >> a >> b >> s;
if(a > b) swap(a, b);
--a;
if(a < 0)
while(1) printf("1");
if(!m.count(a)) m[a] = idx++;
if(!m.count(b)) m[b] = idx++;
x[i] = m[a]; y[i] = m[b];
odd[i] = s[0] == 'o';
}
for(i = 0; i < idx; ++i) { p[i] = i; prt[i] = false; }
for(i = 0; i < ncmd; ++i) {
if(!chk(i))
break;
}
printf("%d\n", i);
return 0;
}
