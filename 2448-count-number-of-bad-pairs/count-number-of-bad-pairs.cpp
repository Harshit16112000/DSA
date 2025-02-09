class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long> mpp;

        

        unordered_map<int,int> goodPair;
        for(int i=0;i<nums.size();i++)
        {
            goodPair[nums[i] - i]++;
        }

        long long cntgoodPair = 0;
        for(auto [key,value]: goodPair)
        {
            if(value > 1)   cntgoodPair += ((1LL * value * (value-1))/2);
        }

    
        int n = nums.size()-1;
        long long totalpair = (1LL * n * (n+1))/2;
        
        return totalpair - cntgoodPair;    
    }
};