class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, pair<int,int>>> q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 1)
                q.push({0, {i,j}});
            }
        }

        vector<vector<int>> vis(row, vector<int> (col, 0));

    
        while(!q.empty())
        {
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c =  it.second.second;
            q.pop();

            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < row && nc >=0 && nc < col && !vis[nr][nc] && grid[nr][nc] != 1)
                {
                    vis[nr][nc] = dis + 1;
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cnt = max(cnt, vis[i][j]);
            }
        }
        if(cnt == 0)  return -1;
        return cnt;
    }
};