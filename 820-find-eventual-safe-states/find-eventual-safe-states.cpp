class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Question Comes up to look for Cyclic Component in DAG.
        // Apart from Cyclic Component everything is ans.
        // IN DAG, best way is Topo Sort.
        int n = graph.size();
        vector<int> inDegree(n, 0);
        vector<int> ans;
        vector<vector<int>> revGraph(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                revGraph[it].push_back(i);
                inDegree[i]++;
            }
        }

        for (int i = 0; i < inDegree.size(); i++) {
            cout << inDegree[i] << " ";
        }

        for (int node = 0; node < n; node++) {
                        if (inDegree[node] == 0) {
                                q.push(node);
                ans.push_back(node);
                           
            }
                   
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : revGraph[node]) {

                inDegree[it]--;
                if (inDegree[it] == 0) {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};