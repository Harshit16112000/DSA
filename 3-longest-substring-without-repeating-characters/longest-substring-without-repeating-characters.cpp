class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        set<char> st;

        while(r < s.size())
        {
            if(st.contains(s[r]))
            {
                
                st.erase(s[l]);
                l++;
            }
            
            else {
                st.insert(s[r]);
                r++;
                ans = max(ans, (int)st.size());
            }
        }

        return ans;
    }
};