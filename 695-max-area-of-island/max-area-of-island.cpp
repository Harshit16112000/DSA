class Solution {
public:
    void DFS(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid, int& ans, int value) {
        vis[row][col] = 1;
        ans++;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        if (value == 0) {
            grid[row][col] = 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                !vis[nr][nc] && grid[nr][nc] > 0) {
                DFS(nr, nc, vis, grid, ans, value);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        int maxi = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                    if (grid[i][j] > 0 && !vis[i][j]) {
                        int ans = 0;
                        int value = 1;
                        DFS(i, j, vis, grid, ans, value);
                        maxi = max(maxi, ans);
                    }
                
            }
        }

        return maxi;
    }
};