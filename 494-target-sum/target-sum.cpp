class Solution {
public:
    int dpProblem(int index, int target, vector<int>& nums, unordered_map<string, int>& memo) {
        if (index == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        string key = to_string(index) + "|" + to_string(target);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int add = dpProblem(index + 1, target - nums[index], nums, memo);
        int subtract = dpProblem(index + 1, target + nums[index], nums, memo);

        return memo[key] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return dpProblem(0, target, nums, memo);
    }
};
