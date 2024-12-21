class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n < 2) return 1;

        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        vector<long long> nodeValues(values.begin(), values.end());

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i] == 1)
               q.push(i);
        }

        int cnt = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            inDegree[cur]--;
            long long addValue = (nodeValues[cur] % k == 0) ? 0 : nodeValues[cur];
            if (addValue == 0) cnt++;

            for (int neighbor : adj[cur]) {
                if (inDegree[neighbor] > 0) {
                    inDegree[neighbor]--;
                    nodeValues[neighbor] += addValue;
                    if (inDegree[neighbor] == 1) q.push(neighbor);
                }
            }
        }
        return cnt;
    }
};