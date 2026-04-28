class Solution {
    public void rotate(int[] nums, int k) {
        k = k%nums.length;
        reverseArray(0, nums.length-1, nums);
        reverseArray(0,k-1,nums);
        reverseArray(k,nums.length-1,nums);
    }

    void reverseArray(int start, int end, int[] nums) {
        
        while(start < end)
        {
            int ele = nums[start];
            nums[start] = nums[end];
            nums[end] = ele;
            start++;
            end--;
        }
    }
}