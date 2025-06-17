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

    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        int n = word1.size();
        int m = word2.size();

        int ans = dpProblem(0,0,word1,word2,dp);

        return (n + m - (2* ans));    
    }
};