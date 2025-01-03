typedef long long ll;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       ll sum = 0;
        int n=nums.size();
        vector<ll> leftpSum(n,0);
        vector<ll> rightpSum(n,0);
        leftpSum[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            leftpSum[i] = nums[i] + leftpSum[i-1];
        }

        for(int j=n-2;j>=0;j--)
        {
            rightpSum[j] = nums[j+1] + rightpSum[j+1];
        }
        int ans = 0;
        for(int i=0;i<leftpSum.size()-1;i++)
        {
            if(leftpSum[i] >= rightpSum[i] ) ans++;
        }

        return ans; 
    }
};