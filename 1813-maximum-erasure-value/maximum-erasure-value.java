class Solution {
    public int maximumUniqueSubarray(int[] nums) {
      int sum = 0;
      int maxi = 0;
     HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
      
      int start = 0;
      int end = 0;

      while(end < nums.length)
      {
          if(map.containsKey(nums[end]))
          {
            maxi = Math.max(maxi, sum);
            
            while(start != map.get(nums[end]))
            {
            
                sum -= nums[start];
                map.remove(nums[start]); 
                start++;   
            }
             sum -= nums[start];
                map.remove(nums[start]);
                start++;
          }
          sum += nums[end];
          map.put(nums[end], end);
          end++;
      }
      maxi = Math.max(maxi, sum);


      return maxi;  
    }
}
