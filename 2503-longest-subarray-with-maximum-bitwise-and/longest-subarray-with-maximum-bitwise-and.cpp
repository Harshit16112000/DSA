class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, nums[i]);
        }

        int cnt = 0;
        int maxim = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == maxi)  {
                cnt++;
                maxim = max(cnt,maxim);
            }
            else {
                cnt = 0;
            }
        }

        return maxim;
    }
};