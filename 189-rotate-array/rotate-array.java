class Solution {
    public void rotate(int[] nums, int k) {
         k = k%nums.length;
        reverseArray(nums,0, nums.length );
       reverseArray(nums, 0,k);
      reverseArray(nums, k, nums.length);
    }

    public void reverseArray(int [] nums, int start, int end)
    {
            end--; 
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        start++;
        end--;
    }
    }
}