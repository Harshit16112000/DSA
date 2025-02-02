class DSU {
    public:
    vector<int> rank, parent;

    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if (n == parent[n])
            return n;
        return parent[n] = findParent(parent[n]);
    }

    void Union(int u, int v) {
        int lu = findParent(u);
        int lv = findParent(v);

        if (lu != lv) {
            if (rank[lu] < rank[lv]) {
                parent[lu] = lv;
            } else if (rank[lv] < rank[lu]) {
                parent[lv] = lu;
            } else {
                parent[lv] = lu;
                rank[lu]++;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> mpp;
        vector<vector<string>> result;
        DSU *dsu = new DSU(accounts.size());
        for(int i=0;i<accounts.size(); i++)
        {
            // First index contains name, not email
            for(int j=1;j<accounts[i].size();j++)
            {
                if(!mpp.contains(accounts[i][j]))
                {
                    mpp[accounts[i][j]] = i;
                }
                else {
                    dsu->Union(i, mpp[accounts[i][j]]);
                }
            }
        }

        unordered_map<int, set<string>> mergedAccounts;
        for (auto& [email, idx] : mpp) {
            int root = dsu->findParent(idx);
            mergedAccounts[root].insert(email);
        }

        for (auto& [idx, emails] : mergedAccounts) {
            vector<string> account;
            account.push_back(accounts[idx][0]); 
            account.insert(account.end(), emails.begin(), emails.end()); 
            result.push_back(account);
        }

        return result;
    }
};