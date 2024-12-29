class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
     int row = grid.size();
     int col = grid[0].size();

     int j = 0;
     int ans = 0;
     while(j < col)
     {
        int ele = grid[0][j];
        for(int i=1;i<row;i++)
        {
            if(grid[i][j] <= grid[i-1][j])
            {
                ans += (grid[i-1][j] - grid[i][j] + 1);
                grid[i][j] = 1 + grid[i-1][j];
            }
        }
        j++;
     }  

     return ans;
    }
};