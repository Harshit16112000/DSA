class Solution {
public:
    int dpProblem(int index1, int index2, string text1, string text2,
                  vector<vector<int>>& dp) {
        if (index1 >= text1.size())
            return 0;
        if (index2 >= text2.size())
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1] == text2[index2]) {
            return 1 + dpProblem(index1 + 1, index2 + 1, text1, text2, dp);
        }
        int skip1 = dpProblem(index1 + 1, index2, text1, text2, dp);
        int skip2 = dpProblem(index1, index2 + 1, text1, text2, dp);

        return dp[index1][index2] = max(skip1, skip2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        if (n1 == 1 && n2 == 1) {
            if (text1[0] == text2[0])
                return 1;
            return 0;
        }
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, -1));

        for (int i = 0; i < n2; i++)
            dp[0][i] = 0;
        for (int i = 0; i < n1; i++)
            dp[i][0] = 0;
        string s = "";
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

       
        int i = n1, j = n2;
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                s += text1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(s.begin(), s.end());
        cout << s << " ";

        return dp[n1][n2];
    }
};