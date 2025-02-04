class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        long long sum = nums[0];
        long long maxi = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1])
            {
                sum += nums[i];
                maxi = max(maxi, sum);
            }
            else {
                sum = nums[i];
            }
        }

        return maxi;
    }
};