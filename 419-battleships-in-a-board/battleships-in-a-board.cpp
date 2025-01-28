class Solution {
public:
    void DFS(int row, int col, vector<vector<int>> &visited,
             vector<vector<char>> &board) {
        int rows = board.size();
        int cols = board[0].size();

        // Mark the current cell as visited
        visited[row][col] = 1;

        // Move horizontally to the right
        if (col + 1 < cols && board[row][col + 1] == 'X' && !visited[row][col + 1])
            DFS(row, col + 1, visited, board);

        // Move vertically downward
        if (row + 1 < rows && board[row + 1][col] == 'X' && !visited[row + 1][col])
            DFS(row + 1, col, visited, board);
    }

    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> visited(row, vector<int> (col,0));
        int cnt = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j] == 'X' && !visited[i][j])
                {
                    cnt++;
                     DFS(i,j,visited,board);
                }
            }
        }

        return cnt;   
    }
};