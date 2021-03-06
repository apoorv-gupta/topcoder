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

typedef pair <int,int> ii;
class CandleTimerEasy {
public:
	int differentTime(vector <int> A, vector <int> B, vector <int> len) {
           int v = A.size()+1;
           vector<vector < int > > e(v);
           vector < int > deg(v,0);
           for(int i=0;i<A.size();++i){
              e[A[i]].push_back(i);
              e[B[i]].push_back(i);
              deg[A[i]]++;
              deg[B[i]]++;
           }
           char possible[40001]={};
           for(int bit=(1<<v)-1;bit;--bit){
              int fail=0;
              set<pair<int,int> > s; //<time,vertex>
              vector < int > best(v,123456);
              vector < int > done(v,0);
              for(int i=0;i<v;++i){
                 if(!(bit&(1<<i))) continue;
                 if(deg[i]>1) {fail=1;break;}
                 s.insert(ii(0,i));
                 best[i]=0;
              }
              if(fail) continue;
              int lans=0;
              while(!s.empty()){
                 pair<int,int> tmp= *(s.begin());
                 s.erase(tmp);
                 int t = tmp.first;
                 int i = tmp.second;
                 if(best[i]<t) continue;
                 lans=t;
                 for(int j=0;j<e[i].size();++j){
                    int edge = e[i][j];
                    int vert = A[edge]+B[edge]-i;
                    int newd = t + len[edge];
                    if(best[vert]<=newd) continue;
                    s.insert(ii(newd,vert));
                    best[vert]=newd;
                 }
              }
              
              lans*=2;
              for(int i=0;i<A.size();++i){
                 int a=best[A[i]];
                 int b=best[B[i]];
                 if(a>b) swap(a,b);
                 //now a < b
                 if(a+len[i]==b) continue;//only one end burnt throughout
                 int thist = (2*b+len[i]-(b-a));
                 lans=max(lans,thist);
              }
              possible[lans]=1;
           }
           int ans=0;
           for(int i=0;i<40001;++i){
              ans+=possible[i];
           }
           return ans;
        }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
   cout << "Test " << testNum << ": [" << "{";
   for (int i = 0; int(p0.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << p0[i];
   }
   cout << "}" << "," << "{";
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
   CandleTimerEasy *obj;
   int answer;
   obj = new CandleTimerEasy();
   clock_t startTime = clock();
   answer = obj->differentTime(p0, p1, p2);
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

   vector <int> p0;
   vector <int> p1;
   vector <int> p2;
   int p3;

   {
      // ----- test 0 -----
      int t0[] = {0,1};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1,2};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {10,1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 2;
      all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      int t0[] = {0,0,0};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1,2,3};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1,1,1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 2;
      all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      int t0[] = {0,0,0};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1,2,3};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1,2,3};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 4;
      all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      int t0[] = {0,1,1,2,3,3,2,4};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1,2,3,4,5,6,7,8};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {5,3,2,4,6,8,7,1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 7;
      all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 4 -----
      int t0[] = {0,0,0,0};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1,2,3,4};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {123,456,789,1000};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 8;
      all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
      // ------------------
   }

   {
      // ----- test 5 -----
      int t0[] = {0};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1000};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      p3 = 2;
      all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
