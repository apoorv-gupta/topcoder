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

class TwoNumberGroupsEasy{
public:
   vector<int> primes;
   char p[31700];
   set<int> s;
   void add(int d){
      //printf("called for %d\n",d);
      vector<int> f;
      for(int i=0;primes[i]<d;++i){
         int c = primes[i];
         while((d%c)==0){
            d/=c;
            f.push_back(c);
         }
      }
      if(d>1) f.push_back(d);
      int n = f.size();
      for(int bit=(1<<n)-1;bit;--bit){
         int prod=1;
         for(int i=0;i<n;++i)
            if(bit&(1<<i))
               prod*=f[i];
         s.insert(prod);
      }
   }
   void sieve() {
      fill(p,p+31700,0);
      primes.push_back(2);
      for(int i=3;i<31700;i+=2){
         if(p[i]) continue;
         primes.push_back(i);
         for(int j=i*i;j<31700;j+=(2*i))
            p[j]=1;
      }
      //imes.push_back(1123456789);
      primes.push_back(1000000007);
   }
   int findcur(const vector <int> &A, const vector <int> &numA, const vector <int> &B, const vector <int> &numB){
      map<int,int> m;
         for(unsigned int i=0;i<A.size();++i)
            m[A[i]]+=numA[i];
         for(unsigned int j=0;j<B.size();++j)
            m[B[j]]-=numB[j];
         int lans=0;
         for(map<int,int>::iterator it = m.begin();it!=m.end();it++)
            lans+=max(it->second,-(it->second));
         return lans;
   }
   int solve(const vector <int> A, const vector <int> numA, const vector <int> B, const vector <int> numB) {
      sieve();
      for(unsigned int i=0;i<A.size();++i)
         for(unsigned int j=0;j<B.size();++j){
            int a = A[i];
            int b = B[j];
            add(max(a,b)-min(a,b));
         }
      vector < int > can(s.begin(),s.end());
      int n = can.size();
      int ans = findcur(A,numA,B,numB);
      for(int k=0;k<n;++k){
         map<int,int> m;
         const int mod = can[k];
         //printf("mod is %d\n",mod);
         for(unsigned int i=0;i<A.size();++i)
            m[A[i]%mod]+=numA[i];
         
         for(unsigned int i=0;i<B.size();++i)
            m[B[i]%mod]-=numB[i];
         int lans=0;
         for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
            int key=it->first;
            int val=it->second;
            lans+=abs(val);
         }
         ans=min(ans,lans);
      }
      return ans;
   }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
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
   cout << "}" << "," << "{";
   for (int i = 0; int(p3.size()) > i; ++i) {
      if (i > 0) {
         cout << ",";
      }
      cout << p3[i];
   }
   cout << "}";
   cout << "]" << endl;
   TwoNumberGroupsEasy *obj;
   int answer;
   obj = new TwoNumberGroupsEasy();
   clock_t startTime = clock();
   answer = obj->solve(p0, p1, p2, p3);
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
      res = answer == p4;
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
   vector <int> p3;
   int p4;

   {
      // ----- test 0 -----
      int t0[] = {1,2,3,4};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {2,1,1,1};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {5,6,7,8};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {1,1,1,2};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      p4 = 2;
      all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      int t0[] = {5,7};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1,1};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {12,14};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {1,1};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      p4 = 0;
      all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      int t0[] = {100};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {2};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {1};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      p4 = 1;
      all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      int t0[] = {1};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {1};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {1};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      p4 = 0;
      all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 4 -----
      int t0[] = {5};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {1};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {6};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {1};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      p4 = 2;
      all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
      // ------------------
   }

   {
      // ----- test 5 -----
      int t0[] = {733815053,566264976,984867861,989991438,407773802,701974785,599158121,713333928,530987873,702824160};
      p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
      int t1[] = {8941,4607,1967,2401,495,7654,7078,4213,5485,1026};
      p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
      int t2[] = {878175560,125398919,556001255,570171347,643069772,787443662,166157535,480000834,754757229,101000799};
      p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
      int t3[] = {242,6538,7921,2658,1595,3049,655,6945,7350,6915};
      p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
      p4 = 7;
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