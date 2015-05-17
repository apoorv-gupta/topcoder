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


class ConundrumReloaded {
public:
   int check(string s){
      int ans=s.size()+1;
      for(int v=0;v<2;++v){
         int ini = v;
         int lans=0;
         for(int i=0;i<s.size();++i){
            if(v) lans++;
            if((v==0)&&(s[i]=='L'))      v=1;
            else if((v==1)&&(s[i]=='L')) v=0;
            else if(s[i]=='?') v=ini;
         }
         if(v==ini)
            ans=min(ans,lans);
         v=ini;
      }
      if(ans==s.size()+1)
         return -1;
      return ans;
   }
   int minimumLiars(string inp) {
      if(inp.find('?')==string::npos){
         return check(inp);
      }
      int n = inp.size();
      inp+=inp;
      int j=0;
      while(inp[j]!='?') j++;
      while(inp[j]=='?') j++;
      int ans=0;
      string sub;
      for(int cnt=0;cnt<n;++cnt,++j){
         if(inp[j]=='?'){
            if(sub.size()){
               ans+=check(sub+'?');
               sub="";
            }
         }
         else sub+=inp[j];
      }
      return ans;
   }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
   cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
   cout << "]" << endl;
   ConundrumReloaded *obj;
   int answer;
   obj = new ConundrumReloaded();
   clock_t startTime = clock();
   answer = obj->minimumLiars(p0);
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
      p0 = "LLH";
      p1 = 1;
      all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      p0 = "?" "?" "?" "?" "?";
      p1 = 0;
      all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      p0 = "LHLH?";
      p1 = 2;
      all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      p0 = "?" "?LLLLLL?" "?";
      p1 = 3;
      all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 4 -----
      p0 = "LLL";
      p1 = -1;
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