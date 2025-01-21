class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long total = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            total +=  grid[0][i];
        }

        long long bottomRowCount = 0;
        long long ans = 0;
        for(int i=0;i<grid[0].size();i++)
        {
            total -= grid[0][i];
            bottomRowCount += grid[1][i];

            ans = max(ans, min(total, bottomRowCount) );
        }

        

        return ans;
    }
};