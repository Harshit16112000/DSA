class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        int cnt = 0;
        int operations = 0;

        for(int i=0;i<n;i++)
        {
            ans[i] = operations;
            cnt += (boxes[i] == '1') ? 1 : 0;
            operations += cnt;
        }

        cnt = 0;
        operations = 0;

        for(int i=n-1;i>=0;i--)
        {
            ans[i] += operations;
            cnt += (boxes[i] == '1') ? 1 : 0;
            operations += cnt;
        }

        return ans;
    }
};