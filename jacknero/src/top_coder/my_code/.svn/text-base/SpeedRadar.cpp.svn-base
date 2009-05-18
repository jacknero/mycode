// BEGIN CUT HERE
#if 0
// PROBLEM STATEMENT
// 
A speed radar is installed in a highway zone where the maximum speed limit is maxLimit mph, and the minimum speed limit is minLimit mph.  Any reading that is strictly above or below this interval is an infringement.


Periodically, the radar readings are analyzed to make sure that the sensors are working properly.  It is assumed that most drivers obey speed limits, and therefore, the radar will be considered faulty if more than 10% of its readings are infringements.


Given the radar readings over a period of time, return the average speed of all cars that are driving within the speed limits.  If the radar is faulty, return 0.0.


DEFINITION
Class:SpeedRadar
Method:averageSpeed
Parameters:int, int, vector <int>
Returns:double
Method signature:double averageSpeed(int minLimit, int maxLimit, vector <int> readings)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-maxLimit will be between 1 and 200, inclusive.
-minLimit will be between 1 and maxLimit, inclusive.
-readings will contain between 1 and 50 elements, inclusive.
-Each element of readings will be between 1 and 200, inclusive.


EXAMPLES

0)
1
50
{45, 40, 50}

Returns: 45.0

With all drivers within the speed limits, the return value is just the average speed.

1)
1
50
{42,43,44,45,46,47,48,49,50,51}

Returns: 46.0

There is only one driver infringing the limit, and it represents 10% of the total readings. The average speed of the other readings is 46.0.

2)
1
50
{42,46,48,50,52}

Returns: 0.0

Only one reading is outside the given limits, but it represents 20% of the total number of readings.  We therefore assume that the radar is not working and return 0.0.

3)
20
60
{25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54}

Returns: 41.68421052631579

#endif // 0
#include <iostream>
#include <sstream>
// END CUT HERE
#line 74 "SpeedRadar.cpp"
#include <string>
#include <vector>
using namespace std;
class SpeedRadar {
   public:
   double averageSpeed(int minLimit, int maxLimit, vector <int> readings) {

   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 50; int Arr2[] = {45, 40, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 45.0; verify_case(0, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 50; int Arr2[] = {42,43,44,45,46,47,48,49,50,51}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 46.0; verify_case(1, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 50; int Arr2[] = {42,46,48,50,52}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(2, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 60; int Arr2[] = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 41.68421052631579; verify_case(3, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
SpeedRadar ___test;
___test.run_test(-1);
}
// END CUT HERE
