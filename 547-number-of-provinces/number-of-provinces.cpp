class DSU {
public:
    vector<int> rank;
    vector<int> parent;

    DSU(int number) {
        rank.resize(number, 0);
        parent.resize(number, 0);
        for (int i = 0; i < number; i++) {
            parent[i] = i;
        }
    }

    int findParent(int v) {
        if (v == parent[v])
            return v;

        return findParent(parent[v]);
    }

    void Union(int u, int v) {
        int alt_u = findParent(u);
        int alt_v = findParent(v);
        if (alt_u != alt_v) {
            if (rank[alt_u] > rank[alt_v]) {
                parent[alt_v] = alt_u;
            } else if (rank[alt_v] > rank[alt_u]) {
                parent[alt_u] = alt_v;
            } else {
                parent[alt_u] = alt_v;
                rank[alt_v]++;
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        DSU* dsu = new DSU(n);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j])
                   dsu->Union(i,j);
            }
        }

        for(int i=0;i<dsu->parent.size();i++)
        {
            if(dsu->parent[i] == i)
              cnt++;
        }

        return cnt;
    }
};