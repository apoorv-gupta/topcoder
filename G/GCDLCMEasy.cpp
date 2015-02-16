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


class GCDLCMEasy {
   public:
      vector<vector < int > > e;
      vector<bool> vis;
      vector<int> A,B,G,L;
      vector<int> value;
      int dfs(int node) {
         if(vis[node]) return 1;
         vis[node]=true;
         int ret = 1;
         for(int i=0;i<e[node].size();++i){
            int ind = e[node][i];
            if((G[ind]*L[ind])%value[node]) return 0;
            int y=((G[ind]*L[ind])/value[node]);
            if(__gcd(value[node],y)!=G[ind]) return 0;
            int other = A[ind]+B[ind]-node;
            if(vis[other]&&(value[other]!=y))
               return 0;
            else if(!vis[other]){
               value[other]=y;
               ret*=dfs(other);
            }
         }
         return ret;
      }
      string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L) {
         e.clear();
         e.resize(n);
         this->A=A;
         this->B=B;
         this->G=G;
         this->L=L;
         vis.resize(n);
         value.resize(n);
         for(int i=0;i<A.size();++i){
            int a=A[i],b=B[i];
            e[a].push_back(i);
            e[b].push_back(i);
         }
         fill(vis.begin(),vis.end(),false);
         fill(value.begin(),value.end(),-1);
         vector<bool> lvis = vis;
         for(int i=0;i<n;++i){
            if(!vis[i]){
               int fail=1;
               for(int x=1;x<=10000;++x){
                  vis=lvis;//could TLE; should use dfs to set this. Meh.
                  value[i]=x;
                  if(dfs(i)){
                     fail=0;
                     break;
                  }
               }
               if(fail) return "Solution does not exist";
               lvis=vis;
            }
         }
         return "Solution exists";
      }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, vector <int> p4, bool hasAnswer, string p5) {
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
   cout << "}" << "," << "{";
   for (int i = 0; int(p3.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << p3[i];
   }
   cout << "}" << "," << "{";
   for (int i = 0; int(p4.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << p4[i];
   }
   cout << "}";
   cout << "]" << endl;
   GCDLCMEasy *obj;
   string answer;
   obj = new GCDLCMEasy();
   clock_t startTime = clock();
   answer = obj->possible(p0, p1, p2, p3, p4);
   clock_t endTime = clock();
   delete obj;
   bool res;
   res = true;
   cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
   if (hasAnswer) {
      cout << "Desired answer:" << endl;
      cout << "\t" << "\"" << p5 << "\"" << endl;
   }
   cout << "Your answer:" << endl;
   cout << "\t" << "\"" << answer << "\"" << endl;
   if (hasAnswer) {
      res = answer == p5;
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
   vector <int> p3;
   vector <int> p4;
   string p5;
   {
      // ----- test 0 -----
      p0 = 4;
      int t1[] = {0,1,2,3};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1,2,3,0};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {6,6,6,6};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      int t4[] = {12,12,12,12};
      p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
      p5 = "Solution exists";
      all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      p0 = 5;
      int t1[] = {0,1,2,3,4};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1,2,3,4,0};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {6,6,6,6,6};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      int t4[] = {12,12,12,12,12};
      p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
      p5 = "Solution does not exist";
      all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      p0 = 2;
      int t1[] = {0,0};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1,1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {123,123};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      int t4[] = {456,789};
      p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
      p5 = "Solution does not exist";
      all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
      // ------------------
   }
   {
      // ----- test 3 -----
      p0 = 2;
      int t1[] = {0};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {1234};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      int t4[] = {5678};
      p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
      p5 = "Solution does not exist";
      all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
      // ------------------
   }
   {
      // ----- test 4 -----
      p0 = 6;
      int t1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {2,2,3,3,1,2,5,1,5,1,7,7,3,5,7};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      int t4[] = {30,42,30,42,210,70,30,210,70,210,42,70,105,105,105};
      p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
      p5 = "Solution exists";
      all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
      // ------------------
   }

   {
      // ----- test 5 -----
      p0 = 500;
      int t1[] = {0};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {10000};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      int t4[] = {10000};
      p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
      p5 = "Solution exists";
      all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
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