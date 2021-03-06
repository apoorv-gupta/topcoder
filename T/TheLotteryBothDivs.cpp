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


class TheLotteryBothDivs {
   public:
      double find(vector <string> goodSuffixes) {
         int ans=0;
         sort(goodSuffixes.begin(),goodSuffixes.end());
         goodSuffixes.resize(unique(goodSuffixes.begin(),goodSuffixes.end())-goodSuffixes.begin());
         int n = goodSuffixes.size();
         for(int i=0;i<n;++i)
            reverse(goodSuffixes[i].begin(),goodSuffixes[i].end());
         for(int i=0;i<n;++i){
            int succ=1;
            for(int j=0;j<n;++j){
               if(i==j) continue;
               const char *a=goodSuffixes[i].c_str();
               const char *b=goodSuffixes[j].c_str();
               const char *ptr=strstr(a,b);
               if(ptr==a)
                  succ=0;
            }
            if(!succ)
               continue;
            int dig = 9-goodSuffixes[i].size();
            int cur=1;
            while(dig--)
               cur*=10;
            ans+=cur;
         }
         return ans/((double)10000*10000*10);
      }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, double p1) {
   cout << "Test " << testNum << ": [" << "{";
   for (int i = 0; int(p0.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << "\"" << p0[i] << "\"";
   }
   cout << "}";
   cout << "]" << endl;
   TheLotteryBothDivs *obj;
   double answer;
   obj = new TheLotteryBothDivs();
   clock_t startTime = clock();
   answer = obj->find(p0);
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
      res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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

   vector <string> p0;
   double p1;

   {
      // ----- test 0 -----
      string t0[] = {"4"};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 0.1;
      all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      string t0[] = {"4","7"};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 0.2;
      all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      string t0[] = {"47","47"};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 0.01;
      all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      string t0[] = {"47","58","4747","502"};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 0.021;
      all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 4 -----
      string t0[] = {"8542861","1954","6","523","000000000","5426","8"};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      p1 = 0.201100101;
      all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
