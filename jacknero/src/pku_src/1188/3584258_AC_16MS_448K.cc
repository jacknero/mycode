#include <iostream>
using namespace std;
struct Pot {
	int x,y,z;
}L,R,C;
int main() {
	int N,x,y,z,len;
	while(cin >> N,N!=0) {
		L.x = L.y = L.z = len = 0;
		cin >> L.x >> L.y >> L.z >> len;
		R.x = L.x + len;
		R.y = L.y + len;
		R.z = L.z + len;
		N--;
		bool flag = 1;
		while(N--) {
			C.x = C.y = C.z = len = 0;
			cin >> C.x >> C.y >> C.z >> len;
			if(C.x>=R.x||C.y>=R.y||C.z>=R.z)	{	flag = 0;break;}
			if(C.x+len<=L.x||C.y+len<=L.y||C.z+len<=L.z)	{flag =  0;break;}
			if(C.x>L.x)	L.x = C.x;
			if(C.y>L.y)	L.y = C.y;
			if(C.z>L.z)	L.z = C.z;
			if(C.x+len<R.x)	R.x = C.x+len;	
			if(C.y+len<R.y)	R.y = C.y+len;
			if(C.z+len<R.z)	R.z = C.z+len;
		}
		while(N>0)	{N--;cin >> C.x >> C.y >> C.z >> len;}
		if(flag == 0)	{cout << 0 << endl; continue;}
		cout << (R.x-L.x)*(R.y-L.y)*(R.z-L.z) << endl;
	}
	return 0;
}
