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

        return parent[v] = findParent(parent[v]);
    }

    void Union(int u, int v) {
        // Get the Parent of the Node.
        int alt_u = findParent(u);
        int alt_v = findParent(v);
        if (alt_u != alt_v) {
            // If smaller node, gets 
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        DSU* dsu = new DSU(n);
        int extraedges = 0;
        for(auto it: connections)
        {
            int npu = dsu->findParent(it[0]);
            int npv = dsu->findParent(it[1]);
            if(npu == npv) 
              extraedges++; 
            
            dsu->Union(it[0], it[1]);
        }

        int components = 0;
        for(int i=0;i<dsu->parent.size();i++)
        {
            if(dsu->parent[i] == i)
              components++;
        }


        if(extraedges >= components-1)  return components -1;
        return -1;   
    }
};