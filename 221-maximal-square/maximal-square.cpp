class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int> (col, -1));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    if(matrix[i][j] == '0')
                       dp[i][j] = 0;
                    else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                }
            }
        }

            int maxi = 0;

            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    
                    maxi = max(maxi, dp[i][j]);
                }
                cout << endl;
            }

            return maxi * maxi; 
        
    }
};