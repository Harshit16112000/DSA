class Solution {
private:
    bool isCyclic(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, vector<bool>& isSafe) {
        visited[node] = true;
        pathVisited[node] = true;
        
        for (int ne : graph[node]) {
            if (!visited[ne]) {
                if (isCyclic(ne, graph, visited, pathVisited, isSafe)) {
                    return true;
                }
            } else if (pathVisited[ne]) {
                return true;
            }
        }
        
        pathVisited[node] = false;
        isSafe[node] = true;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodeCount = graph.size();
        vector<bool> visited(nodeCount, false);
        vector<bool> pathVisited(nodeCount, false);
        vector<bool> isSafe(nodeCount, false);
        
        for (int node = 0; node < nodeCount; node++) {
            if (!visited[node]) {
                isCyclic(node, graph, visited, pathVisited, isSafe);
            }
        }
        
        vector<int> safeNodes;
        for (int node = 0; node < nodeCount; node++) {
            if (isSafe[node]) {
                safeNodes.push_back(node);
            }
        }
        
        return safeNodes;
    }
};