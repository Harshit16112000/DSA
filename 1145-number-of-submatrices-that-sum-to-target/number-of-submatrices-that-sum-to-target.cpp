class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> pSum(row, vector<int> (col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0; j<col; j++)
            {
                pSum[i][j] = matrix[i][j];
                if(j > 0)
                  pSum[i][j] += pSum[i][j-1];
            }
        }

        int cnt = 0;
        for(int colStart = 0; colStart < col; colStart++)
        {
            for(int colEnd =colStart; colEnd < col; colEnd++)
            {
                for(int rowStart = 0; rowStart < row; rowStart++)
                {
                    int sum = 0;
                    for(int rowEnd = rowStart; rowEnd < row; rowEnd++)
                    {
                        sum += pSum[rowEnd][colEnd] - (colStart ? pSum[rowEnd][colStart - 1] : 0);
                        if(sum == target) cnt++;
                    }
                    
                }
            }
        }

        return cnt;
    }

};