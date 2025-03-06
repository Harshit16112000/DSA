class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        cout << rows * cols << " ";
        vector<int> mat(rows * cols + 1, 0);

        for (int i = 0; i < grid.size(); i++)
        {
            for(int j=0;j<grid[0].size(); j++)
            {
                mat[grid[i][j]]++;
            }    
        }

        int zero = 0;
        int two = 0;
        for(int i=1;i<mat.size();i++)
        {
            if(mat[i] == 0)  zero = i;
            if(mat[i] == 2)   two = i;
        }
        return {two, zero};
    }
};