class Solution {
public:
    void DFS(int node, vector<vector<int>> &adj, vector<int> &vis, int &cnt)
    {
        vis[node] = 1;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                cnt++;
                DFS(it, adj, vis, cnt );
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,0);

        vector<int> component;
        for(int i=0;i<n;i++)
        {
            
            if(vis[i] == 0)
            {
                int cnt = 1;
                DFS(i,adj,vis, cnt);
                component.push_back(cnt);
            }

        }

        vector<int> rightpSum(component.size(), 0);
        rightpSum[component.size() - 1] = component[component.size() -1];

        for(int i=component.size()-2; i>=0;i--)
        {
            rightpSum[i] = rightpSum[i+1] + component[i];

            cout << rightpSum[i] << " "; 
        }

        long long ans = 0;
        for(int i=0;i<rightpSum.size()-1;i++)
        {
            ans += (1LL * component[i] * rightpSum[i+1]); 
        }
        return ans;
    }
};