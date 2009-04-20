#include <iostream>
using namespace std;

#define MAX 100
int main(){
  int hoge[1000];
  for(int i = 0; i <MAX; i++){
hoge[i] = i;
  }
  for(int i = 0; i <MAX; i++){
cout << hoge[i]  << endl;
  }
  return 0;
}


