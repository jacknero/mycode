// BEGIN CUT HERE
#if 0
// PROBLEM STATEMENT
// 
In graph theory, an independent set or stable set is a set of vertices in a graph such that no two of the vertices are adjacent. That is, it is a set V of vertices such that for every two vertices in V, there is no edge connecting the two. 


Similarly, we can define a k-stable set as a set of vertices in a graph such that each vertex in the set has at most k adjacent vertices that are also in the set. So the 0-stable set is the original stable set.


You will be given a vector <string> graph, representing an undirected, acyclic, connected graph. The j-th character of the i-th element of graph will be 'Y' if vertices i and j are connected, or 'N' otherwise. Return a vector <int> containing exactly n elements, where n is the number of elements in graph. The i-th element should be the number of distinct i-stable sets in the graph modulo 112901989, where i is a 0-based index.



DEFINITION
Class:TreeCount
Method:count
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> count(vector <string> graph)


CONSTRAINTS
-graph will contain between 1 and 50 elements, inclusive.
-Each element of graph will contain exactly N characters, where N is the number of elements in graph.
-Each character in graph will be either 'Y' or 'N'.
-The j-th character of the i-th element of graph will equal to the i-th character of the j-th element.
-The i-th character of the i-th element of graph will be 'N'.
-The graph will represent a tree.


EXAMPLES

0)
{"NYY", "YNN", "YNN"}

Returns: {5, 7, 8 }

The tree is 1-0-2. The 5 0-stable sets are {}, {0}, {1}, {2}, {1, 2}. 
The 7 1-stable sets are all the subsets except {0, 1, 2}.  There are 2^3 subsets total, and each one is a 2-stable set.

1)
{"N"}

Returns: {2 }



2)
{"NYNNNYY", "YNNNNNN", "NNNNNNY", "NNNNNNY", "NNNNNNY", "YNNNNNN", "YNYYYNN"}

Returns: {44, 73, 104, 124, 128, 128, 128 }



3)
{"NY", "YN"}

Returns: {3, 4 }



4)
{"NYYYYY", "YNNNNN", "YNNNNN", "YNNNNN", "YNNNNN", "YNNNNN"}

Returns: {33, 38, 48, 58, 63, 64 }



#endif // 0
#include <iostream>
#include <sstream>
// END CUT HERE
#line 75 "TreeCount.cpp"
#include <string>
#include <vector>
using namespace std;
class TreeCount {
   public:
   vector <int> count(vector <string> graph) {

   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NYY", "YNN", "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 7, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNNNYY", "YNNNNNN", "NNNNNNY", "NNNNNNY", "NNNNNNY", "YNNNNNN", "YNYYYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {44, 73, 104, 124, 128, 128, 128 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"NY", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYYYYY", "YNNNNN", "YNNNNN", "YNNNNN", "YNNNNN", "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33, 38, 48, 58, 63, 64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
TreeCount ___test;
___test.run_test(-1);
}
// END CUT HERE
