class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff = 0;
        for(int i=1;i<nums.size();i++)
        {
            diff = max(diff, abs(nums[i] - nums[i-1]));
        }

        diff = max(diff, abs(nums[nums.size() -1] - nums[0]));
        return diff;
    }
};