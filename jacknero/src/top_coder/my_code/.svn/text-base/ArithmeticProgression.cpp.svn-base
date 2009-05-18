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



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
