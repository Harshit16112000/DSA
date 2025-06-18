class Solution {
public:
    int dpProblem(int ind1, int ind2, string &word1, string &word2, vector<vector<int>> &dp)
    {
     if(ind2 >= word2.size()) return word1.size() - ind1;  // Delete remaining in word1
        if(ind1 >= word1.size()) return word2.size() - ind2;  // Insert remaining in word2

        if(dp[ind1][ind2] != -1)  return dp[ind1][ind2];


        if(word1[ind1] == word2[ind2])
        {
            return dp[ind1][ind2] = dpProblem(ind1+1,ind2+1, word1, word2, dp);
        }
        return dp[ind1][ind2] = 1 + min({dpProblem(ind1+1, ind2+1, word1, word2, dp) , dpProblem(ind1+1, ind2, word1, word2, dp), dpProblem(ind1, ind2+1, word1, word2, dp) });
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return dpProblem(0,0,word1,word2,dp);
    }
};