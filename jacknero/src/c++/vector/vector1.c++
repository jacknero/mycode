#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v1;

  for(int i = 0; i < 10 ; i++ )
  {
    v1.push_back( i );
  }

  vector<int>::iterator it = v1.begin();
  while( it != v1.end())
  {
    cout <<  *it << endl;
    ++it;
  }

  return 0;
}
  

