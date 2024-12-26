class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if (roads.empty()) {
            return 0; // No roads, no cost
        }

        int n = roads.size() + 1; // Total number of nodes (roads + 1)
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0); // Degree of each node
        vector<int> reps(n, 1);  // Each node starts with 1 representative

        // Build adjacency list and initialize degrees
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }

        // Identify leaf nodes
        deque<int> leaves;
        for (int i = 1; i < n; ++i) {
            if (degree[i] == 1) { // Node with degree 1 is a leaf
                leaves.push_back(i);
            }
        }

        long long fuelCost = 0;

        // Process leaf nodes
        while (!leaves.empty()) {
            int cur = leaves.front();
            leaves.pop_front();

            for (int neighbor : adj[cur]) {
                if (degree[neighbor] > 0) { // Process only if the neighbor is still active
                    // Add representatives to the neighbor
                    reps[neighbor] += reps[cur];

                    // Calculate fuel cost
                    fuelCost += (reps[cur] + seats - 1) / seats;

                    // Reduce the degree of the neighbor
                    degree[neighbor]--;

                    // If the neighbor becomes a leaf, add it to the queue
                    if (degree[neighbor] == 1 && neighbor != 0) {
                        leaves.push_back(neighbor);
                    }
                }
            }

            // Mark the current node as processed
            degree[cur] = 0;
        }

        return fuelCost;
    }
};
