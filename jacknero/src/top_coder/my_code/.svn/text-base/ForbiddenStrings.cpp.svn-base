// BEGIN CUT HERE
#if 0
// PROBLEM STATEMENT
// A string of letters A, B, C is forbidden if there are three consecutive letters from which one is A, one is B, and one is C. For example, BAACAACCBAAA is forbidden, while AABBCCAABB is not.

Your task is to calculate how many such strings of length n are not forbidden.


DEFINITION
Class:ForbiddenStrings
Method:countNotForbidden
Parameters:int
Returns:long long
Method signature:long long countNotForbidden(int n)


CONSTRAINTS
-n will be between 1 and 30, inclusive.


EXAMPLES

0)
2

Returns: 9

All 9 strings of length 2 are not forbidden.


1)
3

Returns: 21

There are 27 strings of length 3. Of these, 6 contain one occurrence of each letter. Those 6 strings are forbidden, so you should return 21.


2)
4

Returns: 51



#endif // 0
#include <iostream>
#include <sstream>
// END CUT HERE
#line 51 "ForbiddenStrings.cpp"
#include <string>
#include <vector>
using namespace std;
class ForbiddenStrings {
   public:
   long long countNotForbidden(int n) {

   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 9LL; verify_case(0, Arg1, countNotForbidden(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, countNotForbidden(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 51LL; verify_case(2, Arg1, countNotForbidden(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
ForbiddenStrings ___test;
___test.run_test(-1);
}
// END CUT HERE
