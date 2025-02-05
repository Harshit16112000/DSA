class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        long long ans = 0;
        while(k!=0 && !pq.empty())
        {
            int top = pq.top();
            pq.pop();
            ans += top;
            pq.push(ceil((double)top/3));
            k--;
        }
        return ans;
    }
};