class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        map<int, vector<int>> indices; 
        for (int i = 0; i < n; i++) 
            indices[nums1[i]].push_back(i);

        vector<long long> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        long long sum = 0;

        for (auto& [value, indexList] : indices) {
                for (int index : indexList) {
                    ans[index] = sum;  // Store the sum of top k elements
                }

            for (int index : indexList) {
                minHeap.push(nums2[index]);
                sum += nums2[index];

                if (minHeap.size() > k) {
                    sum -= minHeap.top();
                    minHeap.pop();
                }
            }
        }
        return ans;
    }
};