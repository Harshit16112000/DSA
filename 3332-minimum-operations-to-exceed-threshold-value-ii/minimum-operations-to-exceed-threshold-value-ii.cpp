class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        int ans = 0;

        for (auto it : nums) {
            pq.push(it);
        }

        while (pq.size() >= 2 && pq.top() < k) {
            long long n1 = pq.top();
            pq.pop();
            long long n2 = pq.top();
            pq.pop();

            long long sum1 = n1 * 2LL;
            long long sum = sum1 + n2;
            // cout << sum << " ";
            pq.push(sum);
            ans++;
        }

        return ans;
    }
};