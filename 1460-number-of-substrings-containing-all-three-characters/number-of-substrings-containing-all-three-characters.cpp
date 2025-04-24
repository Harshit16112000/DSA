class Solution {
public:
    int numberOfSubstrings(string s) {
    int l = 0;
      int r = 0;
      int n = s.size();
      int k = 3;
      unordered_map<int,int> mpp;
      int cnt = 0;  
      while(r < n)
      {
            mpp[s[r]]++;
            while(mpp.size() == 3)
            {
                mpp[s[l]]--;
                if(mpp[s[l]]==0)
                  mpp.erase(s[l]);
                l++;
                cnt = cnt + (n-r);
            }
            
            r++;
      }
      return cnt;  
    }
};