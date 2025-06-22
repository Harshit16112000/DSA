class Solution {
public:
    bool dpProblem(int ind1, int ind2, string& s, string& p,
                   vector<vector<int>>& dp) {
        if (ind1 == s.size() && ind2 == p.size())
            return true;
        if (ind2 == p.size())
            return false;    

        if (ind1 == s.size()) {
            for (int i = ind2; i < p.size(); i++) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }

         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        bool ans = false;

        if (p[ind2] == '?') {
            ans = dpProblem(ind1 + 1, ind2 + 1, s, p, dp);
        } else if (p[ind2] == '*') {
            ans = dpProblem(ind1 + 1, ind2, s, p, dp) ||
                 dpProblem(ind1 + 1, ind2 + 1, s, p, dp) ||
                  dpProblem(ind1, ind2 + 1, s, p, dp);
        } else {
            if (p[ind2] != s[ind1])
                ans = false;
            else
                ans = dpProblem(ind1+1, ind2+1, s, p, dp);
        }

        return dp[ind1][ind2] = ans;
    }

    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return dpProblem(0, 0, s, p, dp);
    }
};