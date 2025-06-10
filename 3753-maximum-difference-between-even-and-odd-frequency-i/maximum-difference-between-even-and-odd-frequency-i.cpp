class Solution {
public:
    int maxDifference(string s) {
     unordered_map<int,int> mpp;

        for(int i=0;i<s.size();i++)
            {
                mpp[s[i]-'a']++;
            }

        int odd = 0;
        int even = INT_MAX;
        for(auto &[key,value] : mpp)
            {
                if(value%2 == 0)
                     even = min(value,even);
                else
                    odd = max(value, odd);
            }

     //   cout << even << " " << odd ;

        return  odd- even;
    }
};