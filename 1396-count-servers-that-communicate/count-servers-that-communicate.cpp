class Solution {
public:
    int cnt = 0;
    void solve(int row, int col, vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[row][i] == 1) {
                sum++;
            }
        }

        if (sum > 1) {
            cnt++;
            return;
        }
        sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][col] == 1) {
                sum++;
            }
        }
        if (sum > 1) {
            cnt++;
            return;
        }
    }

    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    solve(i, j, grid);
                }
            }
        }

        return cnt;
    }
};