class Solution {
    public void nextPermutation(int[] nums) {
       int ind = -1;

       for(int i=nums.length -1 ;i >0;i--)
       {
            if(nums[i] > nums[i-1])
            {
                ind = i-1;
                break;
            }
       }

       if(ind == -1)  {
           reverseArray(nums, 0, nums.length - 1);
           return; 
       } 

       int greater_element = nums.length - 1;
        while(nums[greater_element] <= nums[ind]) {
            greater_element--;
        }

       int temp = nums[greater_element];
       nums[greater_element] = nums[ind];
       nums[ind] = temp;

       reverseArray(nums, ind+1, nums.length - 1) ;

    }



        public static void reverseArray(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }
}