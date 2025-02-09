class Solution {
public:
    vector<int> getKmp(string s, string a)
    {
        vector<int> lps(s.size(), 0);
        for(int i=1;i<s.size();i++)
        {
            int prevIndx = lps[i-1];
            while(prevIndx > 0 && s[i] != s[prevIndx])
            {
                prevIndx = lps[prevIndx-1];
            }
            lps[i] = prevIndx + (s[i] == s[prevIndx] ? 1 : 0);
        }
        
            return lps;
        
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string s1 = s + '#' + rev;
        vector<int>lps = getKmp(s1,rev);

        // for(int i=0;i<lps1.size();i++)
        // {
        //     cout << lps1[i] << " ";
        // }

        string ans = "";
        for(int i = 0; i < rev.size() - lps[lps.size() -1];i++)
        {
            ans += rev[i];
        }

        return ans + s;
    }
};