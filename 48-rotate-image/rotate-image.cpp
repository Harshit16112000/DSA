class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix.size(), vector<int> (matrix.size(),0));
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result.size();j++)
            {
                result[j][matrix.size() - i -1] = matrix[i][j];
            }
        }
        matrix  = result;
    }
};