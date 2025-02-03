class Solution {
public:
    void DFS(int node, vector<vector<int>>& graph, vector<int>& path,
             vector<vector<int>>& result) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            result.push_back(path);

        } else {
            for (auto it : graph[node]) {

                DFS(it, graph, path, result);
                path.pop_back();
            }
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        DFS(0, graph, path, result);
        return result;
    }
};