class Solution {
    public void sortColors(int[] nums) {
        int low = 0;
        int mid = 0;
        int high = nums.length - 1;

       
        
        while(mid <= high)
        {
            if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 0)
            {
               int tmp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = tmp;

                mid++;
                low++;
            }
            else {
                int tmp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = tmp;
            high--;
            }
        }
    }
}