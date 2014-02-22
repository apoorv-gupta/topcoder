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
#include<string.h>

using namespace std;

int ans[102345][64];

class TheProgrammingContestDivOne {
   public:
      void precomp(int T, vector <long long int > m, vector <long long int> p, vector <long long int> r){
         memset(ans,0,sizeof(ans));
         int n=p.size();
         for(int t=T;t>=0;--t)
            for(int i=n-1;i>=0;--i){
               ans[t][i]=ans[t][i+1];//ignored it
               if(t+r[i]>T) 
                  continue;
               ans[t][i]=max((long long int)ans[t][i],m[i]-p[i]*(r[i]+t)+ans[t+r[i]][i+1]);
            }
      }
      int find(int T, vector <int> m, vector <int> p, vector <int> r){
         vector < int > v=m;
         for(int i=0;i<v.size();++i)
            v[i]=i;
         for(int i=0;i<v.size();++i)
            for(int j=i+1;j<v.size();++j)
               if(((long long int)r[v[j]]*p[v[i]])<=((long long int)r[v[i]]*p[v[j]]))
                  swap(v[i],v[j]);
         int n=v.size();
         vector < long long int > m1(n),p1(n),r1(n);
         for(int i=0;i<v.size();++i){
            m1[i]=m[v[i]];
            r1[i]=r[v[i]];
            p1[i]=p[v[i]];
         }
         precomp(T, m1, p1, r1);
         return (int)ans[0][0];
      }

};
