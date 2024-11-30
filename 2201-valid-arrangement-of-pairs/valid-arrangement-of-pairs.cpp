class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, int node, vector<int>& path) {
        // Traverse all edges from the current node
        while (!graph[node].empty()) {
            int nextNode = graph[node].back();
            graph[node].pop_back(); // Remove the edge
            dfs(graph, nextNode, path); // Recursively visit the next node
        }
        // During the post recurrsion
                cout << node;
        path.push_back(node);
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;
        vector<vector<int>> ans;
        for(auto it: pairs)
        {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }
        int startNode = pairs[0][0];
        for( auto it: pairs)
        {
            if(outDegree[it[0]] > inDegree[it[0]]) {
            startNode = it[0];
            break;
            }
        }

        vector<int> path;

        dfs(graph, startNode,path);

        reverse(path.begin(), path.end());
        
        for(int i=0;i<path.size()-1;i++)
        {
            ans.push_back({path[i], path[i+1]});
        }
        return ans;

        
    }
};
    
    