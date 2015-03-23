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

char b[]={'(',')','[',']','{','}'};
char opp[128],open[128];

class BracketExpressions {
   public:
      void pre() {
         opp['(']=')';
         opp['[']=']';
         opp['{']='}';
         opp[')']='(';
         opp[']']='[';
         opp['}']='{';
         open['(']=')';
         open['[']=']';
         open['{']='}';
         open[')']=0;
         open[']']=0;
         open['}']=0;
      }
      int check(string str){
         stack <char > s;
         int n = str.size();
         for(int i=0;i<n;++i)
            if(open[str[i]])
               s.push(str[i]);
            else{
               if(s.empty()) return 0;
               char ch = s.top();
               if(opp[ch]==str[i])
                  s.pop();
               else return 0;
            }
         return s.empty();
      }
      string ifPossible(string e) {
         pre();
         int n = e.size();
         int m = 0;
         for(int i=0;i<n;++i) m+=(e[i]=='X');
         vector<vector < int > > tried;
         for(int bit=(1<<(m*3))-1;bit>=0;--bit){
            vector<int> x;
            int mask = 7;
            int bbit = bit;
            for(int i=0;i<m;++i){
               int ind = bit&mask;
               if(ind>5) break;
               x.push_back(b[ind]);
               bit/=8;
            }
            bit=bbit;
            if(x.size()!=m) continue;
           // tried.push_back(x);
            string str(e);
            int j=0;
            for(int i=0;i<n;++i) if(e[i]=='X') str[i]=x[j++];
            if(check(str)) return "possible";
         }
         return "impossible";
      }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
   cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
   cout << "]" << endl;
   BracketExpressions *obj;
   string answer;
   obj = new BracketExpressions();
   clock_t startTime = clock();
   answer = obj->ifPossible(p0);
   clock_t endTime = clock();
   delete obj;
   bool res;
   res = true;
   cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
   if (hasAnswer) {
      cout << "Desired answer:" << endl;
      cout << "\t" << "\"" << p1 << "\"" << endl;
   }
   cout << "Your answer:" << endl;
   cout << "\t" << "\"" << answer << "\"" << endl;
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
   string p1;

   {
      // ----- test 0 -----
      p0 = "([]{})";
      p1 = "possible";
      all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 1 -----
      p0 = "(())[]";
      p1 = "possible";
      all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 2 -----
      p0 = "({])";
      p1 = "impossible";
      all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 3 -----
      p0 = "[]X";
      p1 = "impossible";
      all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
      // ------------------
   }

   {
      // ----- test 4 -----
      p0 = "([]X()[()]XX}[])X{{}}]";
      p1 = "possible";
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
