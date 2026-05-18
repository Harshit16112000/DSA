class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int sum = 0;
        int maxi = 0;

        int l = 0;
        int r = 0;
        for(int i=0;i<k;i++)
        {
            sum += cardPoints[i];
            r++;
        }
        maxi = sum;
        
        l = cardPoints.length-1;
        while(r != 0)
        {
            r--;
            sum += cardPoints[l];
            sum -= cardPoints[r];
            l--;
            
            maxi = Math.max(sum,maxi);
        }
        return maxi;
    }
}