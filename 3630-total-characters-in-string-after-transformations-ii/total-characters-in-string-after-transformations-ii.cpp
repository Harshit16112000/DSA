class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> multiply(vector<vector<int>> x, vector<vector<int>> y) {
        vector<vector<int>> result(26, vector<int>(26));
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                for(int k = 0; k < 26; k++) {
                    result[i][j] = (result[i][j] + (x[i][k] * 1LL * y[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }
    vector<vector<int>> matrixFastMult(vector<vector<int>> &x, int t) {
        if(t == 1) 
            return x;
        vector<vector<int>> y = matrixFastMult(x, t / 2);
        if(t % 2 == 0)
            return multiply(y, y);
        return multiply(multiply(y, y), x);
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        vector<vector<int>> matrix(26, vector<int>(26));
        for(int i = 0; i < 26; i++) {
            for(int j = 1; j <= nums[i]; j++) {
                matrix[i][(i + j) % 26]++;
            }
        }
        matrix = matrixFastMult(matrix, t);
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            int sum = 0;
            for(int j = 0; j < 26; j++) {
                sum = (sum + matrix[i][j]) % MOD;
            }
            ans = (ans + (sum * 1LL * freq[i]) % MOD) % MOD;
        }
        return ans;
    }
};