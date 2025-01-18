class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        }
        // max Heap
         priority_queue <pair<double,int>> pq;
        pq.push({1.0, src});
        vector<double> dis(n,0.0);
        dis[src] = 1.0;

        while(!pq.empty())
       {
           auto it = pq.top();
           double currPor = it.first;
           int node = it.second;
           pq.pop();

           if (node == end) {
                return currPor;
            }

           for (auto i: adj[node])
           {
               int neigh = i.first;
               double edgeProb = i.second;
               double newProb = currPor * edgeProb;
               if(newProb > dis[neigh])
               {
                 dis[neigh] = newProb;
                 pq.push({newProb, neigh});
               }
              
           } 
       }
       return 0.0;
    }
};