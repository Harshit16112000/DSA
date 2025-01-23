class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> ans(row, vector<int> (col, -1));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j])
                {
                    q.push({0,{i,j}});
                    ans[i][j] = 0;
                }
            }
        }
        

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int h = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && ans[nr][nc] == -1)
                {
                    ans[nr][nc] = h+1;        
                    q.push({h+1, {nr,nc}});
                }
            }
        }

        return ans;
    }
};