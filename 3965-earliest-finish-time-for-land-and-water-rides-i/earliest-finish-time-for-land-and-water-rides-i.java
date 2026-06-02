class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<landStartTime.length;i++)
        {
            int tempans = landStartTime[i] + landDuration[i];     
            for(int j=0;j<waterStartTime.length;j++)
            {
                if(waterStartTime[j] <= tempans)
                {
                    int temp = tempans + waterDuration[j];
                    ans = Math.min(ans, temp);
                }
                else{
                    int temp = waterStartTime[j] + waterDuration[j];
                    ans = Math.min(ans, temp);
                }
                
            }
        }


        for(int i=0;i<waterStartTime.length;i++)
        {
            int tempans = waterStartTime[i] + waterDuration[i];     
            for(int j=0;j<landStartTime .length;j++)
            {
                if(landStartTime [j] <= tempans)
                {
                    int temp = tempans + landDuration[j];
                    ans = Math.min(ans, temp);
                }
                else{
                    int temp = landStartTime[j] + landDuration[j];
                    ans = Math.min(ans, temp);
                }
                
            }
        }

        return ans;   
    }
}