class Solution {
    public int[] rearrangeArray(int[] nums) {
       int result[] = new int[nums.length];
       int even[] = new int[nums.length/2];
       int odd[] = new int[nums.length/2];
       
       int e = 0;
       int o=0;
       for(int i=0;i<nums.length;i++)
       {
            if(nums[i] > 0) {
               even[e] = nums[i];
               e++;
            }
            else {
                odd[o] = nums[i];
                o++;
            }
       } 

        e=0;
        o=0;
       for(int i=0;i<nums.length;i++)
       {
            if(i%2 == 0) {
                result[i] = even[e];
                e++;
            }  
            else  {
                result[i] = odd[o];
                o++;
            } 
       }
       return result;
    }
}