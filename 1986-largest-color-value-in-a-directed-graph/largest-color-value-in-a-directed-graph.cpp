class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(colors.size());
        vector<int> inDegree(colors.size(), 0);
        
        for(int i=0;i<n;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++;
        }

        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i] == 0)
              q.push(i);
        }

        vector<vector<int>> color(colors.size(), vector<int> (26, 0));

        for(int i=0;i<colors.size();i++)
        {
            color[i][colors[i]-'a']++;
        }

        int visited = 0;
        int node_visited = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visited++;
            for(auto it: adj[node])
            {
                for(int i=0;i< 26;i++)
                {
                    color[it][i] = max(color[it][i], color[node][i] + (colors[it] - 'a' == i ? 1 : 0));
                }            
             inDegree[it]--;
             if(inDegree[it] == 0)
               q.push(it);     
            }

            
        }
        int maxi = 0;
            for(int i=0;i<colors.size();i++)
            {
                maxi = max(maxi, *max_element(color[i].begin(), color[i].end()));
            }

            if(visited != colors.size())  return -1;
            return maxi;
    }
};