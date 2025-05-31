class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> straightBoard(n * n + 1, -1);
        bool leftToRight = true;
        int idx = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    straightBoard[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    straightBoard[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

            
            vector<int> vis(n*n+1, 0);
            queue<pair<int,int>> q;
            q.push({1,0});
            int mini = 0;
            vis[1] = 1;
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                int curr = it.first;
                int move = it.second;
                if(curr == n*n)  {
                    return move;
                }
                for(int i=1; i <= 6;i++)
                {
                    int next = curr + i;
                    
                    if(next > n*n) continue;    
                    if(!vis[next] ) {
                        vis[next] = 1;
                        if(straightBoard[next] != -1)
                        {
                            q.push({straightBoard[next], move + 1});
                        }
                        else {
                            q.push({next, move + 1});
                        }
                    }
                }
            }
            return -1;
        }
    
};