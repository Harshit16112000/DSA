class Solution {
public:
    int solve(int idx, int k, vector<vector<int>> &dp, vector<int>& nums, vector<int>& pSum) {
        if (k == 1) return pSum[nums.size()] - pSum[idx]; // Base case: one partition
        if (dp[idx][k] != -1) return dp[idx][k]; // Return memoized result

        int result = INT_MAX;

        for (int j = idx; j < nums.size() - k + 1; j++) {
            int currSum = pSum[j + 1] - pSum[idx];
            int largestSum = max(currSum, solve(j + 1, k - 1, dp, nums, pSum));
            result = min(result, largestSum);

            // Early stopping if currSum exceeds the current result
            if (currSum >= result) break;
        }

        return dp[idx][k] = result;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Compute prefix sums
        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + nums[i];
        }

        // Initialize DP table
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // Solve from the beginning
        return solve(0, k, dp, nums, pSum);
    }
};
