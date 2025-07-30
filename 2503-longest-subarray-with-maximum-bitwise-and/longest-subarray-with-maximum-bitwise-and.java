class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int maxi = 0;
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            maxi = Math.max(nums[i], maxi);
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i] == maxi)
            {
                cnt++;
                ans = Math.max(ans, cnt);
            }
            else {
                cnt = 0;
            }
        }

        return ans;
    }
}