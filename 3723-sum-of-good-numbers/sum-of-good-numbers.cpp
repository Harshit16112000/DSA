class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            int prevIndex = i-k;
            int nextIndex = i+k;
            if(prevIndex >= 0)
            {
                if(nums[prevIndex] >= nums[i]) continue;
            }
            if(nextIndex < nums.size())
            {
                if(nums[nextIndex] >= nums[i]) continue;
            }

            sum += nums[i]; 
        }

        return sum;
    }
};