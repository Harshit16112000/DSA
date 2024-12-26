class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if (roads.empty()) {
            return 0; // No roads, no cost
        }

        int n = roads.size() + 1; // Number of nodes
        vector<unordered_set<int>> adj(n);
        vector<int> reps(n, 1); // Each node starts with 1 representative
        
        // Build adjacency list
        for (auto& road : roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        // Initialize deque with leaf nodes
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) {
                leaves.push(i);
            }
        }

        // Process leaf nodes
        while (!leaves.empty()) {
            int cur = leaves.front();
            leaves.pop();

            if (cur == 0) {
                continue; // Skip the capital node
            }

            // Get the neighbor and remove the current node from adjacency list
            int nbr = *adj[cur].begin();
            adj[cur].erase(nbr);
            adj[nbr].erase(cur);

            // Add representatives to the neighbor
            reps[nbr] += reps[cur];

            // If the neighbor becomes a leaf, add it to the queue
            if (adj[nbr].size() == 1) {
                leaves.push(nbr);
            }
        }

        // Calculate the total fuel cost
        long long fuelCost = 0;
        for (int i = 1; i < n; ++i) { // Skip the capital (node 0)
            fuelCost += (reps[i] + seats - 1) / seats; // Ceil(reps / seats)
        }

        return fuelCost;
    }
};
