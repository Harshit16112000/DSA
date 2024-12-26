class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> mpp;

        int maxi = 0;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
            maxi = max(maxi, mpp[s[i]]);
        }

        unordered_map<char,int> mpp2 = mpp;
        string str;
        for(int i=0;i<s.size();i++)
        {
            if(mpp2[s[i]] == maxi)
            {
                
                if(mpp[s[i]] == 1)  str.push_back(s[i]);
                mpp[s[i]]--;
            }
        }

        return str;
    }
};