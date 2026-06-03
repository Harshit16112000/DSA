class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        
        int minimumTimeInLand = Integer.MAX_VALUE;
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<landStartTime.length;i++)
        {
            minimumTimeInLand = Math.min(minimumTimeInLand,landStartTime[i] + landDuration[i]);
        }

        for(int j=0;j<waterStartTime.length;j++)
        {
            int waterTime = Math.max(minimumTimeInLand, waterStartTime[j]);
            ans = Math.min(waterTime + waterDuration[j], ans);
        }


        int minimumTimeInWater = Integer.MAX_VALUE;
        
        for(int i=0;i<waterStartTime.length;i++)
        {
            minimumTimeInWater = Math.min(minimumTimeInWater,waterStartTime[i] + waterDuration[i]);
        }

        for(int j=0;j<landStartTime.length;j++)
        {
            int waterTime = Math.max(minimumTimeInWater, landStartTime[j]);
            ans = Math.min(waterTime + landDuration[j], ans);
        }

        return ans;
    }
}