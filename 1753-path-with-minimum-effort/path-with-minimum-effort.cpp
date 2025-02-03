class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dis(rows, vector<int>(cols, 1e9));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        dis[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == rows-1 && c == cols-1) {
                return distance;
            }

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) 
                {
                    int efforts = max(abs(heights[r][c] - heights[nr][nc]), distance);
                    if(efforts < dis[nr][nc])
                    {
                        dis[nr][nc] = efforts;
                        pq.push({efforts,{nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};