class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt = 1;
        int maxi = 1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1])
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else {
                cnt = 1;
            }
        }

        cnt = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[i-1])
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else {
                cnt = 1;
            }
        }

        return maxi;

    }
};