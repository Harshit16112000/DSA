class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0;i < flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<> > pq;
        vector<int> dis(n, INT_MAX);
        // stops, node
        pq.push({0,src,0});
        dis[src] = 0;

        while(!pq.empty())
        {
            auto i = pq.top();
            pq.pop();
            int stops = i[0];
            int node = i[1];
            int wt = i[2];

            if(stops > k)  continue;

            for(auto it: adj[node] )
            {
                int adjSrc = it.first;
                int adjW = it.second;
                if(adjW + wt < dis[adjSrc] && stops <= k) 
                {
                    dis[adjSrc] = adjW + wt;
                    pq.push({stops+1,adjSrc, dis[adjSrc]});
                }
            }
        }
        if(dis[dst] == INT_MAX)  return -1;
            return dis[dst];
    }
};