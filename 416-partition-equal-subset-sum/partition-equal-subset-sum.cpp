class Solution {
public:
    bool createPartition(int index, int target, vector<vector<int>> & dp, vector<int> &nums)
    {
        if(target == 0 )  return true;
        if(index == nums.size() -1)  return nums[index] == target;
        if(dp[index][target] != -1)  return dp[index][target];    
        bool nonTake = createPartition(index+1, target, dp, nums);
        bool take = false;
        if(target > nums[index])
        {
            take = createPartition(index+1, target- nums[index], dp, nums);
        }

        // Possibility whether to take or nonTake
        return dp[index][target] = take || nonTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        if(sum%2 == 1)  return false;
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return createPartition(0, target, dp, nums);
    }
};