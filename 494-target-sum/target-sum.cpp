class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // dp[i][sum] = number of ways to make 'sum' using first 'i' elements
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;  // base case: one way to make sum=0 with 0 elements

        for (int i = 0; i < n; i++) {
            for (auto& [currSum, count] : dp[i]) {
                int add = currSum + nums[i];
                int subtract = currSum - nums[i];
                dp[i + 1][add] += count;
                dp[i + 1][subtract] += count;
            }
        }

        return dp[n][target];
    }
};
