class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int,int>> mpp;
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowsCount(m,n);
        vector<int> colsCount(n,m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mpp[mat[i][j]] = {i,j};
            }
        }

        for(int i=0;i<arr.size();i++)
        {
            auto [r,c] = mpp[arr[i]];
            rowsCount[r]--;
            colsCount[c]--;

            if(rowsCount[r] == 0 || colsCount[c] == 0)
              return i;
        }

        return -1;

        return 2;
    }
};