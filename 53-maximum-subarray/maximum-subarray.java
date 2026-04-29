class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int cnt = Integer.MIN_VALUE;

        for(int i=0;i<nums.length;i++)
        {
            sum += nums[i];
            cnt = Math.max(sum,cnt);

            if(sum < 0 )
                sum = 0;
        }

        return cnt;
    }
}