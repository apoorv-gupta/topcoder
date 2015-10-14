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
#include<cstring>

using namespace std;

#define MAX 222
#define MODBY 1000000007
int cnt[MAX][MAX][MAX];  // 250 MB+
class BearCries {
public:
   inline int mult(int x, int y){
      return (((long long int)x)*y)%MODBY;
   }
   inline void add(int &x, int y){
      x+=y;
      if(x>=MODBY) x-=MODBY;
   }
   int count(string m) {
      int n = m.size();
      memset(cnt, 0, sizeof(cnt));
      cnt[0][0][0]=1;
      for(int i=0;i<n;++i)
         for(int j=0;j<n;++j)
            for(int k=0;k<n;++k){
               int x = cnt[i][j][k];
               if(m[i]==';'){
                  add(cnt[i+1][j+1][k], x);// adding new family with left semicolon only
                  if(k)
                     add(cnt[i+1][j][k-1], mult(x, k));// adding right semicolon; completes a family
               } else {// it's an '_'
                  add(cnt[i+1][j-1][k+1], mult(x, j));// adding underscore to a new family
                  if(k)
                     add(cnt[i+1][j][k], mult(x, k));// wasting underscore on someone with a half family
               }
            }
      return cnt[n][0][0];
   }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
   cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
   cout << "]" << endl;
   BearCries *obj;
   int answer;
   obj = new BearCries();
   clock_t startTime = clock();
   answer = obj->count(p0);
   clock_t endTime = clock();
   delete obj;
   bool res;
   res = true;
   cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
   if (hasAnswer) {
      cout << "Desired answer:" << endl;
      cout << "\t" << p1 << endl;
   }
   cout << "Your answer:" << endl;
   cout << "\t" << answer << endl;
   if (hasAnswer) {
      res = answer == p1;
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

   string p0;
   int p1;
   {
      // ----- test 0 -----
      p0 = ";_;";
      p1 = 1;
      all_right = KawigiEdit_RunTest(-1, p0, true, p1) && all_right;
      // ------------------
   }
   {
      // ----- test 0 -----
      p0 = ";__;";
      p1 = 1;
      all_right = KawigiEdit_RunTest(-1, p0, true, p1) && all_right;
      // ------------------
   }
   {
      // ----- test 0 -----
      p0 = ";_;;_;";
      p1 = 2;
      all_right = KawigiEdit_RunTest(-1, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 0 -----
      p0 = ";_;;_____;";
      p1 = 2;
      all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      p0 = ";;;___;;;";
      p1 = 36;
      all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      p0 = "_;__;";
      p1 = 0;
      all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      p0 = ";_____________________________________;";
      p1 = 1;
      all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 4 -----
      p0 = ";__;____;";
      p1 = 0;
      all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 5 -----
      p0 = ";_;;__;_;;";
      p1 = 52;
      all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
      // ------------------
   }
   {
      // ----- test 6 -----
      p0 = ";;;_;;;;;;;_;__;;;;_;;;;;;;;;;_;_;;___;;;;_;;_;____;_;;;;;;;__;__;;_;__;;;;;;___;;;_;;;;;__;_;;;_;;;_;_;;;_;;_;_;;;;___;;;______;;__;;;;;;_;;_;;;;_;;;;_;;;;;_____;;;;;;_;;;;;_____;;_;;;;;;__;;;;;;__;;";
      p1 = 936117765;
      all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
