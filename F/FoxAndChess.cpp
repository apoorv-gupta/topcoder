//Problem Statement: http://community.topcoder.com/stat?c=problem_statement&pm=12725&rd=15702
#define tr(c,i)                      for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
class FoxAndChess {
   public:
      string ableToMove(string begin, string target) {
         int n=begin.size();
         vp f,s; 
         for(int i=0;i<n;++i){
            if(begin[i]!='.')
               f.push_back(pair < int, int> (begin[i],i));
            if(target[i]!='.')
               s.push_back(pair < int, int> (target[i],i));
         }
         if(f.size()!=s.size()) return "Impossible";
         for(int i=0;i<f.size();++i){
            if(f[i].first!=s[i].first) return "Impossible";
            if(f[i].first=='L')
               if(f[i].second<s[i].second) return "Impossible";
            if(f[i].first=='R')
               if(f[i].second>s[i].second) return "Impossible";
         }
         return  "Possible";
      }
};
