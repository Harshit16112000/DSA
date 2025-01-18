class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>> , greater<>> pq;
        vector<vector<int>> cost(row, vector<int> (col, INT_MAX));
        vector<vector<int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        cost[0][0] = 0;
        pq.push({0,0,0});

        while(!pq.empty())
        {
            auto it = pq.top();
            int dis = it[0];
            int r = it[1];
            int c = it[2];
            pq.pop();

            if (dis > cost[r][c]) continue;
            
            for(int dir = 0; dir < 4;dir++)
            {
                int nr = r + direction[dir][0];
                int nc = c + direction[dir][1];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col)
                {
                    int newcost =dis + (grid[r][c] == dir +1 ? 0 : 1);
                    if(newcost < cost[nr][nc])
                    {
                        cost[nr][nc] = newcost;
                        pq.push({newcost, nr,nc});
                    }
                }
            }
        }

        return cost[row-1][col-1]; 
    }
};