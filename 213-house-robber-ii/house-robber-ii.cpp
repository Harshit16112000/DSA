class Solution {
public:
    int dpProblem(int index, vector<int>& nums, int n, vector<int>& dp)
    {
        if(index > n) return 0;

        
        if(dp[index] != -1)  return dp[index];

        int take = nums[index] + dpProblem(index+2, nums,n,dp);
        int nonTake = dpProblem(index+1, nums, n, dp);

        return dp[index] = max(take, nonTake);
    }
    int rob(vector<int>& nums) {
     vector<int> dp(nums.size() , -1);

     int left = dpProblem(0,nums, nums.size() -2, dp);
     
     vector<int> dp2(nums.size() , -1);
     int right = dpProblem(1,nums, nums.size() -1, dp2);

     if(nums.size() == 1)  return nums[0];
        return max(left, right);
    }
};