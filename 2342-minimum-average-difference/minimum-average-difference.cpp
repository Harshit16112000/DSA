class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        vector<long long> rightPSum(n,0);
        rightPSum[n-1] = nums[nums.size() -1];
        
        for(int i=n-2;i>=0;i--)
        {
            rightPSum[i] = rightPSum[i+1] + nums[i];
        }

        long long leftSum = 0;
        int idx = 0;
        for(int i = 0; i<n-1;i++)
        {
            leftSum += nums[i];
            long long leftSumAverage = leftSum/(i+1);

            long long rightSum = rightPSum[i+1];
            long long rightSumAverage = rightSum/(n-i-1);

            long long avg = abs(rightSumAverage - leftSumAverage);
            //cout << avg << " " << mini << endl;
            if( avg < mini)
            {
                mini = avg;
                idx = i;
            }
        }

        // Need to include last element also
         long long avg = (leftSum + nums[nums.size() -1])/(n);
        //cout << avg;
        if(avg < mini)
        {
            idx = n-1;
        }
        return idx;
    }
};