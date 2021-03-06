// BEGIN CUT HERE
#if 0
// PROBLEM STATEMENT
// 
NOTE: This problem statement contains subscripts that may not display properly if viewed outside of the applet.


Let's consider an infinite sequence A defined as follows:

A0 = 1;
Ai = A[i/p] + A[i/q] for all i >= 1, where [x] denotes the floor function of x. (see Notes)


  You will be given n, p and q. Return the n-th element of A (index is 0-based).

  DEFINITION
  Class:InfiniteSequence
  Method:calc
  Parameters:long long, int, int
  Returns:long long
Method signature:long long calc(long long n, int p, int q)


  NOTES
  -[x] denotes the floor function of x which returns the highest integer less than or equal to x. For example, [3.4] = 3, [0.6] = 0.


  CONSTRAINTS
  -n will be between 0 and 10^12, inclusive.
  -p and q will both be between 2 and 10^9, inclusive.


  EXAMPLES

  0)
  0
  2
  3

  Returns: 1

  A[0] = 1.

  1)
  7
  2
  3

  Returns: 7

  A[0] = 1;
  A[1] = A[0] + A[0] = 2;
  A[2] = A[1] + A[0] = 2 + 1 = 3;
  A[3] = A[2] + A[1] = 3 + 2 = 5;
  A[7] = A[3] + A[2] = 5 + 3 = 8.

  2)
  10000000
  3
  3

  Returns: 32768



  3)
  256
  2
  4

  Returns: 89



  4)
  1
  1000000
  1000000

  Returns: 2



#endif // 0
#include <iostream>
#include <sstream>
  // END CUT HERE
#line 89 "InfiniteSequence.cpp"
#include <string>
#include <vector>
#include <map>
  using namespace std;

  map<long long, long long> MAP;
  class InfiniteSequence {
    public:
      long long calc(long long n, int p, int q) {
        if(n==0)
          return 1;
        if(MAP.count(n))
          return MAP[n];
        return MAP[n] = calc(n/p,p,q)+ calc(n/q,p,q);

      }


      // BEGIN CUT HERE
    public:
      void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
      template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
      void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
      void test_case_0() { long long Arg0 = 0LL; int Arg1 = 2; int Arg2 = 3; long long Arg3 = 1LL; verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
      void test_case_1() { long long Arg0 = 7LL; int Arg1 = 2; int Arg2 = 3; long long Arg3 = 7LL; verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
      void test_case_2() { long long Arg0 = 10000000LL; int Arg1 = 3; int Arg2 = 3; long long Arg3 = 32768LL; verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
      void test_case_3() { long long Arg0 = 256LL; int Arg1 = 2; int Arg2 = 4; long long Arg3 = 89LL; verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
      void test_case_4() { long long Arg0 = 1LL; int Arg1 = 1000000; int Arg2 = 1000000; long long Arg3 = 2LL; verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }

      // END CUT HERE

  };

// BEGIN CUT HERE
int main() {
  InfiniteSequence ___test;
  ___test.run_test(-1);
}
// END CUT HERE
