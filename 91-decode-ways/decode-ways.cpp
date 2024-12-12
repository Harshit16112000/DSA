class Solution {
public:
    
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        int ans = solve(s,0, dp);
        return ans;
    }

    int solve(string s, int idx, vector<int>&dp)
    {
        if (s[idx] == '0') return 0;
        if(idx == s.size())  return 1;
        if(dp[idx] != -1) return dp[idx];

        int onealphabet = solve(s, idx+1, dp);
        int twoalphabet = 0;
        if(idx + 1 < s.size() )
        {
            string way2 = s.substr(idx, 2);
            int num = stoi(way2);
            if(num <=26 && num > 0)
                twoalphabet = solve(s, idx+2, dp);
        }

        return dp[idx] = onealphabet + twoalphabet;
    }
};