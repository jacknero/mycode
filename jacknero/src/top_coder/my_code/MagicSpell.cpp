// BEGIN CUT HERE
#if 0
// PROBLEM STATEMENT
// You are given a string spell containing an ancient magic spell.  The spell is encrypted, but the cypher is quite simple.  To decrypt the spell, you need to find all occurrences of the letters 'A' and 'Z', and then reverse their order.  For example, if the encrypted spell is "AABZCADZA", you would first find all the 'A's and 'Z's: "AA_Z_A_ZA".  You would then reverse their order: "AZ_A_Z_AA".  The final decrypted spell is "AZBACZDAA".  Return the decrypted version of the given spell.

DEFINITION
Class:MagicSpell
Method:fixTheSpell
Parameters:string
Returns:string
Method signature:string fixTheSpell(string spell)


CONSTRAINTS
-spell will contain between 1 and 50 uppercase letters ('A'-'Z'), inclusive. 


EXAMPLES

0)
"AZ"

Returns: "ZA"

This spell contains only letters 'A' and 'Z', so we just need to reverse it.

1)
"ABACADA"

Returns: "ABACADA"

This spell remains the same after decryption.

2)
"AABZCADZA"

Returns: "AZBACZDAA"

The example from the problem statement.

3)
"AZBASGHNAZAHBNVZZGGGAGGZAZ"

Returns: "ZABZSGHNAZZHBNVAZGGGAGGAZA"



#endif // 0
#include <iostream>
#include <sstream>
// END CUT HERE
#line 53 "MagicSpell.cpp"
#include <string>
#include <vector>
using namespace std;
class MagicSpell {
   public:
   string fixTheSpell(string spell) {
      
  unsigned int i; 
     for( i = 0; i < spell.length(); i++){
       if(spell[i] == 'A')
         spell.replace(i,1,"Z");
       else if(spell[i] == 'Z')
         spell.replace(i,1,"A");
     }
     return spell;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AZ"; string Arg1 = "ZA"; verify_case(0, Arg1, fixTheSpell(Arg0)); }
	void test_case_1() { string Arg0 = "ABACADA"; string Arg1 = "ABACADA"; verify_case(1, Arg1, fixTheSpell(Arg0)); }
	void test_case_2() { string Arg0 = "AABZCADZA"; string Arg1 = "AZBACZDAA"; verify_case(2, Arg1, fixTheSpell(Arg0)); }
	void test_case_3() { string Arg0 = "AZBASGHNAZAHBNVZZGGGAGGZAZ"; string Arg1 = "ZABZSGHNAZZHBNVAZGGGAGGAZA"; verify_case(3, Arg1, fixTheSpell(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
MagicSpell ___test;
___test.run_test(-1);
}
// END CUT HERE
