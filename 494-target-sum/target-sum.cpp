class Solution {
public:
    int dpProblem(int index, int target, vector<int>& nums, vector<vector<int>>& dp, int offset, int maxSum) {
        // If out of range after applying offset
        if (target + offset < 0 || target + offset > maxSum) return 0;

        if (index == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        if (dp[index][target + offset] != -1) {
            return dp[index][target + offset];
        }

        int add = dpProblem(index + 1, target - nums[index], nums, dp, offset, maxSum);
        int subtract = dpProblem(index + 1, target + nums[index], nums, dp, offset, maxSum);

        return dp[index][target + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int offset = sum;
        int maxSum = 2 * sum;

        if (target > sum || target < -sum) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(maxSum + 1, -1));

        return dpProblem(0, target, nums, dp, offset, maxSum);
    }
};
