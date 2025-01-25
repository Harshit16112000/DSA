class Solution {
public:
    void DFS(vector<int> &vis,int index,string &s, string &stx,vector<int>& tempans,
    vector<vector<int>>& graph)
    {
        vis[index] = 1;
        stx += s[index];
        tempans.push_back(index);
        for(auto it: graph[index])
        {
            if(!vis[it])
              DFS(vis,it,s,stx,tempans, graph);
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> graph(s.size());
        for(int i=0;i<pairs.size();i++)
        {
            graph[pairs[i][0]].push_back(pairs[i][1]);
            graph[pairs[i][1]].push_back(pairs[i][0]);
        }

        vector<int> vis(s.size() , 0);
        string ans;

        for(int i=0;i<s.size();i++)
        {
            if(!vis[i])
            {
                string stx = "";
                vector<int> tempans;
                DFS(vis,i,s,stx,tempans, graph);
            
                sort(tempans.begin(), tempans.end());
                sort(stx.begin(), stx.end());

                for(int j=0;j<stx.size();j++){
                    s[tempans[j]]=stx[j];
                }
            }
        }
        return s;

    }
};