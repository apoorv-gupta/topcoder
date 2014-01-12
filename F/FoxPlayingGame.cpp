#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef double data_t;
data_t minval[64][64];
data_t maxval[64][64];

class FoxPlayingGame {
public:
   double theMax(int nA, int nB, int paramA, int paramB) {
      data_t a=paramA/((data_t)1000.0);//to be added
      data_t b=paramB/((data_t)1000.0);
      for(int i=0;i<64;++i)
         minval[i][0]=maxval[i][0]=a*i;
      for(int j=0;j<64;++j)
         minval[0][j]=maxval[0][j]=0;
      for(int i=1;i<64;++i)
         for(int j=1;j<64;++j){
            minval[i][j]=min(min(b*maxval[i][j-1],b*minval[i][j-1]),min(a+maxval[i-1][j],a+minval[i-1][j]));
            maxval[i][j]=max(max(b*maxval[i][j-1],b*minval[i][j-1]),max(a+maxval[i-1][j],a+minval[i-1][j]));
         }
      return ((double)maxval[nA][nB]);
   }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4) {
   cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
   cout << "]" << endl;
   FoxPlayingGame *obj;
   double answer;
   obj = new FoxPlayingGame();
   clock_t startTime = clock();
   answer = obj->theMax(p0, p1, p2, p3);
   clock_t endTime = clock();
   delete obj;
   bool res;
   res = true;
   cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
   if (hasAnswer) {
      cout << "Desired answer:" << endl;
      cout << "\t" << p4 << endl;
   }
   cout << "Your answer:" << endl;
   cout << "\t" << answer << endl;
   if (hasAnswer) {
      res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
   }
   if (!res) {
      cout << "DOESN'T MATCH!!!!" << endl;
   } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
      cout << "FAIL the timeout" << endl;
      res = false;
   } else if (hasAnswer) {
      cout << "Match :-)" << endl;
   } else {
      cout << "OK, but is it right?" << endl;
   }
   cout << "" << endl;
   return res;
}
int main() {
   bool all_right;
   all_right = true;

   int p0;
   int p1;
   int p2;
   int p3;
   double p4;
   {
      // ----- test 0 -----
      p0 = 5;
      p1 = 4;
      p2 = 3000;
      p3 = 2000;
      p4 = 240.0;
      all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      p0 = 3;
      p1 = 3;
      p2 = 2000;
      p3 = 100;
      p4 = 6.0;
      all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      p0 = 4;
      p1 = 3;
      p2 = -2000;
      p3 = 2000;
      p4 = -8.0;
      all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }
   {
      // ----- test 3 -----
      p0 = 5;
      p1 = 5;
      p2 = 2000;
      p3 = -2000;
      p4 = 160.0;
      all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }
   {
      // ----- test 4 -----
      p0 = 50;
      p1 = 50;
      p2 = 10000;
      p3 = 2000;
      p4 = 5.62949953421312E17;
      all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 5 -----
      p0 = 41;
      p1 = 34;
      p2 = 9876;
      p3 = -1234;
      p4 = 515323.9982341775;
      all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   if (all_right) {
      cout << "You're a stud (at least on the example cases)!" << endl;
   } else {
      cout << "Some of the test cases had errors." << endl;
   }
   return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!