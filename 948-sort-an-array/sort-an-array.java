class Solution {
    public int[] sortArray(int[] nums) {
      PriorityQueue<Integer> pq = new PriorityQueue<>();

      ArrayList<Integer>  result = new ArrayList<>();
      for(int i=0;i<nums.length;i++)
      {
        pq.offer(nums[i]);
      }  

      while(!pq.isEmpty())
      {
          result.add(pq.peek());
          pq.poll();
      }

      return result.stream().mapToInt(Integer::intValue).toArray();
    }
}