class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0;
        int r = 0;
        int maxi = 0;
        int sum = 0;
        int temp = k;

        while(r < nums.length)
        {
            if(nums[r] == 0)
            
            temp--;

            while(temp < 0)
            {
                if(nums[l] == 0)
                    temp++;
                l++;
            }
            maxi = Math.max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
}
