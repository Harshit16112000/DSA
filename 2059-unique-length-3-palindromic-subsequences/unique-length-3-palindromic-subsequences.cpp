class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int,int>> mpp;
        int n = s.size();

        for(char c='a'; c <='z';c++)
        {
            mpp[c] = {-1,-1};
        }

        for (int i = 0; i < n; i++) {
            if(mpp[s[i]].first == -1)
            {
                mpp[s[i]] = {i,-1};
            }
            else {
                mpp[s[i]].second = i;
            }
        }
        int ans = 0;
        for(const auto&[key,value] : mpp)
        {
            if(value.first != -1  && value.second != -1)
            {
                set<char> st;
                for(int i=value.first + 1; i<value.second;i++)
                {
                    st.insert(s[i]);
                }
                if(st.empty())  continue;
                ans += st.size();
            }
            
        }

        return ans;
    }
};