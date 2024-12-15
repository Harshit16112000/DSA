class Solution {
public:
    double DFS(string start, string end, unordered_map<string,unordered_map<string,double>> &mpp,
    unordered_set<string>& visited) {
        if (mpp.find(start) == mpp.end()) return -1.0;

        if (mpp[start].find(end) != mpp[start].end()) {
            return mpp[start][end];
        }
        visited.insert(start);
        for (const auto& pair : mpp[start]) {
        if (mpp.find(start) != mpp.end()) { 
             if (visited.find(pair.first) == visited.end()) {
            double res = DFS(pair.first, end, mpp, visited);
                if (res != -1.0) {
                    return pair.second * res;
                    }
                 }                
            }
        }
        return -1;

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mpp;
        vector<double> result;
        for(int i=0;i<equations.size();i++)
        {
            string from = equations[i][0];
            string to = equations[i][1];
            mpp[from][to] = values[i];
            mpp[to][from] = 1.0/ values[i];
        }

        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> visited;
            double ans = DFS(queries[i][0], queries[i][1], mpp, visited);
            result.push_back(ans);
        }
        return result;
    }
};