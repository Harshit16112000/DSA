class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> maxHeap =
        new PriorityQueue<>(Collections.reverseOrder());

        for(int i=0;i<matrix.length;i++)
        {
            for(int j=0;j<matrix[i].length;j++)
            {
                maxHeap.offer(matrix[i][j]);
                if(maxHeap.size() > k)
                {
                    maxHeap.poll();
                }
                
            }
        }

        return maxHeap.peek();
    }
}