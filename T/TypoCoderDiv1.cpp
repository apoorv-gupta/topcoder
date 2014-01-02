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
#include <cstring>
#include <ctime>

using namespace std;

int ans[64][2200];
class TypoCoderDiv1 {
public:
	int getmax(vector <int> d, int x) {
           int n=d.size();
           memset(ans,0,sizeof(ans));
           for(int i=n-1;i>=0;--i){
              for(int st=0;st<2200;++st){
                 //we lose
                 int end = max(st-d[i],0);
                 ans[i][st]=ans[i+1][end];
              }
              for(int st=0;st<2200;++st){
                 //we win
                 int end = st+d[i];
                 if(end >=2200){
                    if(i==n-1){
                       ans[i][st]=1;
                       continue;
                    }
                    //see if you can lose next one
                    int next = max(end-d[i+1],0);
                    if(next<2200)
                       ans[i][st]=max(ans[i][st],ans[i+2][next]+2);
                 }
                 else
                    ans[i][st]=max(ans[i][st],ans[i+1][end]);
              }
           }
           return ans[0][x];
        }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
   cout << "Test " << testNum << ": [" << "{";
   for (int i = 0; int(p0.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << p0[i];
   }
   cout << "}" << "," << p1;
   cout << "]" << endl;
   TypoCoderDiv1 *obj;
   int answer;
   obj = new TypoCoderDiv1();
   clock_t startTime = clock();
   answer = obj->getmax(p0, p1);
   clock_t endTime = clock();
   delete obj;
   bool res;
   res = true;
   cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
   if (hasAnswer) {
      cout << "Desired answer:" << endl;
      cout << "\t" << p2 << endl;
   }
   cout << "Your answer:" << endl;
   cout << "\t" << answer << endl;
   if (hasAnswer) {
      res = answer == p2;
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

   vector <int> p0;
   int p1;
   int p2;

   {
      // ----- test 0 -----
      int t0[] = {100,200,100,1,1};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 2000;
      p2 = 3;
      all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      int t0[] = {0,0,0,0,0};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 2199;
      p2 = 0;
      all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      int t0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 0;
      p2 = 1;
      all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      int t0[] = {1000000000,1000000000,10000,100000,2202,1};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 1000;
      p2 = 4;
      all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
      // ------------------
   }

   {
      // ----- test 4 -----
      int t0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 2199;
      p2 = 0;
      all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
      // ------------------
   }
   {
      // ----- test 5 -----
      int t0[] ={61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 1223;
      p2 = 29;
      all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
      // ------------------
   }
   {
      // ----- test 6 -----
      int t0[] ={34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 1328;
      p2 = 20;
      all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
