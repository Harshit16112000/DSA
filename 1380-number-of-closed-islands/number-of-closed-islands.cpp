class Solution {
public:
    void DFS(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        grid[row][col] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 0 && !vis[nr][nc])
            {
                DFS(nr,nc,grid, vis);
            }
        }
     }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int> (col,0));
        for(int i=0;i<col;i++)
        {
            if(grid[0][i] == 0 && vis[0][i] == 0)
              DFS(0,i,grid,vis);

              if(grid[row-1][i] == 0 && vis[row-1][i] == 0)
              DFS(row-1,i,grid,vis);
        }

        for(int i=0;i<row;i++)
        {
            if(grid[i][0] == 0 && vis[i][0] == 0)
              DFS(i,0,grid,vis);

              if(grid[i][col-1] == 0 && vis[i][col-1] == 0)
              DFS(i,col-1,grid,vis);
        }

        int cnt = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 0 && !vis[i][j])
                {
                    DFS(i,j,grid,vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};