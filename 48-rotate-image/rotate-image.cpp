class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top = 0;
        int right = 0;
        int left = matrix.size();
        int bottom = matrix[0].size();
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int j=0;j<bottom;j++)
        {
            reverse(matrix[j].begin(), matrix[j].end());
        }
    }
};