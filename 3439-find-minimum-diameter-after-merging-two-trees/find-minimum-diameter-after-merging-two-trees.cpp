class Solution {
public:
    vector<vector<int>> makeGraph(vector<vector<int>>& edges1) 
    {
        int n = edges1.size();
        vector<vector<int>> adjNode(n+1);
        for(int i=0;i<edges1.size();i++)
        {
            adjNode[edges1[i][0]].push_back(edges1[i][1]);
            adjNode[edges1[i][1]].push_back(edges1[i][0]);
        }
        return adjNode;
    }

    void findFarthest(int node, int parent, int dis, vector<vector<int>>&graph,pair<int,int>& res)
    {
        if(dis >res.first)
           res = {dis, node};
        for(auto it: graph[node])
        {
            if(it != parent)
            {
                findFarthest(it, node, dis +1, graph, res);
            }
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)     
    {
        auto graph1 = makeGraph(edges1);
        auto graph2 = makeGraph(edges2);
        // It has FarthestNode {dist , node}
        pair<int,int> res = {INT_MIN,-1}, res2 = {INT_MIN, -1};

        // Calculating the Farthest Distance from node 0 and value being upadted in Graph 
        findFarthest(0,-1,0,graph1, res);
        // From that furthest distance calculating other end of farthest distance
        findFarthest(res.second,-1,0,graph1, res2);
        int diameter1 = res2.first;

        res = {INT_MIN,-1};
        res2 = {INT_MIN, -1};

        findFarthest(0,-1,0,graph2, res);
        findFarthest(res.second,-1,0,graph2, res2);
        int diameter2 = res2.first;

        int ans = (diameter1 + 1)/2 + (diameter2 + 1)/2 + 1;
        // WHy need to calculate the maximum, is still doubt, need to check that.
        return max({diameter1, diameter2, ans});

    }
};