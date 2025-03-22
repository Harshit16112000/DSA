class Solution {
public:
    void bfs(int index, vector<vector<int>> &adj, vector<int> &node, vector<bool> &vis)
    {
        queue<int> q;
        q.push(index);
        vis[index] = true;

        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            node.push_back(n);
            for(auto it:adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }            
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(n,false);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<int> node;
                bfs(i,adj,node, vis);
                bool cnt = true;
                
                for(int j=0;j<node.size();j++)
                {
                    if(node.size()-1 != adj[node[j]].size())  {cnt = false; break;}    
                }
                if(cnt)  ans++;
            }
        }

        return ans;




    }
};