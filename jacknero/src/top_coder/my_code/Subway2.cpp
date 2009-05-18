#line 82 "Subway2.cpp"
#include <string>
#include <vector>
#include <cmath>
  using namespace std;
  class Subway2 {
    public:
      double minTime(int length, int maxAcceleration, int maxVelocity) {
        double len=length, a=maxAcceleration, vmax=maxVelocity;
        if((double)len > (double)vmax*(double)vmax/(double)a){
          len -= (double)vmax*(double)vmax / (double)a;
          return len / vmax + vmax / a*2;
        }else{
          return 2*sqrt(len/a);
        }

      }



  };



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
