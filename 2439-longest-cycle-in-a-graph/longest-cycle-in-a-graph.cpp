class Solution {
public:
    int ans = -1;
    void DFS(int node, unordered_map<int,int> &mpp,vector<int> &edges, vector<int>&vis)
    {
        
        vis[node] = 1;
        int neigh = -1;
        neigh = edges[node];

        if(neigh != -1 && !vis[neigh])
        {
            mpp[neigh] = mpp[node] + 1;
            DFS(neigh, mpp, edges, vis);
        }
        else if(neigh != -1 && mpp.count(neigh))
        {
            ans = max(ans, mpp[node] - mpp[neigh] + 1);
        }
        
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        

        vector<int> vis(n,0);

        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                unordered_map<int,int> mpp;
                mpp[i] = 1;
               DFS(i,mpp,edges, vis);
            }   
        }
        return ans;
    }
};