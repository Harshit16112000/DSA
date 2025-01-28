class Solution {
public:
    int halveArray(vector<int>& nums) {
        long long  sum = 0;
        priority_queue<double> pq;
        for(auto it: nums)
        {
             sum += it;
             pq.push(it);
        }

        double half_sum = (double)sum/2.0;
        int cnt = 0;
        double rem_sum = 0;
        while(!pq.empty())
        {
            double num = pq.top();
            pq.pop();
            rem_sum += num/2.0;
            cnt++;
            if(rem_sum >= half_sum)  break;
            pq.push(num/2.0);   
        }

        return cnt;
        
    }
};