class Solution {
public:
    int MOD = 1e9 + 7;
    int ways(vector<string>& pizza, int k) {
        int row = pizza.size();
        int col = pizza[0].size();

        vector<vector<vector<int>>> dp(k, vector(row, vector(col,-1)));
        vector<vector<int>> pSum(row + 1, vector<int>(col + 1, 0));

        for (int i = row-1; i  >= 0; i--) {
            for (int j = col -1; j >= 0; j--) {
                pSum[i][j] = pizza[i][j] == 'A' ? 1 : 0;
                   pSum[i][j] += pSum[i+1][j] 
                   + pSum[i][j+1] - pSum[i+1][j+1];
                   
            }
        }

        return solve(0,0, k-1,dp, pSum,  pizza);

        
    }

    int solve(int r, int c, int k, vector<vector<vector<int>>> &dp, vector<vector<int>> &pSum, vector<string>& pizza)
    {
        if (pSum[r][c] == 0) return 0;  
        if(k ==0)   return 1;

        if(dp[k][r][c] != -1)  return dp[k][r][c];
        int ans = 0;
        for(int nr=r+1;nr< pizza.size();nr++)
        {
            if(pSum[r][c] - pSum[nr][c] > 0) 
               ans = (ans + solve(nr,c,k-1,dp,pSum,pizza))%MOD;
        }

        for(int nc =c+1;nc < pizza[0].size(); nc++)
        {
            if(pSum[r][c] - pSum[r][nc] > 0)
               ans = (ans + solve(r,nc,k-1, dp, pSum, pizza))%MOD;
        }

        return dp[k][r][c] = ans;
    }
};