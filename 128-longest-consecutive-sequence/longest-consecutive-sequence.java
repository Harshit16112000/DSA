class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        Arrays.sort(nums);

        int cnt = 1;
        int maxi = 0;

        for (int i = 1; i < nums.length; i++) {

            // Skip duplicates
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            // Consecutive element
            if (nums[i] - nums[i - 1] == 1) {
                cnt++;
            } 
            // Reset count
            else {
                maxi = Math.max(maxi, cnt);
                cnt = 1;
            }
        }

        return Math.max(maxi, cnt);
    }
}