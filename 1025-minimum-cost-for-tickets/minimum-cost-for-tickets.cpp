class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return solve(days,0, costs, dp);
    }

    int solve(vector<int> days, int idx, vector<int>& cost, vector<int> &dp)
    {
        
        if(idx >= days.size())  return 0;
        if(dp[idx] != -1)  return dp[idx];

        int day1 = cost[0] + solve(days,idx+1, cost, dp); 
        int day7 = cost[1];
        int day30 = cost[2];
        for(int i = idx;i<days.size();i++)
        {
            if( days[i] >= days[idx] + 7)
            {
                day7 += solve(days,i,cost, dp);
                break;   
            }
        }

    
        for(int i = idx;i<days.size();i++)
        {
            if( days[i] >= days[idx] + 30)
            {
                day30 += solve(days,i,cost, dp);
                break;   
            }
        }
        return dp[idx] =   min(day30, min( day7, day1));
        
    }
};