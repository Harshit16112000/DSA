class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, vector<unordered_map<int, int>>& dp) {
        if (i == nums.size()) {
            return sum == 0 ? 1 : 0;
        }
        if (dp[i].count(sum)) return dp[i][sum];

        int add = solve(i + 1, sum - nums[i], nums, dp);
        int subtract = solve(i + 1, sum + nums[i], nums, dp);

        return dp[i][sum] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        return solve(0, target, nums, dp);
    }
};
