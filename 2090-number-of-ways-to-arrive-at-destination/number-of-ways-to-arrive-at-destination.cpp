class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        // Min Heap
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<>> pq;
        // Solve, First Path With Minimum Efforts
        // Node, Weight
        pq.push({0,0});
        vector<long long> dis(n, LONG_MAX);
        vector<long long> ways(n,0);
        long long mod = (long long)1e9+7;

        dis[0] = 0;
        ways[0] = 1;

        while(!pq.empty())
        {
            auto it = pq.top();
            long long dist =  it.first;
            long long node = it.second;
            pq.pop();

            for(auto it: adj[node])
            {
                long long adjSrc = it.first;
                long long wt = it.second;
                if( dist + wt  < dis[adjSrc])
                {
                    dis[adjSrc] = wt + dist;
                    pq.push({wt + dist, adjSrc});
                    ways[adjSrc] = ways[node];
                }
                else if(dist + wt == dis[adjSrc])
                {
                    ways[adjSrc] = (ways[adjSrc] + ways[node])% mod;
                }
            }

            
        }
        return ways[n-1];
    }
};