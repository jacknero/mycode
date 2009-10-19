#line 45 "Time.cpp"
#include <string>
#include <vector>
using namespace std;
class Time {
   public:
   string whatTime(int seconds) {
     char buf[10000];
     sprintf(buf, "%d:%d:%d",seconds/3600 ,seconds%3600/60,seconds%3600%60);
return buf;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
