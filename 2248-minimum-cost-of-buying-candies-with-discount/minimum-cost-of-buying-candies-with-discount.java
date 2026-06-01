class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int ans = 0;
        int n = cost.length;
        int cnt = 0;
        for(int i=n-1;i>=0;i--)
        {
            cnt++;
            if(cnt%3 != 0) 
             ans += cost[i]; 
        }
        return ans;
    }
}