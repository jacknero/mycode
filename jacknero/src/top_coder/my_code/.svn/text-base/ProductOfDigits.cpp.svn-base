// BEGIN CUT HERE
#if 0
// PROBLEM STATEMENT
// You are given an int N.  Find the smallest positive integer X such that the product of its digits (in decimal notation) is equal to N.  Return the number of digits in X, or return -1 if such a number does not exist.

DEFINITION
Class:ProductOfDigits
Method:smallestNumber
Parameters:int
  Returns:int
Method signature:int smallestNumber(int N)


  CONSTRAINTS
  -N will be between 1 and 1,000,000,000, inclusive.


  EXAMPLES

  0)
  1

  Returns: 1

  Just take X = 1. It contains 1 digit.

  1)
  10

  Returns: 2

  Here the smallest possible X is 25.

  2)
  26

  Returns: -1



  3)
  100

  Returns: 3

  The number 455 has 3 digits and the product of its digits is 4 * 5 * 5 = 100.

  4)
  2520

  Returns: 4



  5)
  864

  Returns: 4



#endif // 0
#include <iostream>
#include <sstream>
  // END CUT HERE
#line 67 "ProductOfDigits.cpp"
#include <string>
#include <vector>
  using namespace std;
  class ProductOfDigits {
    public:
      int smallestNumber(int n) {
        vector<int> buf;
        if (n == 1)
          return 1;
        int i=2;
        while(n > 1){
          if(n % i == 0)
          {
            buf.push_back(i);
            n /= i;
          }
          else{
            i++; 
          }
        }
        if(buf.empty())
          return -1;
        vector<int>::iterator it = buf.begin();
        while(it != buf.end()){
          if(*it > 10){
            return -1;
          }          
          ++it;
        }

        return buf.size();
      };


      // BEGIN CUT HERE
    public:
      void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
    private:
      template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
      void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
      void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, smallestNumber(Arg0)); }
      void test_case_1() { int Arg0 = 10; int Arg1 = 2; verify_case(1, Arg1, smallestNumber(Arg0)); }
      void test_case_2() { int Arg0 = 26; int Arg1 = -1; verify_case(2, Arg1, smallestNumber(Arg0)); }
      void test_case_3() { int Arg0 = 100; int Arg1 = 3; verify_case(3, Arg1, smallestNumber(Arg0)); }
      void test_case_4() { int Arg0 = 2520; int Arg1 = 4; verify_case(4, Arg1, smallestNumber(Arg0)); }
      void test_case_5() { int Arg0 = 864; int Arg1 = 4; verify_case(5, Arg1, smallestNumber(Arg0)); }

      // END CUT HERE

  };

// BEGIN CUT HERE
int main() {
  ProductOfDigits ___test;
  ___test.run_test(-1);
}
// END CUT HERE
