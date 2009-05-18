// BEGIN CUT HERE
#if 0
// PROBLEM STATEMENT
// NOTE: This problem statement contains subscripts that may not display properly if viewed outside of the applet.

In mathematics, an arithmetic progression or arithmetic sequence is a sequence of numbers such that the difference of any two successive members of the sequence is a constant. For instance, the sequence 3, 5, 7, 9, 11, 13... is an arithmetic progression with common difference 2. An arithmetic sequence can always be represented as an=a0+n*d.


You will be given a sequence seq, where seqi = [ai+1] for some nondecreasing arithmetic sequence a (both indices are 0-based). [x] denotes the floor function (see Notes). The sequence a is defined as a0+i*d. Return the minimal possible value for d. If no possible value exists for d, return -1 instead.


DEFINITION
Class:ArithmeticProgression
Method:minCommonDifference
Parameters:int, vector <int>
  Returns:double
Method signature:double minCommonDifference(int a0, vector <int> seq)


  NOTES
  -[x] denotes the floor function of x which returns the highest integer less than or equal to x. For example, [3.4] = 3, [0.6] = 0, [-1.2] = -2 and [-0.6] = -1.
  -Your return value must be accurate to within an absolute or relative tolerance of 1E-9.


  CONSTRAINTS
  -seq will contain between 0 and 50 elements, inclusive.
  -Each element of seq will be between -10^6 and 10^6, inclusive.
  -a0 will be between -10^6 and 10^6, inclusive.


  EXAMPLES

  0)
  0
{6, 13, 20, 27}

Returns: 6.75



1)
1
{2, 3, 4, 5, 6}

Returns: 1.0



2)
3
{}

Returns: 0.0

Since the sequence a is nondecreasing, d must be at least 0.

3)
3
{3, 3, 3, 3, 4}

Returns: 0.2



4)
1
{-3}

Returns: -1.0



5)
0
{6, 14}

Returns: -1.0



#endif // 0
#include <iostream>
#include <sstream>
// END CUT HERE
#line 86 "ArithmeticProgression.cpp"
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>
using namespace std;
class ArithmeticProgression {
  public:
    double minCommonDifference(int a0, vector <int> a) {
      double minD=0.0, maxD=1e20;
      for(int i=0; i<a.size();i++){
        double A=(a[i]-a0)/(double)(i+1);
        double B=(a[i]-a0+1)/(double)(i+1);
        minD=max(minD,A),maxD=min(maxD,B);
      }
      if(minD<maxD) return minD;
      return -1;

    }


    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 0; int Arr1[] = {6, 13, 20, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.75; verify_case(0, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 1; int Arr1[] = {2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 3; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 3; int Arr1[] = {3, 3, 3, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.2; verify_case(3, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 1; int Arr1[] = {-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(4, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = 0; int Arr1[] = {6, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(5, Arg2, minCommonDifference(Arg0, Arg1)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main() {
  ArithmeticProgression ___test;
  ___test.run_test(-1);
}
// END CUT HERE
