class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
      // PriorityQueue<Pair<Integer,Integer>> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

       
        PriorityQueue<Pair<Integer, Integer>> maxHeap = new PriorityQueue<>(
            (a, b) -> {
                int diff = Integer.compare(b.getKey(), a.getKey());
                if (diff == 0) return Integer.compare(b.getValue(), a.getValue()); // tie-break: remove larger element
                return diff;
            }
        );

        for(int i=0;i<arr.length;i++)
        {
            
            maxHeap.offer(new Pair<>(Math.abs(arr[i] - x), arr[i]));
            if(maxHeap.size() > k)
            {
                maxHeap.poll();
            }
        }

        List<Integer> ans = new ArrayList<>();;
        while(!maxHeap.isEmpty())
        {
            ans.add(maxHeap.peek().getValue());
            maxHeap.poll();
        }
        Collections.sort(ans); 
        return ans;
    }
}