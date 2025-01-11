class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<int,int> mpp;
        if(k > s.size()) return false;
        for(int i=0;i<s.size();i++)
        {
            mpp[(s[i]-'a')]++;
        }

        int minK = 0;
        for(auto const&[key,value] : mpp)
        {
            if(value %2 == 1)  
               minK++;
        }

        if(minK <= k)  return true;
        return false;
    }
};