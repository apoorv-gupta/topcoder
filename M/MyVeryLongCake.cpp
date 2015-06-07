#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
class MyVeryLongCake{
   public:
   int cut(int n) {
      vector < int > fact;
      for(int i=2;i*i<=n;++i){
         if(n%i) continue;
         fact.push_back(i);
         fact.push_back(n/i);
      }
      sort(fact.begin(), fact.end());
      vector<bool> isp(fact.size(),true);
      int ans=n;
      for(int i=0;i<fact.size();++i){
         if(!isp[i]) continue;
         ans/=fact[i];
         ans*=(fact[i]-1);
         for(int j=i+1;j<fact.size();++j)
            if(!(fact[j]%fact[i]))
               isp[j]=false;
      }
      return max(n-ans,1);
   }
};

int main()
{
   vector < int > inp,op;
   inp.push_back(15);
   op.push_back(7);
   inp.push_back(3);
   op.push_back(1);
   inp.push_back(1000000000);
   op.push_back(600000000);
   inp.push_back(577007436);
   op.push_back(384671628);
   MyVeryLongCake h;
   for(int i=0;i<inp.size();++i){
      int ac = h.cut(inp[i]);
      if(op[i]==ac) {
         printf("correct\n");
      } else{
         printf("actual %d expected %d\n",ac,op[i],ac);
      }
   }
   return 0;
}
