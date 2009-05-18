#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

class LinearPolyominoCovering {
public:
  string findCovering(string region) {
    int size = region.size();
    int count =0;
    for(int i =0; i < size ; i++){
      //cout << region[i] << endl;
      if(region[i] == 'X'){
        count++;
        cout << count << endl;
        }
      }else if(region[i] == '.'){
        if(count == 2){
        }
      }
    
    string result;
    return result;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "XXXXXX"; string Arg1 = "AAAABB"; verify_case(0, Arg1, findCovering(Arg0)); }
	void test_case_1() { string Arg0 = "XX.XX"; string Arg1 = "BB.BB"; verify_case(1, Arg1, findCovering(Arg0)); }
	void test_case_2() { string Arg0 = "XXXX....XXX.....XX"; string Arg1 = "impossible"; verify_case(2, Arg1, findCovering(Arg0)); }
	void test_case_3() { string Arg0 = "X"; string Arg1 = "impossible"; verify_case(3, Arg1, findCovering(Arg0)); }
	void test_case_4() { string Arg0 = "XX.XXXXXXXXXX..XXXXXXXX...XXXXXX"; string Arg1 = "BB.AAAAAAAABB..AAAAAAAA...AAAABB"; verify_case(4, Arg1, findCovering(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  LinearPolyominoCovering ___test;
  ___test.run_test(-1);
}
// END CUT HERE
