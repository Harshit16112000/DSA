class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

       int m = grid.size();
       int n = grid[0].size();
       int cnt = 1;
       
       // If distance is of 1, then mostly go with //BFS only
       vector<vector<int>> vis(m, vector<int> (n,1e9));
        vis[0][0] = 1;
       queue< pair < pair <int,int> , int>> q;
       q.push({{0,0},cnt});
       
       if(n==1 && m==1 && grid[0][0]==0){
            return 1;
        }
        if(grid[0][0] == 1)
          return -1;

       while(!q.empty())
       {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            // To go 8 directionall
            for(int i =-1; i<2;i++)
            {
                for(int j= -1; j<2;j++)
                {
                    int nrow = row +  i;
                    int ncol = col + j;

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] ==  0 && steps + 1 < vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1 + steps;
                        if(nrow == m-1 && ncol == n-1)
                           return steps+ 1;
                        q.push({{nrow,ncol}, steps + 1 });
                    }
                }
            }
       }
       return -1; 
    }
};