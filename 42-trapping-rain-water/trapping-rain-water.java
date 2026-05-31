class Solution {
    public int trap(int[] height) {
        int maxl[] = new int[height.length];
        int maxr[] = new int[height.length];

        maxl[0] = height[0];
        for(int i=1;i<height.length;i++)
        {
            maxl[i] = Math.max(maxl[i-1], height[i]);
        }

        maxr[height.length - 1] = height[height.length - 1];
        for(int i=height.length -2;i >=0;i--)
        {
            maxr[i] = Math.max(maxr[i+1], height[i]);
        }

        int sum = 0;
        for(int i=0;i<height.length;i++)
        {
            sum += Math.min(maxr[i], maxl[i]) - height[i];
        }
        return sum;
    }
}