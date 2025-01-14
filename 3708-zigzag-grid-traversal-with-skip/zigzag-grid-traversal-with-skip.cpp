class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> newGrid;
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<m;j++)
            {
                temp.push_back(grid[i][j]);
            }
            if(cnt%2 ==0)
            {
                newGrid.insert(newGrid.end(), temp.begin(), temp.end());
            }
            else {
                reverse(temp.begin(), temp.end());
                newGrid.insert(newGrid.end(), temp.begin(), temp.end());
            }
            cnt++;
        }

        vector<int> ans;
        
        for(int i=0;i<newGrid.size();i=i+2)
        {
            ans.push_back(newGrid[i]);
        }
        return ans;
    }
};