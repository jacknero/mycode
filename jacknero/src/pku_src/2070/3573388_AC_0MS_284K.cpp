#include <iostream>
using namespace std;
 
int main()
{
	double speed;
	int weight, strength;
	bool flag;
 
	for(;;) {
		cin >> speed >> weight >> strength;
		if(weight==0 && strength==0) break;
 
		flag=false;
		if(speed<=4.5 && weight>=150 && strength>=200) {
			cout << "Wide Receiver ";
			flag=true;
		}
		if(speed<=6.0 && weight>=300 && strength>=500) {
			cout << "Lineman ";
			flag=true;
		}
		if(speed<=5.0 && weight>=200 && strength>=300) {
			cout << "Quarterback ";
			flag=true;
		}
 
		if(flag==false) cout << "No positions";
		cout << endl;
	}
 
	return 0;
}

