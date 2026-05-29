class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double maxi = Double.NEGATIVE_INFINITY;
        int start = 0;
        int end = 0;
        int sum = 0;

        for(int i=0;i<k;i++)
        {
            sum += nums[i];
            end++;
        }
        maxi = Math.max(maxi, (double)sum/k);
        while(end < nums.length)
        {
            sum = sum - nums[start] + nums[end];
            start++;
            end++;
            maxi = Math.max(maxi, (double)sum/k);
        }

        return maxi;
    }
}