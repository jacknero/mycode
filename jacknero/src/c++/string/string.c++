#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string str( "abcdefghijk" );
  string::size_type index = str.find( "fgh" );  // "fgh"�򸡺�
  if( index == string::npos )  // �����Ǥ������ɤ���
  {
    cout << "�����˼��Ԥ��ޤ���" << endl;
  }
  else
  {
    cout << str.substr( index ) << endl;
  }

  return 0;
}

