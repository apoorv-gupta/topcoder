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


class LittleElephantAndIntervalsDiv1 {
public:
	long long getNumber(int M, vector <int> L, vector <int> R) {
           vector < int > iter(M,-1);
           int turns=L.size();
           vector < int > vis(turns,0);
           for(int i=0;i<turns;++i)
              for(int j=L[i]-1;j<=R[i]-1;++j)
                 iter[j]=i;
           long long ans=1;
           for(int i=0;i<M;++i)
              if(iter[i]!=-1)
                 vis[iter[i]]=1;

           for(int i=0;i<turns;++i)
              if(vis[i])
                 ans*=2;
           return ans;
        }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, long long p3) {
   cout << "Test " << testNum << ": [" << p0 << "," << "{";
   for (int i = 0; int(p1.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << p1[i];
   }
   cout << "}" << "," << "{";
   for (int i = 0; int(p2.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << p2[i];
   }
   cout << "}";
   cout << "]" << endl;
   LittleElephantAndIntervalsDiv1 *obj;
   long long answer;
   obj = new LittleElephantAndIntervalsDiv1();
   clock_t startTime = clock();
   answer = obj->getNumber(p0, p1, p2);
   clock_t endTime = clock();
   delete obj;
   bool res;
   res = true;
   cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
   if (hasAnswer) {
      cout << "Desired answer:" << endl;
      cout << "\t" << p3 << endl;
   }
   cout << "Your answer:" << endl;
   cout << "\t" << answer << endl;
   if (hasAnswer) {
      res = answer == p3;
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
   vector <int> p1;
   vector <int> p2;
   long long p3;

   {
      // ----- test 0 -----
      p0 = 4;
      int t1[] = {1,2,3};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1,2,3};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 8ll;
      all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      p0 = 3;
      int t1[] = {1,1,2};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {3,1,3};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 4ll;
      all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      p0 = 1000;
      int t1[] = {47};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {747};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 2ll;
      all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      p0 = 42;
      int t1[] = {5,23,4,1,15,2,22,26,13,16,28,13,27,9,18,4,10,3,4,4,3,4,1,18,18,2,38,4,10,12,3,30,11,38,2,13,1,13,18,16,13,2,14,27,13,3,26,19,5,10};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {30,41,17,1,21,6,28,30,15,19,31,28,35,27,30,13,31,5,8,25,40,10,3,26,23,9,40,8,40,23,12,37,35,39,11,34,10,21,22,21,24,5,39,27,17,16,26,35,25,36};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 256ll;
      all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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