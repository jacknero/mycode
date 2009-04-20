#include <iostream>

class Test{
  public:
  int m_num;

Test();
void printNum();
};

Test::Test()
{
  m_num=0;
}

void Test::printNum(){
  
  std::cout << m_num << std::endl;
  m_num +=1;
}


int main()
{
  Test a, b, c;
  a.printNum();
  a.printNum();
  b.printNum();
  c.printNum();

  return 0;
}
