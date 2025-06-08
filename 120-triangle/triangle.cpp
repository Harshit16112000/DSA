class Solution {
public:
    int solve(int row, int col,vector<vector<int>>& triangle, vector<vector<int>>& dp )
    {
        if(row == triangle.size()-1)
           return triangle[row][col];
        
        if (dp[row][col] != -1)
             return dp[row][col];
        int row1 =  triangle[row][col] + solve(row+1,col, triangle,dp) ;
        int row2 =  triangle[row][col] + solve(row+1,col+1, triangle,dp);
        return dp[row][col] =  min(row1,row2);
        //return dp[row][col];

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));

        return solve(0,0,triangle,dp);
    }

    

};